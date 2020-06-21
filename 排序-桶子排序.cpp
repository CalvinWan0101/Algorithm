//桶子排序法
//優點：
//運算快速邏輯直觀
//缺點：
//浪費記憶體——EX.僅兩數據【1】【1000】排序便要建立1001個水桶
//無法對應相對的人事物
#include <iostream>
using namespace std;
int main(int argc, char** argv)
{
	//先建立bucket以相對應bucket的編號存取相對應的數字量
	int bucket[1001] = { 0 };
	//數值範圍為0~1000
	int number;
	cout << "資料量：";
	cin >> number;
	//可排序100個數字
	int input[100];
	for (int i = 0; i < number; i++)
		cin >> input[i];
	//所對應的數值的桶子+=1
	for (int i = 0; i < number; i++)
		bucket[input[i]]++;
	//將每個桶子所對應的數字印出該桶子的次數
	for (int i = 0; i < 1001; i++)
		if (bucket[i] != 0)
			for (int j = 1; j <= bucket[i]; j++)
				cout << i << " ";
	system("PAUSE");
	return 0;
}