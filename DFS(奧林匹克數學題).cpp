#include<iostream>
using namespace std;
//口口口+口口口=口口口
//口內為1~9的數字且不重複
//用以記錄已經出現過的數字
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
	//一般狀況
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