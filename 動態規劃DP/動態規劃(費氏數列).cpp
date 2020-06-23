#include <iostream>
using namespace std;
int main()
{
	//f(n)
	//n=1 || n=2,f(n)=1
	//else f(n)=f(n-1)+f(n-2)
	int array[10001];
	array[1] = array[2] = 1;
	for (int i = 3; i < 1001; i++)
		array[i] = -1;
	for (int i = 3; i < 1001; i++)
		array[i] = array[i - 1] + array[i - 2];
	int n;
	while (cin >> n)
		cout << array[n] << endl;
	return 0;
}