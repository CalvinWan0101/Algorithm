#include <iostream>
#include<algorithm>
using namespace std;
int map[9][9] = { 0 };
//�˴����
//�p�G�ŦX�зǫhreturn true
//���ŦX�зǴNreturn false
bool test(int count)
{
	int y = count / 9;
	int x = count % 9;
	//y�ۦP��,�u�n���H�M�L�ۦP�Nreturn false
	for (int i = 0; i < 9; i++)
		if (map[y][i] == map[y][x] && i != x)
			return false;
	//x�ۦP�ɡA�u�n���H�M�L�ۦP�Nreturn false
	for (int i = 0; i < 9; i++)
		if (map[i][x] == map[y][x] && i != y)
			return false;
	//�p��_�I
	int sx, sy;
	sx = (x / 3) * 3;
	sy = (y / 3) * 3;
	for (int i = sy; i < sy + 3; ++i)
		for (int j = sx; j < sx; ++j)
			//�p��l�̭����Ҧ��Ʀr
			if (map[y][x] == map[i][j] && y != i && x != j)
				return false;
	return true;
}
//�`���u���j��
void dfs(int count)
{
	//count=81�����I
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
	//�Ů�l
	if (map[y][x] == 0)
		for (int i = 0; i < 9; i++)
		{
			//���N�ƭȥ�imap�̭�
			map[y][x] = i;
			//�p�G���󤹳\�N�i�J�U�@�h
			if (test(count))
				dfs(count + 1);
			//���ŦX���ܦ^�k��l�]�w
			else
				map[y][x] = 0;
		}
	//�o�@�榳�F��N��������p�ƾ�+1�U�@�h
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