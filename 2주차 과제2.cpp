#include <iostream>
using namespace std;

int main()
{
	while (1) {
		int shape;
		cout << "----------�� ��� �ý���------------" << endl;
		cout << "����� ���� ����� �������ּ���." << endl;
		cout << "1.�����ﰢ��" << endl;
		cout << "2.���ﰢ��" << endl;
		cout << "3.����" << endl;
		cout << "4.������" << endl;
		cin >> shape; //1~4�� ��ȣ �ޱ�
		cout << endl << endl;

		if (shape == 1)//�����ﰢ���� ���� ���
		{
			int num;
			cout << "�����ﰢ���� �����Ͽ����ϴ�." << endl;
			cout << "���� ������ �������ּ���." << endl;
			cin >> num;
			cout << endl;

			for (int i = 0; i < num; i++)//���� ������ŭ �ݺ�
			{
				for (int j = 0; j < num - i; j++)//i�� �ϳ��� �þ�Ƿ� j�� �ϳ��� �پ���.
					cout << " ";
				for (int k = 0; k <= i; k++)//i�� �þ�� ���� ��ĭ ���� ���� �ϳ��� �þ��.
					cout << "*";
				cout << endl;
			}

			cout << endl;

			for (int i = 0; i < num; i++)
			{
				for (int j = num; j > i; j--)//--�� ����
					cout << "*";
				cout << endl;
			}

			cout << endl;

			for (int i = 0; i < num; i++)
			{
				for (int j = 0; j < i; j++)//��ĭ 0���� �����ؼ� num������ ���������.
					cout << " ";
				for (int j = num; j > i; j--)//num������1������ �ϳ��� ����
					cout << "*";
				cout << endl;

			}

			cout << endl;

			continue;
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
				for (int j = num - 1; j > i; j--)//�� �տ� �ϳ��� �پ��� ��ĭ
					cout << " ";
				for (int k = 0; k < (2 * i + 1); k++)//���� ������ 2���� �þ��.
					cout << "*";

				cout << endl;
			}

			cout << endl;
			continue;

		}

		if (shape == 3)
		{
			int num;
			cout << "���� �����Ͽ����ϴ�." << endl;
			do {
				cout << "���� ������ �������ּ���." << endl;
				cin >> num;
			} while (num % 2 == 0);//¦���̸� �ٽ� �ݺ�
			//3��� �Ѵ�.
			for (int i = 0; i < (num / 2) + 1; i++)//�� num���� �Ǳ� ������
			{
				for (int j = 0; j < i; j++)//���� �ϳ��� �þ��.
					cout << "*";
				for (int k = 0; k < num - (2 * i); k++)//��ĭ�� 2���� �پ���.
					cout << " ";
				for (int j = 0; j < i; j++)//���� �ϳ��� �þ��.
					cout << "*";
				cout << endl;
			}
			for (int i = 0; i < num; i++)//�� num����ŭ ����ϰ� �����ٷ� �Ѿ��.
				cout << "*";
			cout << endl;
			for (int i = 0; i < (num / 2) + 1; i++)
			{
				for (int j = num / 2; j > i; j--)//num/2������ �ϳ��� �پ���.
					cout << "*";
				for (int j = 0; j < 2 * i + 1; j++)//1������ 2���� �þ��.
					cout << " ";
				for (int j = num / 2; j > i; j--)
					cout << "*";
				cout << endl;
			}
			continue;
		}

		if (shape == 4)//������ �ȳ��� ���
		{
			cout << "�����⸦ �����ϼ̽��ϴ�." << endl;
			cout << "�����մϴ�." << endl;
			break;
		}
		cout << endl;
	}
}