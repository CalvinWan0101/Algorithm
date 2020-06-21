#include <iostream>
//快速排序的邏輯：
//取任意項為基準數
//分別從左邊,右邊開始尋找
//當左邊找到第i個比基準值大的數則替換掉右邊找到的第i個比基準值小的數(由小排到大)
//當左邊與右邊找到同一項時則將其與基準數替換
int a[101];
int n;
void quicksort(int left, int right)
{
	//當left>right時直接駁回呼叫
	if (left > right)
		return;
	int temp = a[left];
	int i = left;
	int j = right;
	int buffer;
	while (i != j)
	{
		//順序不能顛倒
		//先由右往左
		while (a[j] >= temp && i < j)
			j--;
		//再由左往右
		while (a[i] <= temp && i < j)
			i++;
		if (i < j)
		{
			buffer = a[i];
			a[i] = a[j];
			a[j] = buffer;
		}
	}
	//交換交匯處與基準數
	a[left] = a[i];
	a[i] = temp;

	//交匯處將原始數列切成兩半
	//兩半各以遞迴數列繼續計算
	quicksort(left, i - 1);
	quicksort(i + 1, right);
}
using namespace std;
int main(int argc, char** argv)
{
	int number;
	cout << "資料量：";
	cin >> number;
	for (int i = 1; i <= number; i++)
		cin >> a[i];
	//召喚快速排序函數！
	quicksort(1, n);
	//輸出已經交換完的數列
	for (int i = 1; i <= number; i++)
		cout << a[i] << " ";
	system("PAUSE");
	return 0;
}