#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

class kiosk {
private:
	vector<string>burger = { "�������","�Ұ�� ����","���̹���","��ġ�����" };
	vector<int>bprice = { 4300,4500,4700,4900 };
	vector<string>side = { "ġ�ƽ","����Ƣ��","������","���̽�ũ��" };
	vector<int>sprice = { 1500,1000,1500,700 };
	vector<string>drink = { "���̴�","�ݶ�","ȯŸ","�������ֽ�" };
	int dprice = 1000;
	vector<string> total = { "�� �ֹ� �޴�" };
	ofstream writeFile;
	

public:
	kiosk();
	int border, sorder, dorder;
	int b, s, d;
	int cnt = 0;
	void getburger();
	void getside();
	void getdrink();
	void select(int a);
	void price();
	~kiosk() {};
};

kiosk::kiosk() {


}

void kiosk::getburger() {
	for (int i = 0; i < 4; i++) {
		cout << i + 1 << ". " << burger.at(i)<<" ("<<bprice.at(i)<<")"<< endl;
	}
	cout << endl;

	cout << "�ֹ��� ������ ��ȣ�� ������ �Է����ּ���" << endl;
	cout << "ex>������� 2�� : 1 2" << endl;
	cin >> border;
	cin >> b;
	while (border > 4) {
		cout << "�������� �ʴ� �޴��� �����ϼ̽��ϴ�." << endl;
		cout << "�ٽ� ������ �ֽʽÿ�." << endl;
		cin >> border;
		cin >> b;
	}
	cout << burger.at(border - 1) << " " << b << "���� �ֹ��Ǿ����ϴ�.";
	cout << endl;
	cnt = cnt + bprice.at(border - 1) * b;
}

void kiosk::getside() {
	for (int i = 0; i < 4; i++) {
		cout << i + 1 << ". " << side.at(i) << " (" << sprice.at(i) <<")"<< endl;
	}
	cout << endl;

	cout << "�ֹ��� ���̵��� ��ȣ�� ������ �Է����ּ���" << endl;
	cout << "ex>ġ�ƽ 2�� : 1 2" << endl;
	cin >> sorder;
	cin >> s;
	while (sorder > 4) {
		cout << "�������� �ʴ� �޴��� �����ϼ̽��ϴ�." << endl;
		cout << "�ٽ� ������ �ֽʽÿ�." << endl;
		cin >> sorder;
		cin >> s;
	}
	cout << side.at(sorder - 1) << " " << s << "���� �ֹ��Ǿ����ϴ�.";
	cout << endl;
	cnt = cnt + sprice.at(sorder - 1) * s;

}

void kiosk::getdrink() {
	for (int i = 0; i < 4; i++) {
		cout << i + 1 << ". " << drink.at(i)<< " (" <<dprice<<")" << endl;
	}
	cout << endl;

	cout << "�ֹ��� ������ ��ȣ�� ������ �Է����ּ���" << endl;
	cout << "ex>���̴� 2�� : 1 2" << endl;
	cin >> dorder;
	cin >> d;
	while (dorder > 4) {
		cout << "�������� �ʴ� �޴��� �����ϼ̽��ϴ�." << endl;
		cout << "�ٽ� ������ �ֽʽÿ�." << endl;
		cin >> dorder;
		cin >> d;
	}
	cout << drink.at(dorder - 1) << " " << d << "���� �ֹ��Ǿ����ϴ�.";
	cout << endl;
	cnt = cnt + dprice * d;
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


void kiosk::price() {
	writeFile.open("������.txt");
	writeFile.write("=========������=========\n",25);
	if (border >= 1) {
		writeFile.write(burger.at(border - 1).c_str(), burger.at(border - 1).size());
		writeFile.write(" ", 1);
		writeFile.write(to_string(b).c_str(), 1);
		writeFile.write("��", 2);
		writeFile.write("\n",1);
	}
	if (sorder >= 1) {
		writeFile.write(side.at(sorder - 1).c_str(), side.at(sorder - 1).size());
		writeFile.write(" ", 1);
		writeFile.write(to_string(s).c_str(), 1);
		writeFile.write("��", 2);
		writeFile.write("\n", 1);
	}
	if (dorder >= 1) {
		writeFile.write(drink.at(dorder - 1).c_str(), drink.at(dorder - 1).size());
		writeFile.write(" ", 1);
		writeFile.write(to_string(d).c_str(), 1);
		writeFile.write("��", 2);
		writeFile.write("\n", 1);
	}
	writeFile.write("========================\n", 25);
	writeFile.write("�� ����:", 8);
	writeFile.write(to_string(cnt).c_str(), to_string(cnt).size());
	writeFile.write("\n", 1);
	writeFile.write("�����մϴ�.", 11);

	writeFile.close();

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
		else {
			cout << "�������� ��µǾ����ϴ�.";
			menu.price();
			break;
		}
	}
	return 0;
}