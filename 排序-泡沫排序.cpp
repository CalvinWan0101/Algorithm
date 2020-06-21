//泡沫排序
//優點：
//節約記憶體
//缺點：
//用時多且運算較無效率
#include <iostream>
using namespace std;
int main(int argc, char** argv)
{
	int input[100];
	int number;
	cout << "數據量：";
	cin >> number;
	for (int i = 0; i < number; i++)
		cin >> input[i];
	//由小到大排序
	int buffer;
	for (int i = 0; i < number; i++)
		//注意：倒數第二與最後比較完後不需要再另外比較最後一位
		//所以limit為number-1而非number
		for (int k = 0; k < number - 1; k++)
			if (input[k] > input[k + 1])
			{
				buffer = input[k];
				input[k] = input[k + 1];
				input[k + 1] = buffer;
			}
	//印出排序後的數列
	for (int i = 0; i < number; i++)
		cout << input[i] << " ";
	system("PAUSE");
	return 0;
}