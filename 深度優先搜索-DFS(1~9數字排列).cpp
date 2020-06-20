#include <iostream>
using namespace std;
//存答案
int answer[10];
//存是否使用過
int bucket[10] = { 0 };
void dfs(int step, int end)
{
	//前面已經end個迴圈把答案都丟進answer陣列了
	//在第end+1的時候負責印出來然後再return就好了
	if (step == end + 1)
	{
		for (int i = 1; i <= end; i++)
			cout << answer[i];
		cout << endl;
		return;
	}
	//這邊有end層
	for (int i = 1; i <= end; i++)
		//當i沒有被使用過的時候
		if (bucket[i] == 0)
		{
			//先把i丟進answer[step]進去試試看
			answer[step] = i;
			//這邊要標記說 i 已經使用過了
			bucket[i] = 1;
			//跑進下個迴圈
			dfs(step + 1, end);
			//等到return回來的時候 i 這條路已經嘗試過了
			//所以 i 再改回未使用的狀況讓他去嘗試 i+1 
			bucket[i] = 0;
		}
}
int main()
{
	//n為1~9的數字
	int n;
	while (cin >> n)
		//dfs(step,end)
		//step=1指從第一項開始
		//end=n表示共n項來排
		dfs(1, n);
	return 0;
}
