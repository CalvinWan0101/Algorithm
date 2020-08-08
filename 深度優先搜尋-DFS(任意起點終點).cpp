#include<iostream>
using namespace std;
int map[101][101], bucket[101][101] = { 0 };
int ty, tx, my, mx, y, x, min = 10000000;
void dfs(int x, int y, int step)
{
	int bufferx, buffery;
	//右上左下
	int way[4][2] = { {0,1},{-1,0},{0,-1},{1,0} };
	if (x == tx && y == ty)
	{
		cout << "step測試：" << step << endl;
		for (int i = 1; i <= my; i++)
			for (int j = 1; j <= mx; j++)
				if (bucket[i][j] != 0)
					cout << "(" << i << "," << j << ")" << endl;
		if (step < min)
			min = step;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		bufferx = x + way[i][1];
		buffery = y + way[i][0];
		//超過範圍的話直接continue
		if (bufferx<1 || buffery<1 || bufferx>mx || buffery>my)
			continue;
		if (map[buffery][bufferx] == 0 && bucket[buffery][bufferx] == 0)
		{
			bucket[buffery][bufferx] = 1;
			dfs(bufferx, buffery, step + 1);
			bucket[buffery][bufferx] = 0;
		}
	}
}
int main()
{
	int a, b;
	cin >> my >> mx;
	for (int i = 1; i <= my; i++)
		for (int j = 1; j <= mx; j++)
			cin >> map[i][j];
	cin >> b >> a >> ty >> tx;
	bucket[b][a] = 1;
	dfs(a, b, 0);
	if (min == 10000000)
		cout << "No Way!" << endl;
	else
		cout << min << endl;
}*/
