#include <iostream>
using namespace std;

class ATM {
private:
	string name;//������ �̸�
	int pw;//���� ��й�ȣ
	int pw2;//�ѹ� �� �Է��� ���� ��й�ȣ, ��й�ȣ Ȯ�ο�
	int money;//���� �ܾ�

public:
	ATM();//������
	void Name();
	void Money();
	void Pw();
	void Pw2();
	void Pw3();
	void deposit();//�Ա�
	void withdraw();//����
	void send(string receiver, int sendMon);//��ü-����
	void receive(int receiveMon);//��ü-����
	int getMoney();//���ִ��� ���
	string getName();//�̸� �ҷ�����
};

ATM::ATM() {

}
void ATM::Name() {//�̸� �Է�
	cin >> name;
};

void ATM::Money() {//�ݾ� �Է�
	cin >> money;
}

void ATM::Pw() {//��й�ȣ �Է�
	cin >> pw;
};

void ATM::Pw2() {//���� �� ��й�ȣ Ȯ��
	cin >> pw2;
	while (pw2 != pw) {
		cout << "��й�ȣ�� ���� �ٸ��ϴ�." << endl;
		cout << endl;
		cout << "��й�ȣ�� �Է����ּ��� >> ";
		cin >> pw;
		cout << "�ѹ� �� �Է����ּ��� >> ";
		cin >> pw2;
	}

};

void ATM::Pw3() {//������� �� ��й�ȣ Ȯ��
	cin >> pw2;
	while (pw2 != pw) {
		cout << "��� ��ȣ�� Ʋ�Ƚ��ϴ�." << endl;
		cout << " ��� ��ȣ�� �Է��� �ּ��� >> ";
		cin >> pw2;
	}
}


void ATM::deposit() {//�Ա�
	int add;
	cin >> add;
	money += add;
}

void ATM::withdraw() {//����
	int subtract;//���߿� �ݾ� �Է� ����, ���� ���� ������ �����غ���
	cin >> subtract;
	money -= subtract;
}

void ATM::send(string receiver, int sendMon) {
	money -= sendMon;//�ܾ׿��� ������ ����
}

void ATM::receive(int receiveMon) {
	money += receiveMon;//�ܾ׿��� ���� �� ���ϱ�
}

int ATM::getMoney() {
	return money;
}

string ATM::getName() {
	return name;
}

int main() {
	int num;//���� ���� �ο�
	int j, k;
	string guest, receiver;//������ �� ����, �޴� ���� -> for�� ������ �ε��� ���� ������ ������ ���� 
	int order = 0;
	int check = 0;//������ �����ϴ��� �Ǵ�Ű //check�� ���ְų� j,k�� ���ִ� ������� �����غ���
	int sendMon;

	cout << "���࿡ ������ �ο��� �Է����ּ��� >>";
	cin >> num;
	cout << endl;
	ATM* p = new ATM[num]; //�Է��� ����ŭ ��ü �迭 ���� ����(���� �ο�)
	for (int i = 0; i < num; i++) {
		cout << i + 1 << "��° �մ�" << endl << endl;
		cout << "������ �����ֽʽÿ� >> ";
		p[i].Name();
		cout << "��й�ȣ�� �Է����ּ��� >> ";
		p[i].Pw();
		cout << "�� �� �� �Է����ּ��� >> ";
		p[i].Pw2();
		cout << "�Ա��� �ݾ��� �Է����ּ��� >> ";
		p[i].Money();
		cout << endl << endl;

	}

	while (1) {
		while (check == 0) {
			cout << endl<<"�ѤѤ� SWING ATM �ѤѤ�" << endl;
			cout << "������ �Է����ּ��� (������ x�� �Է����ּ���) >> ";
			cin >> guest;
			cout << endl;
			if (guest == "x") {
				cout << "ATM�� �����մϴ�.";
				exit(1);//���α׷� ����
			}
			for (int i = 0; i < num; i++) {
				if (guest == p[i].getName()) {
					check = 1;//�����ϴ� ������
					j = i;//������ ���� �ִ� ���� �ε��� ��ȣ j�� ����
				}

			}
			if (check != 1) {//check�� 1�� �ƴϸ� �������� �ʴ� ������
				cout << "�������� �ʴ� �������Դϴ�." << endl;
			}
		}

		while (1) {//do-while�� ������ �� �ؿ� �־ 5�� ������ ��� �ݺ���
			cout << endl << "�ѤѤ� SWING ATM " << guest << "�� �ѤѤ�" << endl;
			cout << "1. �Ա�" << endl;
			cout << "2. ����" << endl;
			cout << "3. ��ü" << endl;
			cout << "4. �ܾ� Ȯ��" << endl;
			cout << "5. ����" << endl;
			cout << endl;
			cout << "��ȣ�� �������ּ��� >> ";
			cin >> order;

			if (order == 1) {
				cout << "�Ա��� �ݾ��� �Է����ּ��� >> ";
				p[j].deposit();//�ݾ� �Է� �� j+1���� �� ���¿� ���� �Աݵ�
				cout << endl << "���� " << p[j].getName() << "���� �ܾ��� " << p[j].getMoney() << "�� �Դϴ�." << endl;
				continue;
			}

			if (order == 2) {
				cout << "�󸶸� �����Ͻðڽ��ϱ�? >> ";
				p[j].withdraw();//�ݾ� �Է� �� j+1���� �� ���¿��� ���� �����
				cout << "��й�ȣ�� �Է����ּ��� >> ";//��й�ȣ�� ���� ������ �Է� �ޱ� ������ ������ ���� �����ص� ������� ������ ������ �ݾ��Է�->��ȣ�Է�->����� �����غ���
				p[j].Pw3();
				cout << endl;
				cout << endl << "���� " << p[j].getName() << "���� �ܾ��� " << p[j].getMoney() << "�� �Դϴ�." << endl;
				continue;
			}

			if (order == 3) {
				cout << "�������� �����ڽ��ϱ�? >> ";
				cin >> receiver;
				for (int i = 0; i < num; i++) {
					if (receiver == p[i].getName()) {//�޴� ����� ������ �߿� ������
						check = 1;//������ ������
						k = i;//�޴� ����� �ε��� ��ȣ
					}

				}
				if (check!=1) {
					continue;//�����ְ� �������� ������ �������� ����
				}

				cout << "�󸶸� �����ڽ��ϱ�? >> ";
				cin >> sendMon;
				cout << "��й�ȣ�� �Է��� �ּ��� >> ";
				p[j].Pw3();//������� �� ��й�ȣ Ȯ�� �� ��й�ȣ Ʋ���� ���� ������ ��й�ȣ �Է�
				p[j].send(p[k].getName(), sendMon);//��ü-����(�޴� ���, ����(����) �ݾ�)
				p[k].receive(sendMon);//��ü-����(������ �ݾ�)
				cout << endl;
				cout << p[k].getName() << "�Բ� " << sendMon << "���� ���½��ϴ�." << endl;
				cout << endl;
				cout << endl << "���� " << p[j].getName() << "���� �ܾ��� " << p[j].getMoney() << "�� �Դϴ�." << endl;
				continue;
			}

			if (order == 4) {
				cout << p[j].getName() << "���� ���� �ܾ��� " << p[j].getMoney() << "�Դϴ�." << endl;//������ ���� �ִ� ���� �ܾ�
				continue;
			}
			if (order == 5) {
				break;
			}
			else
				cout << "��ȣ�� �ٽ� �Է��ϼ���" << endl;
			
		}
		check = 0;//�� ���� check�� ��� 1�� ���� �ֱ� ������ �ݺ����� ���ư��� �ʴ´�.
	}

}