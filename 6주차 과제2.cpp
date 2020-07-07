#include <iostream>
using namespace std;

class PhoneBook {
	string name; //�̸�
	string number;//��ȭ��ȣ
public:
	PhoneBook();//������
	void setPnum(string number);//��ȭ��ȣ ����
	void setName(string name);//�̸� ����
	void addPhone(string name, string number);//�̸��� ��ȭ��ȣ ����
	string getPnum();//��ȭ��ȣ ��������
	string getName();//�̸� ��������

};

PhoneBook::PhoneBook() {//������
};

void PhoneBook::setPnum(string number) {//��ȭ��ȣ ����
	this->number = number;//�Ű� ������ ������� number�� ��ü�� �ִ� ��� ���� number�� ����Ѵ�.
}

void PhoneBook::setName(string name) {//�̸� ����
	this->name = name;//�Ű� ������ ������� name�� ��ü�� �ִ� ��� ���� name���� ����Ѵ�.
}

void PhoneBook::addPhone(string name, string number) {//�̸��� ��ȭ��ȣ ����
	this->name = name;
	this->number = number;
}

string PhoneBook::getPnum() {//��ȣ ��ȯ
	return number;
}

string PhoneBook::getName() {//�̸� ��ȯ
	return name;
}

class PhoneBookmenu {
private:
	PhoneBook* phnum;// PhoneBookmenu�� Ŭ���� �Լ����� PhoneBook�� ���� ������ �� ����.
	int i;//�ݺ��п��� ���, i��° ������� ���
	int num;//������ ��ȭ��ȣ�� ��
	int check = 9999;
	string SearchName;//��ȣ �˻��� �̸�
	string name;//i��° ����� �̸�
	string number;//i��° ����� ��ȣ
	string newName;//�߰��� (i+1)��° ����� �̸�
	string newNumber;//�߰��� (i+1)��° ����� ��ȣ
	string editName;//������ ����� �̸�
	string editNumber;//������ ����� ��ȣ

public:
	PhoneBookmenu();//������
	void savePB();//num ���� �̸�, ��ȭ��ȣ ����
	void showPB();//��ȭ��ȣ�� ����
	void searchPB();//��ȭ��ȣ �˻�
	void addPB();//��ȭ��ȣ �߰��ϱ�
	void editPB();//��ȭ��ȣ �����ϱ�
	void close();//��ȭ��ȣ�� �����ϱ�
};

PhoneBookmenu::PhoneBookmenu() {
	
};

