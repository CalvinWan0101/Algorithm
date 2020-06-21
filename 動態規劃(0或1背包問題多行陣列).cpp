#include <iostream>
#include <algorithm>
using namespace std;
//�ei�Ӫ��~�ˤJ�e�q��j���I�]����o���̤j����
int chart[200][200];
int KnapSack(int n, int w[], int v[], int C)
{
	int i, j;
	//j=0��ܷ�I�]���q��0��
	for (j = 0; j <= C; j++)
		chart[0][j] = 0;
	//n�󪫫~�]n��
	for (i = 0; i <= n - 1; i++)
		//�I�]�����q��0~C(�W��)
		for (j = 0; j <= C; j++)
			//���~���q>��ϥΪ��e�q
			if (j < w[i])
				//�u��^�����ϥγo�Ӫ��󪺳̨θ�
				chart[i][j] = chart[i - 1][j];
	//�e�q�i�H����ܪ��ɭ�
			else
				chart[i][j] = max(chart[i - 1][j], chart[i - 1][j - w[i]] + v[i]);
	int buffer = -1000;
	for (int k = 0; k <= C; k++)
		if (chart[n - 1][k] > buffer)
			buffer = chart[n - 1][k];
	return buffer;
}
int main()
{
	int w[100];
	int v[100];
	int n, i;
	int C, buffer;
	cout << "�I�]���̤j�e�q�G";
	cin >> C;
	cout << "���~�ơG";;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cout << "��" << i + 1 << "�Ӫ��~���q�G";
		cin >> w[i];
		cout << "��" << i + 1 << "�Ӫ��~���ȡG";
		cin >> v[i];
		cout << endl;
	}
	//�έ��q�ƧǤ@��
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (w[i] > w[j])
			{
				buffer = w[i];
				w[i] = w[j];
				w[j] = buffer;
				buffer = v[i];
				v[i] = v[j];
				v[j] = buffer;
			}
	cout << "���~�̤j���Ȭ��G" << endl << KnapSack(n, w, v, C) << endl;
}