//��l�ƧǪk
//�u�I�G
//�B��ֳt�޿誽�[
//���I�G
//���O�O����X�XEX.�Ȩ�ƾڡi1�j�i1000�j�ƧǫK�n�إ�1001�Ӥ���
//�L�k�����۹諸�H�ƪ�
#include <iostream>
using namespace std;
int main(int argc, char** argv)
{
	//���إ�bucket�H�۹���bucket���s���s���۹������Ʀr�q
	int bucket[1001] = { 0 };
	//�ƭȽd��0~1000
	int number;
	cout << "��ƶq�G";
	cin >> number;
	//�i�Ƨ�100�ӼƦr
	int input[100];
	for (int i = 0; i < number; i++)
		cin >> input[i];
	//�ҹ������ƭȪ���l+=1
	for (int i = 0; i < number; i++)
		bucket[input[i]]++;
	//�N�C�ӱ�l�ҹ������Ʀr�L�X�ӱ�l������
	for (int i = 0; i < 1001; i++)
		if (bucket[i] != 0)
			for (int j = 1; j <= bucket[i]; j++)
				cout << i << " ";
	system("PAUSE");
	return 0;
}