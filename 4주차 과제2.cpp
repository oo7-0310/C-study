#include <iostream>
using namespace std;

class Phonebook { //class ����
	string name; //���ڿ��� �Է¹޾ƾ� �ϱ� ������ string
	string pnum;// private ���� (class �ȿ����� �� �Ŷ�)
public:
	void addPhone(); //Ư�� ���� return �ϴ� �� �ƴ϶� ������ ����-> void
	void editPhone();// main���� �� �Ŷ� public
	string getPnum();//���ڿ��� return�� ����->string
	string getName();
};

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
			cout <<phnum.getName();//�ش� �Լ����� return �ߴ� ���� ����Ѵ�.
			cout << "::";
			cout <<phnum.getPnum();//�׳� return�ϸ� �� ��� ���Ѵ�. �ݵ�� cout ����
			cout << endl;
			continue; //1,,2,3�߿� �ٽ� �� �� �ֵ��� �ݺ��� �ٽ� ����
		}

		if (n == 2) {
			phnum.editPhone();//��ȭ��ȣ�� �����ϴ� �Լ��̴�.
			continue;
		}

		if(n == 3) {
			exit(1);//�ݺ� ������ �ƿ� �����Ѵ�.
		}
	}
}