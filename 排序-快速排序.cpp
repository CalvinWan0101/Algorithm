#include <iostream>
//�ֳt�ƧǪ��޿�G
//�����N������Ǽ�
//���O�q����,�k��}�l�M��
//�������i�Ӥ��ǭȤj���ƫh�������k���쪺��i�Ӥ��ǭȤp����(�Ѥp�ƨ�j)
//����P�k����P�@���ɫh�N��P��Ǽƴ���
int a[101];
int n;
void quicksort(int left, int right)
{
	//��left>right�ɪ�����^�I�s
	if (left > right)
		return;
	int temp = a[left];
	int i = left;
	int j = right;
	int buffer;
	while (i != j)
	{
		//���Ǥ����A��
		//���ѥk����
		while (a[j] >= temp && i < j)
			j--;
		//�A�ѥ����k
		while (a[i] <= temp && i < j)
			i++;
		if (i < j)
		{
			buffer = a[i];
			a[i] = a[j];
			a[j] = buffer;
		}
	}
	//�洫��׳B�P��Ǽ�
	a[left] = a[i];
	a[i] = temp;

	//��׳B�N��l�ƦC������b
	//��b�U�H���j�ƦC�~��p��
	quicksort(left, i - 1);
	quicksort(i + 1, right);
}
using namespace std;
int main(int argc, char** argv)
{
	int number;
	cout << "��ƶq�G";
	cin >> number;
	for (int i = 1; i <= number; i++)
		cin >> a[i];
	//�l��ֳt�ƧǨ�ơI
	quicksort(1, n);
	//��X�w�g�洫�����ƦC
	for (int i = 1; i <= number; i++)
		cout << a[i] << " ";
	system("PAUSE");
	return 0;
}