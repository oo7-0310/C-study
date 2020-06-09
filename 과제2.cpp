#include <iostream>
#include <string>
using namespace std;

class VendingMachine {
private:
	string name; //���� �̸�
	int price;//����
	int total;//���� �ջ� ��

public:
	VendingMachine() {};//������
	void purchase(double v1); //�� �ݾ� ���, ���� �Է�, �Ž����� ���
	void menu(); //�޴���
	void menu2(); //�� �޴��� (�Է� ���� ��)
	string getName(); // name ��ȯ
	double getPrice();// price��ȯ
	double getTotal();//�� �հ� ��ȯ
	void setName(string n); //���� �̸� ����
	void setPrice(int p);// ���� ���� ����
	void setTotal(int t);// �ݾ� ��� �����ִ� ��
};

void VendingMachine::purchase(double v1) {
	int money;// ���� �� ��
	int change; // �Ž��� ��
	
	cout << "�ѱݾ� : " << v1 << endl;
	cout << "���� �Է��ϼ��� : ";
	cin >> money;
	cout << endl;
	while (1) {
		
		if (v1 > money) {
			cout << "�ݾ��� �����մϴ�. �ٽ� �־��ּ���.";
			cin >> money;
			continue;//�����ϸ� �ٽ� �� �־�� �ϴϱ� �ݺ�
		}
		if (v1 < money) {
			change = money - v1;
			if (money % 100 != 0) //1, 10��¥�� �ȉ�.
			{
				cout << "�Ž������� 500���� 100���� �����մϴ�.";
				cout << "500�� : " << change / 500 << "��" << endl;
				cout << "100�� : " << change % 500 / 100 << "��" << endl;
				break;// ��� �������Ƿ� break; �ݺ��� Ż���ϱ�
			}
			else {
				cout << "�Ž����� �Դϴ�." << endl;
				cout << "500�� : " << change / 500 << "��" << endl;
				cout << "100�� : " << change % 500 / 100 << "��" << endl;
				break;
			}
		}
		if (v1 == money) {
			cout << "�Ž������� �����ϴ�. �ȳ��� ������" << endl;
			break;
		}
	}
}

void VendingMachine::menu() {
	cout << "===== SWING ���Ǳ� =====" << endl;
	cout << "1. ��ī�ݶ� : 1500��" << endl;
	cout << "2. ��Ÿ500 : 900��" << endl;
	cout << "3. �Ŀ����̵� : 2000��" << endl;
	cout << "4. �غ���" << endl;
	cout << "5. ���" << endl;
}

void VendingMachine::menu2() {//���� �Է� ���� ������� ���� ����
	cout << endl;
	cout << "===== SWING ���Ǳ� =====" << endl;
	cout << "1. ��ī�ݶ� : 1500��" << endl;
	cout << "2. ��Ÿ500 : 900��" << endl;
	cout << "3. �Ŀ����̵� : 2000��" << endl;
	cout << "4. " << name << " : " << price << "��" << endl;
	cout << "5. ���" << endl;
}

string VendingMachine::getName(){//�������� ����
	return name;
}
double VendingMachine::getPrice() {//�������� ����
	return price;
}
double VendingMachine::getTotal(){//�������� ����
	return total;
}

void VendingMachine::setName(string n) { //�������� �� �ƴϰ� �����ϴ� ����!
	name = n;
};

void VendingMachine::setPrice(int p) { //�Է¹��� �� �����ϴ� ����!
	price = p;
};

void VendingMachine::setTotal(int t) { //�Է¹��� �� �����ϴ� ����!
	total += t;

};


int main() {
	string newName;//���� �߰��� ����� �̸�
	int newPrice;//���� �߰��� ����� ����
	int num;//��� ���� �����
	int amount;//��� ���� ������� ����
	VendingMachine jp; //��ü ����
	VendingMachine *p; //������ ����
	p = &jp; //��ü �ּ� ����

	jp.menu();

	cout << "�߰��� ���� �̸��� �Է����ּ��� : ";
	cin >> newName;
	(*p).setName(newName);//��ü ������

	cout << endl;
	
	cout << "�Ǹ��� ������ �Է��ϼ��� : ";
	cin >> newPrice;
	p->setPrice(newPrice);//��ü ������

	cout << endl;

	while (1) {
		jp.menu2();

		cout << "��ȣ�� �������ּ��� : ";
		cin >> num;

		switch (num) {
		case 1:
			cout << "������ ������ ������ �ּ��� : ";
			cin >> amount;
			amount *= 1500;//�� ���ϱ� ����
			p->setTotal(amount);// �� ��ǰ�� ���� �� ������ total�� �߰��ϱ� ����
			break;//break; �� ������ "������ ���� �����ϼ��� ��� ��"
		case 2:
			cout << "������ ������ ������ �ּ��� : ";
			cin >> amount;
			amount *= 900;
			p->setTotal(amount);
			break;
		case 3:
			cout << "������ ������ ������ �ּ��� : ";
			cin >> amount;
			amount *= 2000;
			p->setTotal(amount);
			break;
		case 4:
			cout << "������ ������ ������ �ּ��� : ";
			cin >> amount;
			amount *= newPrice;
			p->setTotal(amount);
			break;
		}

		if (num == 5) {
			cout << "��� ���Դϴ�. ��ٷ� �ּ���..." << endl;
			break;
		}
		
	}

	jp.purchase(jp.getTotal()); //�Ž�����(get total�� �� �հ�ݾ� ��)
	

}