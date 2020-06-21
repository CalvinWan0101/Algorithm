#include <iostream>
#include <algorithm>
using namespace std;
//前i個物品裝入容量為j的背包中獲得的最大價值
int chart[200][200];
int DP(int n, int w[], int v[], int C)
{
	int i, j;
	//j=0表示當背包重量為0時
	for (j = 0; j <= C; j++)
		chart[0][j] = 0;
	//n件物品跑n次
	for (i = 0; i <= n - 1; i++)
		//背包的重量由0~C(上限)
		for (j = 0; j <= C; j++)
			//當物品重量>能使用的容量
			if (j < w[i])
				//只能回推不使用這個物件的最佳解
				chart[i][j] = chart[i - 1][j];
	//容量可以做選擇的時候
			else
				chart[i][j] = max(chart[i - 1][j], chart[i - 1][j - w[i]] + v[i]);
	return chart[n - 1][C];
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
		cout << "第" << i + 1 << "個物品重量：";
		cin >> w[i];
		cout << "第" << i + 1 << "個物品價值：";
		cin >> v[i];
		cout << endl;
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
	cout << "物品最大價值為：" << endl << DP(n, w, v, C) << endl;
}
