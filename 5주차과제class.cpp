#include <iostream>
#include <string.h>
#include "5��������class.h"
using namespace std;



void Phonebook::addPhone() {//ó���� �� �Ű��Լ��̴�. �̸��� ��ȣ�� �Է¹޴´�.
	cout << "--- swing ��ȭ��ȣ�� ---" << endl;
	cout << "�̸��� �Է��� �ּ���>> ";
	cin >> name;//Ŭ���� ������ �� private �����ߴ� name ����, ����ڿ��Լ� �̸��� �Է¹޴´�.
	cout << "��ȣ�� �Է��� �ּ���>> ";
	cin >> pnum;// Ŭ���� ������ �� private �����ߴ� pnum ����, ����ڿ��Լ� ��ȭ��ȣ�� �Է¹޴´�.
}

void Phonebook::editPhone() {// �̸� �˻��Ͽ� ��ȣ�� �����ϴ� �Լ��̴�.
	string edit;// ������ ��ȣ �Է¹��� ���ڿ� ����
	cout << "�̸��� �Է��� �ּ��� >>";
	cin >> edit;
	while (1) {// �ùٸ� �̸��� �Է��� ������ �ݺ��Ѵ�.
		if (edit != name) {
			cout << "����ó�� �������� �ʽ��ϴ� �ٽ� �Է��� �ּ���>>";
			cin >> edit;
			continue;
		}
		else {//����� �̸��� �����ϰ��� �ϴ� �̸��� ������ ������ ��ȭ��ȣ�� ���� �Է��Ѵ�.
			cout << "������ ��ȭ��ȣ�� �Է��� �ּ��� >>";
			cin >> pnum;//��ȭ��ȣ�� �Է¹޾Ҵ� pnum ������ �ٽ� �Է¹޴´�.
			break;
		}
	}
}

string Phonebook::getPnum() {
	return pnum;// ���������� ����� ��ȣ�� return�ϴ� �Լ��̴�.
}

string Phonebook::getName() {
	return name;// ���������� ����� �̸��� return�ϴ� �Լ��̴�.
}