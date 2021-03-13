//写这段代码让我十分沮丧，提交代码提示wrong answer，但我已经找不到代码的问题了，输入过几组数据差错
//找不到错哪里了，网上看别人也有类似的评论，真叫人头大
//请容许我不写注释，以下代码仅提供思想，若想借用代码，还是去搜索吧
#include<iostream>
#include<iomanip>
using namespace std;


int main()
{
	int N, M;
	while (cin >> N >> M)
	{
		if (N == 0 && M == 0)
			break;
		double class_ave[5], student_ave[50] = { 0 }, student_score[50];
		int student_top = 0;
		bool student_flag[50] = { false };
		for (int i = 0; i < M; i++)
		{
			float sum = 0;
			for (int j = 0; j < N; j++)
			{
				cin >> student_score[j];
				sum += student_score[j];
				student_ave[j] += student_score[j];
			}
			class_ave[i] = sum / N;
			for (int k = 0; k < N; k++)
			{
				if ((!student_flag[k]) && (student_score[k] < class_ave[i]))
					student_flag[k] = true;
			}
		}
		for (int i = 0; i < N; i++)
		{
			if (!student_flag[i])
				student_top++;
			student_ave[i] = student_ave[i] / M;
		}

		cout << fixed << setprecision(2) << student_ave[0];
		for (int i = 1; i < N; i++)
			cout << " " << fixed << setprecision(2) << student_ave[i];
		cout << endl;

		cout << fixed << setprecision(2) << class_ave[0];
		for (int i = 1; i < M; i++)
			cout << " " << fixed << setprecision(2) << class_ave[i];
		cout << endl;

		cout << student_top << endl << endl;
	}
	return 0;
}
