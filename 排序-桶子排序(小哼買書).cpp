//�ؼСG
//�q�p��j�ƧǨåh�����ƪ�
#include <iostream>
using namespace std;
int main(int argc, char** argv)
{
	int n;
	//ISBN(1~1000)
	int ISBN[100];
	cout << "��J�H�ơG";
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> ISBN[i];
	//�ƭȪ��d�򤣤j=�nuse ��l�Ƨǥh������
	int bucket[1001] = { 0 };
	for (int i = 0; i < n; i++)
		bucket[ISBN[i]]++;
	for (int i = 0; i < 1001; i++)
		if (bucket[i] != 0)
			cout << i << " ";
	system("PAUSE");
	return 0;
}