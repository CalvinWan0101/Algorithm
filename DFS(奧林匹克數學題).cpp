#include<iostream>
using namespace std;
//�f�f�f+�f�f�f=�f�f�f
//�f����1~9���Ʀr�B������
//�ΥH�O���w�g�X�{�L���Ʀr
int bucket[10] = { 0 };
int answer[10] = { 0 };
void dfs(int step)
{
	if (step == 10)
	{
		if (answer[1] * 100 + answer[2] * 10 + answer[3] + answer[4] * 100 + answer[5] * 10 + answer[6] == answer[7] * 100 + answer[8] * 10 + answer[9])
			for (int i = 1; i <= 9; i++)
				if (i == 3)
					cout << answer[i] << " + ";
				else if (i == 6)
					cout << answer[i] << " = ";
				else if (i == 9)
					cout << answer[i] << endl;
				else
					cout << answer[i];
		return;
	}
	//�@�몬�p
	for (int i = 1; i <= 9; i++)
	{
		if (bucket[i] == 0)
		{
			answer[step] = i;
			bucket[i] = 1;
			dfs(step + 1);
			bucket[i] = 0;
		}
	}
}
int main(int argc, char** argv)
{
	dfs(1);
	system("PAUSE");
	return 0;
}