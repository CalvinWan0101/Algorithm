//目標：
//從小到大排序並去掉重複的
#include <iostream>
using namespace std;
int main(int argc, char** argv)
{
	int n;
	//ISBN(1~1000)
	int ISBN[100];
	cout << "輸入人數：";
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> ISBN[i];
	//數值的範圍不大=》use 桶子排序去掉重複
	int bucket[1001] = { 0 };
	for (int i = 0; i < n; i++)
		bucket[ISBN[i]]++;
	for (int i = 0; i < 1001; i++)
		if (bucket[i] != 0)
			cout << i << " ";
	system("PAUSE");
	return 0;
}