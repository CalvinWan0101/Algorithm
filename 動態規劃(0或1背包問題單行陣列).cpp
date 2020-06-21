#include <iostream>
#include <algorithm>
using namespace std;
int cha[200] = { 0 };
int DP(int n, int w[], int v[], int C)
{
	//chartone[i]i璉甧秖
	//倒
	for (int i = 0; i <= C; i++)
		cha[i] = 0;
	//计沮
	for (int q = 0; q < n; q++)
		//璉甧秖
		for (int p = C; p >= 0; p--)
			if (p < w[q])
				continue;
			else
				cha[p] = max(cha[p], cha[p - w[q]] + v[q]);
	int buffer = -10000;
	for (int i = 0; i <= C; i++)
		if (cha[i] > buffer)
			buffer = cha[i];
	return buffer;
}
int main()
{
	int w[100];
	int v[100];
	int n, i;
	int C, buffer;
	cout << "璉程甧秖";
	cin >> C;
	cout << "珇计";;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cout << endl;
		cout << "材" << i + 1 << "珇秖";
		cin >> w[i];
		cout << "材" << i + 1 << "珇基";
		cin >> v[i];
	}
	//ノ秖逼Ω
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
	cout << "珇程基" << DP(n, w, v, C) << endl;
}