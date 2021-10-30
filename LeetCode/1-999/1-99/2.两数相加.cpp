class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* p = l1;
    int carry = 0;
    while (p->next != nullptr && l2->next != nullptr) {
      p->val += carry + l2->val;
      carry = p->val / 10;
      p->val %= 10;
      p = p->next;
      l2 = l2->next;
    }
    if (l2->next != nullptr) {
      p->next = l2->next;
      l2->next = nullptr;
    }
    p->val += carry + l2->val;
    carry = p->val / 10;
    p->val %= 10;
    while (carry) {
      if (p->next) {
        p = p->next;
        p->val += carry;
        carry = p->val / 10;
        p->val %= 10;
      } else {
        p->next = new ListNode(carry);
        carry = 0;
      }
    }
    return l1;
  }
};
