#include <iostream>
using namespace std;

int main()
{
	int shape;
	cout << "----------�� ��� �ý���------------" << endl;
	cout << "����� ���� ����� �������ּ���." << endl;
	cout << "1.�����ﰢ��" << endl;
	cout << "2.���ﰢ��" << endl;
	cout << "3.����" << endl;
	cout << "4.������" << endl;
	cin >> shape;
	cout << endl << endl;
	
	if (shape == 1)
	{
		int num;
		cout << "�����ﰢ���� �����Ͽ����ϴ�." << endl;
		cout << "���� ������ �������ּ���." << endl;
		cin >> num;
		cout << endl;

		for (int i = 0; i < num; i++)
		{
			for (int j = 0; j < num-i ; j++)
				cout << " ";
			for (int k = 0; k <= i; k++)
				cout << "*";
			cout << endl;
		}

		cout << endl;

		for (int i = 0; i < num; i++)
		{
			for (int j = num; j > i; j--)
				cout << "*";
			cout << endl;
		}

		cout << endl;

		for (int i = 0; i < num; i++)
		{
			for (int j = 0; j < i; j++)
				cout << " ";
			for (int j = num; j > i; j--)
				cout << "*";
			cout << endl;

		}

		cout << endl;


	}

	if (shape == 2)
	{
		int num;
		cout << "���ﰢ���� �����Ͽ����ϴ�." << endl;
		cout << "���� ������ �������ּ���." << endl;
		cin >> num;
		cout << endl;

		for (int i = 0; i < num; i++)
		{
			for (int j = num - 1; j > i; j--)
				cout << " ";
			for (int k = 0; k < (2 * i + 1); k++)
				cout << "*";
			
			cout << endl;
		}

		cout << endl;


	}

	if (shape == 3)
	{
		int num;
		cout << "���� �����Ͽ����ϴ�." << endl;
		do{
			cout << "���� ������ �������ּ���." << endl;
			cin >> num;
		} while (num % 2 == 0);
		
		for (int i = 0; i < (num / 2)+1; i++)
		{
			for (int j = 0; j < i; j++)
				cout << "*";
			for (int k = 0; k < num - (2 * i); k++)
				cout << " ";
			for (int j = 0; j < i; j++)
				cout << "*";
			cout << endl;
		}
		for (int i = 0; i < num; i++)
			cout << "*";
		cout << endl;
		for (int i = 0; i < (num / 2) + 1; i++)
		{
			for (int j = num/2; j >i; j--)
				cout << "*";
			for (int j = 0; j < 2 * i + 1 ; j++)
				cout << " ";
			for (int j = num / 2; j > i; j--)
				cout << "*";
			cout << endl;
		}

	}

	if (shape == 4)
	{
		cout << "�����⸦ �����ϼ̽��ϴ�." << endl;
		cout << "�����մϴ�." << endl;
	}
	cout << endl;
	
}