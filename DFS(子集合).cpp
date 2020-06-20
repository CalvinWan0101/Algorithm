#include <iostream>
using namespace std;
int answer[16];
int bucket[16] = { 1 };
//n這邊是變數的範圍
void dfs(int step, int end, int n)
{
	if (step == end + 1)
	{
		cout << "{";
		for (int i = 1; i <= end; i++)
			if (i == end)
				cout << answer[i];
			else
				cout << answer[i] << ",";
		cout << "}" << endl;;
		return;
	}
	for (int i = 1; i <= n; i++)
		if (bucket[i] == 1)
		{
			if (step != 1 && i < answer[step - 1])
				continue;
			answer[step] = i;
			bucket[i] = 0;
			dfs(step + 1, end, n);
			bucket[i] = 1;
		}
}
int main()
{
	int a;
	int n;
	cin >> a;
	for (int i = 0; i < a; i++)
	{
		cin >> n;
		cout << "{0}" << endl;
		for (int i = 1; i <= n; i++)
		{
			for (int i = 0; i <= 15; i++)
			{
				bucket[i] = 1;
				answer[i] = 0;
			}
			dfs(1, i, n);
		}
	}
	return 0;
}