void PhoneBookmenu::savePB() {
	cout << "--- swing ��ȭ��ȣ�� ---" << endl;
	cout << "������ ��ȭ��ȣ�� ���� �Է����ּ��� >> ";
	cin >> num;//��� ������ ���� �Է�
	cout << endl;
	phnum = new PhoneBook[num];//�Է� ���� ��ŭ ��ü �迭 ���� ����
	
	for (i = 0; i < num; i++) {
		cout << i + 1 << "��° ����� �̸��� �Է����ּ��� >> ";
		cin >> name;//�Ű������� Ȱ��
		cout << i + 1 << "��° ����� ��ȭ��ȣ�� �Է����ּ��� >> ";
		cin >> number;
		phnum[i].setName(name);
		phnum[i].setPnum(number);//num ���� �̸�, ��ȣ ����
		cout << endl;
	}

}
void PhoneBookmenu::showPB() {
	for (i = 0; i < num; i++) {
		cout << i + 1 << ".";
		cout << phnum[i].getName();
		cout << "::";
		cout << phnum[i].getPnum() << endl;//num ���� �̸�, ��ȣ ����
	}
	cout << endl << endl;
};
void PhoneBookmenu::searchPB() {
	cout << "������ ��ȣ�� �˻��ϰڽ��ϱ�? >> ";
	cin >> SearchName;
	for (i = 0; i < num; i++) {
		if (SearchName == phnum[i].getName()) {
			check = i;
		}
	}
	if (check < num) {
		cout << SearchName << "���� ��ȭ��ȣ : " << phnum[check].getPnum() << endl;
	}
	else
		cout << "����ó�� �������� �ʽ��ϴ�." << endl;
	check = 9999;// �ؿ��� �ݺ��� �����Ŵϱ� �ʱⰪ�� 9999�� �ʱ�ȭ
	cout << endl << endl;
};
void PhoneBookmenu::addPB() {
	cout << "�̸��� �Է����ּ��� >> ";
	cin >> newName;
	cout << "��ȭ��ȣ�� �Է����ּ��� >> ";
	cin >> newNumber;
	//new/delete�� ���Ҵ� �Ұ���,  malloc/free�� realloc���� ũ�� ���� ����
	PhoneBook* tmp = new PhoneBook[num + 1];
	memcpy(tmp, phnum, num * sizeof(PhoneBook));
	//memcpy �޸� ����, ���ʷ�(�����Ͱ� ����� ���� �ּ�, ������ �����͵��� ��ġ�� �ּ�, ������ �������� byte ��)
	num = num + 1;//�迭 ũ�⸦ �ϳ� �ø���.
	delete[] phnum;//������ �Ҵ���� ���� �����ϰ�
	phnum = tmp; //������ �ξ��� �� �ٽ� �޾ƿ���

	phnum[num - 1].addPhone(newName, newNumber); //�迭�� ������ �ڸ��� ��ȭ��ȣ �߰�
	cout << "��ȭ��ȣ�� �߰��Ǿ����ϴ�." << endl;
	cout << endl << endl;
};
void PhoneBookmenu::editPB() {
	cout << "������ ��ȣ�� �����Ͻðڽ��ϱ�? >> ";
	cin >> editName;
	for (i = 0; i < num; i++) {
		if (editName == phnum[i].getName()) {
			check = i;//������ �̸��� ��ġ�ϴ� �̸��� �����ִ� �迭�� �ε������� check�� ���Ƿ� ����
		}
	}
	if (check < num)
	{
		cout << "������ ��ȣ�� �Է����ּ��� >> ";
		cin >> editNumber;
		phnum[check].setPnum(editNumber);//�Ʊ� ��ġ�ߴ� ���� ��ȣ�� �ٽ� �Է��Ͽ� �ִ´�.
		cout << "��ȭ��ȣ�� ����Ǿ����ϴ�." << endl;
	}
	else
		cout << "����ó�� �������� �ʽ��ϴ�.";

	check = 9999;//�ε����� ������� �ǵ��� ����(�ݺ� �ؾ��ϴϱ�)
	cout << endl << endl;
};
void PhoneBookmenu::close() {
	cout << endl << "���α׷��� �����մϴ�.";
	cout << endl << endl;
};

int main()
{

	PhoneBookmenu menu; //PhoneBookmenu Ŭ������ menu��� �̸����� ���ڴ�.

	menu.savePB();

	while (1)
	{
		int n;
		cout << "--- swing ��ȭ��ȣ�� ---" << endl;
		cout << "1. ��ȭ��ȣ�� ����" << endl;
		cout << "2. ��ȭ��ȣ �˻�" << endl;
		cout << "3. ��ȭ��ȣ �߰��ϱ�" << endl;
		cout << "4. ��ȭ��ȣ �����ϱ�" << endl;
		cout << "5. ����" << endl;
		cout << "��ȣ�� �Է����ּ��� >> ";
		cin >> n;
		cout << endl << endl;

		if (n == 1)
		{
			menu.showPB();
			continue;//�ٽ� �ݺ�
		}

		if (n == 2) {

			menu.searchPB();
			continue;
		}

		if (n == 3) {
			menu.addPB();
			continue;
		}

		if (n == 4) {

			menu.editPB();
			continue;
		}
		if (n == 5) {
			menu.close();
			exit(1); //����!
		}
		else {
			cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
			continue;//��ȣ �ٽ� �Է¹ޱ� ����
		}

	}
}