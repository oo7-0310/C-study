#include <iostream>
#include <vector>
using namespace std;

class kiosk {
private:
	vector<string>burger = { "�������","�Ұ�� ����","���̹���","��ġ�����" };
	vector<string>side = { "ġ�ƽ","����Ƣ��","������","���̽�ũ��" };
	vector<string>drink = { "���̴�","�ݶ�","ȯŸ","�������ֽ�" };

public:
	kiosk();
	int order, n;//�޴� ��ȣ�� ���� �����ϴ� ����
	void getburger();
	void getside();
	void getdrink();
	void select(int a);
	~kiosk() {};
};

kiosk::kiosk() {
	

}

void kiosk::getburger() {
	for (int i = 0; i < 4; i++) {
		cout << i+1 << ". " << burger.at(i) << endl;
	}
	cout << endl;

	cout << "�ֹ��� ������ ��ȣ�� ������ �Է����ּ���" << endl;
	cout << "ex>������� 2�� : 1 2" << endl;
	cin >> order;
	cin >> n;
	while (order > 4) {
		cout << "�������� �ʴ� �޴��� �����ϼ̽��ϴ�." << endl;
		cout << "�ٽ� ������ �ֽʽÿ�." << endl;
		cin >> order;
		cin >> n;
	}
	cout << burger.at(order - 1) << " " << n << "���� �ֹ��Ǿ����ϴ�.";
	cout << endl;
}

void kiosk::getside() {
	for (int i = 0; i < 4; i++) {
		cout << i+1 << ". " << side.at(i) << endl;
	}
	cout << endl;

	cout << "�ֹ��� ���̵��� ��ȣ�� ������ �Է����ּ���" << endl;
	cout << "ex>ġ�ƽ 2�� : 1 2" << endl;
	cin >> order;
	cin >> n;
	while (order > 4) {
		cout << "�������� �ʴ� �޴��� �����ϼ̽��ϴ�." << endl;
		cout << "�ٽ� ������ �ֽʽÿ�." << endl;
		cin >> order;
		cin >> n;
	}
	cout << side.at(order - 1) << " " << n << "���� �ֹ��Ǿ����ϴ�.";
	cout << endl;

}

void kiosk::getdrink() {
	for (int i = 0; i < 4; i++) {
		cout << i+1 << ". " << drink.at(i) << endl;
	}
	cout << endl;

	cout << "�ֹ��� ������ ��ȣ�� ������ �Է����ּ���" << endl;
	cout << "ex>���̴� 2�� : 1 2" << endl;
	cin >> order;
	cin >> n;
	while (order > 4) {
		cout << "�������� �ʴ� �޴��� �����ϼ̽��ϴ�." << endl;
		cout << "�ٽ� ������ �ֽʽÿ�." << endl;
		cin >> order;
		cin >> n;
	}
	cout << drink.at(order - 1) << " " << n << "���� �ֹ��Ǿ����ϴ�.";
	cout << endl;
}

void kiosk::select(int a) {

		switch (a) {
		case 1:
			getburger();
			break;
		case 2:
			getside();
			break;
		case 3:
			getdrink();
			break;
		default:
			cout << "�������� �ʴ� �з��� �����ϼ̽��ϴ�." << endl;
			cout << "�ٽ� ������ �ֽʽÿ�." << endl;
			cin >> a;
			select(a);
		}
	
}




int main() {

	kiosk menu;
	int num;
	char exit;

	while (1) {
		cout << "======= �޴� �з� ========" << endl;
		cout << "1. �ܹ���" << endl;
		cout << "2. ���̵�" << endl;
		cout << "3. ����" << endl;
		cout << "=========================" << endl << endl;
		cout << "����� �����Ͻðڽ��ϱ�? ";

		cin >> num;
		menu.select(num);
		cout << "��� �����Ͻðڽ��ϱ�?(y or �������� �ƹ�Ű�� �����ּ���)" << endl;
		cin >> exit;
		if (exit == 'y') {
			continue;
		}
		else
			break;
	}
	return 0;
}