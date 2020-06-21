//給地圖
//求哪個點可以一次擊殺最多怪物
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
	//搜尋開始
	int count;
	int max = 0;
	int x = 0, y = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			count = 0;
			if (input[i][j] == '.')
			{
				//往上搜尋
				for (int a = i; a >= 0; a--)
				{
					if (input[a][j] == '#')
						break;
					else if (input[a][j] == 'G')
						count++;
				}
				//cout << "向上搜尋完" << count << endl;
				//往下搜尋
				for (int b = i; b < n; b++)
				{
					if (input[b][j] == '#')
						break;
					else if (input[b][j] == 'G')
						count++;
				}
				//cout << "向下搜尋完" << count << endl;
				//往左搜尋
				for (int c = j; c >= 0; c--)
				{
					if (input[i][c] == '#')
						break;
					else if (input[i][c] == 'G')
						count++;
				}
				//cout << "向左搜尋完" << count << endl;
				//往右搜尋
				for (int d = j; d < m; d++)
				{
					if (input[i][d] == '#')
						break;
					else if (input[i][d] == 'G')
						count++;
				}
				//cout << "向右搜尋完" << count << endl;
				if (count >= max)
				{
					x = j;
					y = i;
					max = count;
				}
			}
		}
	cout << "(" << y<< "," << x << ")" << "有最大擊殺數" << max << endl;
	system("PAUSE");
	return 0;
}