#include <iostream>
#include <string.h>
#include "5��������class.h"
using namespace std;


int main()
{
	Phonebook phnum;// �Ű����� ���� �����ڸ� ȣ���Ѵ�.
	phnum.addPhone();//�ٷ� �Լ��� �ҷ����δ�. �Ű�����.�Լ��̸�(); 
	while (1)//3 ���� ������ �ݺ�
	{
		int n;//1, 2, 3�Է¹��� ������ �����Ѵ�.
		cout << "1. �ֽ� ��� ��ȭ��ȣ ��ȸ" << endl;
		cout << "2. �ֽ� ��� ��ȭ��ȣ ����" << endl;
		cout << "3. ���� >>";
		cin >> n;

		if (n == 1)
		{
			cout << phnum.getName();//�ش� �Լ����� return �ߴ� ���� ����Ѵ�.
			cout << "::";
			cout << phnum.getPnum();//�׳� return�ϸ� �� ��� ���Ѵ�. �ݵ�� cout ����
			cout << endl;
			continue; //1,,2,3�߿� �ٽ� �� �� �ֵ��� �ݺ��� �ٽ� ����
		}

		if (n == 2) {
			phnum.editPhone();//��ȭ��ȣ�� �����ϴ� �Լ��̴�.
			continue;
		}

		if (n == 3) {
			exit(1);//�ݺ� ������ �ƿ� �����Ѵ�.
		}
	}
}