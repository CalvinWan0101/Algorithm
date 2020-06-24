//9 x 9 ���ƿW,�ֵ̤�17�ӼƦr
//�C�ռƿW���u���@�ӵ���
//��J�榡�G�Ů�H 0 ���
#include <iostream>
using namespace std;
int map[10][9] = { 0 };
int buckety[9][10] = { 0 };
int bucketx[9][10] = { 0 };
int bucketblock[9][10] = { 0 };

void dfs(int y, int x)
{
	//y==9�ɥ������w�g�]�L�F
	if (y == 9)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
				cout << map[i][j] << " ";
			cout << endl;
		}
		cout << endl;
		return;
	}
	//��map����l�Ȫ��ɭԪ����ڶi�U�@�ӨB�J
	if (map[y][x] != 0)
		if (x == 8)
			dfs(y + 1, x - 8);
		else
			dfs(y, x + 1);
	//��map[y][x]���Ů�N�}�l������
	else if (map[y][x] == 0)
		for (int i = 1; i <= 9; i++)
			//�T��bucket����0���ɭ�
			if (buckety[y][i] == 0 && bucketx[x][i] == 0 && bucketblock[(y / 3) * 3 + x / 3][i] == 0)
			{
				//cout << "( " << y << " , " << x << " )" << endl;
				map[y][x] = i;
				buckety[y][i]++;
				bucketx[x][i]++;
				bucketblock[(y / 3) * 3 + x / 3][i]++;
				//��x�w�g�O�̫�@�����ɭ�
				if (x == 8)
					dfs(y + 1, x - 8);
				else
					dfs(y, x + 1);
				buckety[y][i] = 0;
				bucketx[x][i] = 0;
				bucketblock[(y / 3) * 3 + x / 3][i] = 0;
			}
			else if (i == 9 && (buckety[y][i] != 0 || bucketx[x][i] != 0 && bucketblock[(y / 3) * 3 + x / 3][i] != 0))
				return;
}
int main()
{
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			cin >> map[i][j];
	//��l��buckety
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
		{
			buckety[i][map[i][j]]++;
			bucketx[j][map[i][j]]++;
			bucketblock[(i / 3) * 3 + j / 3][map[i][j]]++;
		}
	cout << endl;
	cout << endl;
	cout << "buckety" << endl;
	for (int i = 0; i < 9; i++)
	{
		cout << "y = " << i << " �G ";
		for (int j = 1; j < 10; j++)
			cout << buckety[i][j] << " ";
		cout << endl;
		for (int j = 1; j < 10; j++)
			if (buckety[i][j] != 0)
				cout << j << " ";
		cout << endl;
	}
	cout << "bucketx" << endl;
	for (int i = 0; i < 9; i++)
	{
		cout << "x = " << i << " �G ";
		for (int j = 1; j < 10; j++)
			cout << bucketx[i][j] << " ";
		cout << endl;
		for (int j = 1; j < 10; j++)
			if (bucketx[i][j] != 0)
				cout << j << " ";
		cout << endl;
	}
	cout << "bucketblock" << endl;
	for (int i = 0; i < 9; i++)
	{
		cout << "block = " << i << " �G ";
		for (int j = 1; j < 10; j++)
			cout << bucketblock[i][j] << " ";
		cout << endl;
		for (int j = 1; j < 10; j++)
			if (bucketblock[i][j] != 0)
				cout << j << " ";
		cout << endl;
	}
	cout << endl;
	dfs(0, 0);
	return 0;
}