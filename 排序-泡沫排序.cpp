//�w�j�Ƨ�
//�u�I�G
//�`���O����
//���I�G
//�ήɦh�B�B����L�Ĳv
#include <iostream>
using namespace std;
int main(int argc, char** argv)
{
	int input[100];
	int number;
	cout << "�ƾڶq�G";
	cin >> number;
	for (int i = 0; i < number; i++)
		cin >> input[i];
	//�Ѥp��j�Ƨ�
	int buffer;
	for (int i = 0; i < number; i++)
		//�`�N�G�˼ƲĤG�P�̫������ᤣ�ݭn�A�t�~����̫�@��
		//�ҥHlimit��number-1�ӫDnumber
		for (int k = 0; k < number - 1; k++)
			if (input[k] > input[k + 1])
			{
				buffer = input[k];
				input[k] = input[k + 1];
				input[k + 1] = buffer;
			}
	//�L�X�Ƨǫ᪺�ƦC
	for (int i = 0; i < number; i++)
		cout << input[i] << " ";
	system("PAUSE");
	return 0;
}