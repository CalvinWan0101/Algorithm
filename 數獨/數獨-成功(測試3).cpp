#include <iostream>
#include <algorithm>
using namespace std;
int map[9][9];
bool Test(int count)
{
	int y = count / 9;
	int x = count % 9;
	int j;
	//�P�@��
	for (j = 0; j < 9; ++j)
		if (map[y][j] == map[y][x] && j != x)
			return false;
	//�P�@�C
	for (j = 0; j < 9; ++j)
		if (map[j][x] == map[y][x] && j != y)
			return false;
	//�P�@�p��
	int sy = y / 3 * 3;
	int sx = x / 3 * 3;
	for (j = sy; j < sy + 3; ++j)
		for (int k = sx; k < sx + 3; ++k)
			if (map[j][k] == map[y][x] && j != y && k != x)
				return false;
	return true;
}
void backtrace(int count)
{
	if (count == 81)
	{
		for (int i = 0; i < 9; ++i)
		{
			for (int j = 0; j < 9; ++j)
				cout << map[i][j] << " ";
			cout << endl;
		}
		return;
	}
	int y = count / 9;
	int x = count % 9;
	if (map[y][x] == 0)
	{
		for (int i = 1; i <= 9; ++i)
		{
			//���ȼаO�w�g�ϥιL
			map[y][x] = i;
			if (Test(count))
				backtrace(count + 1);
		}
		//���m���I�ƭ�
		map[y][x] = 0;
	}
	else
		backtrace(count + 1);
}
int main()
{
	for (int i = 0; i < 9; ++i)
		for (int j = 0; j < 9; ++j)
			cin >> map[i][j];
	backtrace(0);
	return 0;
}