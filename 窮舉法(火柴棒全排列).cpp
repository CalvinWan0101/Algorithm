#include <iostream>
#include<string>
#include <iomanip>
using namespace std;
int main(int argc, char** argv)
{
	int n;
	cout << "����μƶq�G";
	cin >> n;
	int cost[10] = { 6,2,5,5,4,5,6,3,7,6 };
	//A+B=C
	//0<=A,B<=11111
	int c;
	int sum;
	int w, k, b, s, g;
	int count = 0;
	for (int i = 0; i <= 11111; i++)
		for (int j = 0; j <= 11111; j++)
		{
			sum = 0;
			c = i + j;
			//���ӤQ�ʤd�U��A�A�P�_�O�_��0
			w = i / 10000;
			k = (i % 10000) / 1000;
			b = ((i % 10000) % 1000) / 100;
			s = (((i % 10000) % 1000) % 100) / 10;
			g = (((i % 10000) % 1000) % 100) % 10;
			if (i >= 10000)
				sum += (cost[w] + cost[k] + cost[b] + cost[s] + cost[g]);
			else if (i >= 1000)
				sum += (cost[k] + cost[b] + cost[s] + cost[g]);
			else if (i >= 100)
				sum += (cost[b] + cost[s] + cost[g]);
			else if (i >= 10)
				sum += (cost[s] + cost[g]);
			else
				sum += cost[g];

			w = j / 10000;
			k = (j % 10000) / 1000;
			b = ((j % 10000) % 1000) / 100;
			s = (((j % 10000) % 1000) % 100) / 10;
			g = (((j % 10000) % 1000) % 100) % 10;
			if (j >= 10000)
				sum += (cost[w] + cost[k] + cost[b] + cost[s] + cost[g]);
			else if (j >= 1000)
				sum += (cost[k] + cost[b] + cost[s] + cost[g]);
			else if (j >= 100)
				sum += (cost[b] + cost[s] + cost[g]);
			else if (j >= 10)
				sum += (cost[s] + cost[g]);
			else
				sum += cost[g];

			w = c / 10000;
			k = (c % 10000) / 1000;
			b = ((c % 10000) % 1000) / 100;
			s = (((c % 10000) % 1000) % 100) / 10;
			g = (((c % 10000) % 1000) % 100) % 10;
			if (c >= 10000)
				sum += (cost[w] + cost[k] + cost[b] + cost[s] + cost[g]);
			else if (c >= 1000)
				sum += (cost[k] + cost[b] + cost[s] + cost[g]);
			else if (c >= 100)
				sum += (cost[b] + cost[s] + cost[g]);
			else if (c >= 10)
				sum += (cost[s] + cost[g]);
			else
				sum += cost[g];

			if (sum == (n - 4))
			{
				if (i >= 10)
					cout << i;
				else
					cout << "0" << i;
				cout << " + ";
				if (j >= 10)
					cout << j;
				else
					cout << "0" << j;
				cout << " = ";
				if (c >= 10)
					cout << c << endl;
				else
					cout << "0" << c << endl;
				count++;
			}
		}
	cout << "��" << count << "�رƪk" << endl;
	system("PAUSE");
	return 0;
}