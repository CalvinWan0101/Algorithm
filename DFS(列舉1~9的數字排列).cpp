#include <iostream>
using namespace std;
//�s����
int answer[10];
//�s�O�_�ϥιL
int bucket[10] = { 0 };
void dfs(int step, int end)
{
	//�e���w�gend�Ӱj��⵪�׳���ianswer�}�C�F
	//�b��end+1���ɭԭt�d�L�X�ӵM��Areturn�N�n�F
	if (step == end + 1)
	{
		for (int i = 1; i <= end; i++)
			cout << answer[i];
		cout << endl;
		return;
	}
	//�o�䦳end�h
	for (int i = 1; i <= end; i++)
		//��i�S���Q�ϥιL���ɭ�
		if (bucket[i] == 0)
		{
			//����i��ianswer[step]�i�h�ոլ�
			answer[step] = i;
			//�o��n�аO�� i �w�g�ϥιL�F
			bucket[i] = 1;
			//�]�i�U�Ӱj��
			dfs(step + 1, end);
			//����return�^�Ӫ��ɭ� i �o�����w�g���չL�F
			//�ҥH i �A��^���ϥΪ����p���L�h���� i+1 
			bucket[i] = 0;
		}
}
int main()
{
	//n��1~9���Ʀr
	int n;
	while (cin >> n)
		//dfs(step,end)
		//step=1���q�Ĥ@���}�l
		//end=n��ܦ@n���ӱ�
		dfs(1, n);
	return 0;
}