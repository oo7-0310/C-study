#include <iostream>
using namespace std;//cout,cin ���� ����

int main()
{
	int list[5];//���ڸ� 5�� �Է¹޴´�
	int count1=0;//Ȧ�� ����
	int count2=0;//¦�� ����
	

	for (int i = 0; i < 5; i++)
	{
		cout << "���ڸ� �Է����ּ���:";
		cin >> list[i];//�迭�� �޾��ش�
	}
	cout << endl;
	cout << "-----------���------------" << endl;


	cout << "Ȧ��: ";
	for (int i = 0; i < 5; i++)//5�� �ݺ�
	{
		if (list[i] % 2 == 1)//�������� 1, �� Ȧ���� ���
		{
			cout << list[i] << " ";//�ٷ� ���
			count1++;//�ݺ����� ���� Ȧ���� ��쿡 �ϳ��� �����Ѵ�
		}
	}
	cout << endl;
	cout << "Ȧ���� �� " << count1 << "�� �Դϴ�." << endl;
	cout << endl << endl;

	cout << "¦��: ";
	for (int i = 0; i < 5; i++)//�ټ��� �ݺ�
	{
		if (list[i] % 2 != 1)//�������� 1�� �ƴ� ��� ��, ¦��
		{
			cout << list[i] << " ";//�ٷ� ���
			count2++;//¦�� ���� �ϳ��� ����
		}
	}
	cout << endl;
	cout << "¦���� �� " << count2 << "�� �Դϴ�." << endl;
	cout << endl;



}