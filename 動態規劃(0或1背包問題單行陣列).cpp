#include <iostream>
#include <algorithm>
using namespace std;
int cha[200];
int DP(int n, int w[], int v[], int C)
{
	//chartone[i]的i為背包的容量上限
	cha[0] = 0;
	//先給一下初值
	for (int k = 1; k < C; k++)
		if (k >= w[0])
			cha[k] = v[0];
		else
			cha[k] = 0;
	//數據
	for (int q = 1; q < n; q++)
		//背包容量
		for (int p = C; p >= 0; p--)
			if (p < w[q])
				continue;
			else
				cha[p] = max(cha[p], cha[p - w[q]] + v[q]);
	return cha[C];
}
int main()
{
	int w[100];
	int v[100];
	int n, i;
	int C, buffer;
	cout << "背包的最大容量：";
	cin >> C;
	cout << "物品數：";;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cout << endl;
		cout << "第" << i + 1 << "個物品重量：";
		cin >> w[i];
		cout << "第" << i + 1 << "個物品價值：";
		cin >> v[i];
	}
	//用重量排序一次
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (w[i] > w[j])
			{
				buffer = w[i];
				w[i] = w[j];
				w[j] = buffer;
				buffer = v[i];
				v[i] = v[j];
				v[j] = buffer;
			}
	cout << "物品最大價值為：" << DP(n, w, v, C) << endl;
}
