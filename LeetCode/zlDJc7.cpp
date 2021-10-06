struct step {
  unsigned n;
  int iter;
};

class Solution {
 private:
  bool visited[10][10][10][10];
  queue<step> q;

 public:
  Solution() {
    memset(visited, 0, sizeof(bool) * 10000);
    visited[0][0][0][0] = true;
  }
  int openLock(vector<string> &deadends, string target) {
    int tg = 0;
    for (char i = 3; i >= 0; --i) {
      tg |= (target[i] - '0') << ((3 - i) << 3);
    }
    for (auto value : deadends) {
      if (value == "0000") {
	return -1;
      }
      const char *arr = value.c_str();
      visited[arr[3] - '0'][arr[2] - '0'][arr[1] - '0'][arr[0] - '0'] = true;
    }
    if (tg == 0) {
      return 0;
    }
    q.push({0, 0});

    unsigned next = 0;
    char *nc = (char *)(void *)&next;

    while (!q.empty()) {
      step now = q.front();
      q.pop();

      ++now.iter;
      for (char i = 0; i < 4; ++i) {
	next = now.n;
	nc[i] = nc[i] == 9 ? 0 : nc[i] + 1;
	if (!visited[nc[0]][nc[1]][nc[2]][nc[3]]) {
	  if (tg == next) {
	    return now.iter;
	  }
	  q.push(step{next, now.iter});
	  visited[nc[0]][nc[1]][nc[2]][nc[3]] = true;
	}
      }

      for (char i = 0; i < 4; ++i) {
	next = now.n;
	nc[i] = nc[i] == 0 ? 9 : nc[i] - 1;
	if (!visited[nc[0]][nc[1]][nc[2]][nc[3]]) {
	  if (tg == next) {
	    return now.iter;
	  }
	  q.push(step{next, now.iter});
	  visited[nc[0]][nc[1]][nc[2]][nc[3]] = true;
	}
      }
    }
    return -1;
  }
};
