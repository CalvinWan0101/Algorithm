#include <iostream>
using namespace std;
int main(int argc, char** argv)
{
	int limit;
	cout << "請輸入數據量" << endl;
	cin >> limit;
	int array[100];
	//輸入整數字串
	cout << "請輸入整數陣列元素" << endl;
	for (int i = 0; i < limit; i++)
	{
		cin >> array[i];
		cout << "第" << i << "個元素輸入完畢" << endl;
	}
	//best為最大解
	int sum = 0;
	int best = 0;
	for (int j = 0; j < limit; j++)
	{
		sum = array[j];
		for (int k = j + 1; k < limit; k++)
		{
			sum += array[k];
			if (sum > best)
				best = sum;
		}
	}
	cout << best << endl;
	system("PAUSE");
	return 0;
}