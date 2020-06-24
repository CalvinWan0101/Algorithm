#include <iostream>
#include<algorithm>
using namespace std;
int map[9][9] = { 0 };
//檢測函數
//如果符合標準則return true
//不符合標準就return false
bool test(int count)
{
	int y = count / 9;
	int x = count % 9;
	//y相同時,只要有人和他相同就return false
	for (int i = 0; i < 9; i++)
		if (map[y][i] == map[y][x] && i != x)
			return false;
	//x相同時，只要有人和他相同就return false
	for (int i = 0; i < 9; i++)
		if (map[i][x] == map[y][x] && i != y)
			return false;
	//小圈起點
	int sx, sy;
	sx = (x / 3) * 3;
	sy = (y / 3) * 3;
	for (int i = sy; i < sy + 3; ++i)
		for (int j = sx; j < sx; ++j)
			//小圈子裡面的所有數字
			if (map[y][x] == map[i][j] && y != i && x != j)
				return false;
	return true;
}
//深度優先搜索
void dfs(int count)
{
	//count=81為終點
	if (count == 81)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
				cout << map[i][j] << " ";
			cout << endl;
		}
		return;
	}
	int y = count / 9;
	int x = count % 9;
	//空格子
	if (map[y][x] == 0)
		for (int i = 0; i < 9; i++)
		{
			//先將數值丟進map裡面
			map[y][x] = i;
			//如果條件允許就進入下一層
			if (test(count))
				dfs(count + 1);
			//不符合的話回歸原始設定
			else
				map[y][x] = 0;
		}
	//這一格有東西就直接空轉計數器+1下一層
	else
		dfs(count + 1);
}
int main()
{
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			cin >> map[i][j];
	dfs(0);
	return 0;
}