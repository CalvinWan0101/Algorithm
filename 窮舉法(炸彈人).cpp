//���a��
//�D�����I�i�H�@�������̦h�Ǫ�
#include <iostream>
#include <iomanip>
using namespace std;
int main(int argc, char** argv)
{
	int n, m;
	cin >> n >> m;
	char input[50][50];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> input[i][j];
	//�j�M�}�l
	int count;
	int max = 0;
	int x = 0, y = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			count = 0;
			if (input[i][j] == '.')
			{
				//���W�j�M
				for (int a = i; a >= 0; a--)
				{
					if (input[a][j] == '#')
						break;
					else if (input[a][j] == 'G')
						count++;
				}
				//cout << "�V�W�j�M��" << count << endl;
				//���U�j�M
				for (int b = i; b < n; b++)
				{
					if (input[b][j] == '#')
						break;
					else if (input[b][j] == 'G')
						count++;
				}
				//cout << "�V�U�j�M��" << count << endl;
				//�����j�M
				for (int c = j; c >= 0; c--)
				{
					if (input[i][c] == '#')
						break;
					else if (input[i][c] == 'G')
						count++;
				}
				//cout << "�V���j�M��" << count << endl;
				//���k�j�M
				for (int d = j; d < m; d++)
				{
					if (input[i][d] == '#')
						break;
					else if (input[i][d] == 'G')
						count++;
				}
				//cout << "�V�k�j�M��" << count << endl;
				if (count >= max)
				{
					x = j;
					y = i;
					max = count;
				}
			}
		}
	cout << "(" << y<< "," << x << ")" << "���̤j������" << max << endl;
	system("PAUSE");
	return 0;
}