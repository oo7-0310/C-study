#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

class kiosk {
private:
	vector<string>burger = { "새우버거","불고기 버거","싸이버거","딥치즈버거" };
	vector<int>bprice = { 4300,4500,4700,4900 };
	vector<string>side = { "치즈스틱","감자튀김","샐러드","아이스크림" };
	vector<int>sprice = { 1500,1000,1500,700 };
	vector<string>drink = { "사이다","콜라","환타","오렌지주스" };
	int dprice = 1000;
	vector<string> total = { "총 주문 메뉴" };
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

	cout << "주문할 버거의 번호와 수량을 입력해주세요" << endl;
	cout << "ex>새우버거 2개 : 1 2" << endl;
	cin >> border;
	cin >> b;
	while (border > 4) {
		cout << "존재하지 않는 메뉴를 선택하셨습니다." << endl;
		cout << "다시 선택해 주십시오." << endl;
		cin >> border;
		cin >> b;
	}
	cout << burger.at(border - 1) << " " << b << "개가 주문되었습니다.";
	cout << endl;
	cnt = cnt + bprice.at(border - 1) * b;
}

void kiosk::getside() {
	for (int i = 0; i < 4; i++) {
		cout << i + 1 << ". " << side.at(i) << " (" << sprice.at(i) <<")"<< endl;
	}
	cout << endl;

	cout << "주문할 사이드의 번호와 수량을 입력해주세요" << endl;
	cout << "ex>치즈스틱 2개 : 1 2" << endl;
	cin >> sorder;
	cin >> s;
	while (sorder > 4) {
		cout << "존재하지 않는 메뉴를 선택하셨습니다." << endl;
		cout << "다시 선택해 주십시오." << endl;
		cin >> sorder;
		cin >> s;
	}
	cout << side.at(sorder - 1) << " " << s << "개가 주문되었습니다.";
	cout << endl;
	cnt = cnt + sprice.at(sorder - 1) * s;

}

void kiosk::getdrink() {
	for (int i = 0; i < 4; i++) {
		cout << i + 1 << ". " << drink.at(i)<< " (" <<dprice<<")" << endl;
	}
	cout << endl;

	cout << "주문할 음료의 번호와 수량을 입력해주세요" << endl;
	cout << "ex>사이다 2개 : 1 2" << endl;
	cin >> dorder;
	cin >> d;
	while (dorder > 4) {
		cout << "존재하지 않는 메뉴를 선택하셨습니다." << endl;
		cout << "다시 선택해 주십시오." << endl;
		cin >> dorder;
		cin >> d;
	}
	cout << drink.at(dorder - 1) << " " << d << "개가 주문되었습니다.";
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
		cout << "존재하지 않는 분류를 선택하셨습니다." << endl;
		cout << "다시 선택해 주십시오." << endl;
		cin >> a;
		select(a);
	}

}


void kiosk::price() {
	writeFile.open("영수증.txt");
	writeFile.write("=========영수증=========\n",25);
	if (border >= 1) {
		writeFile.write(burger.at(border - 1).c_str(), burger.at(border - 1).size());
		writeFile.write(" ", 1);
		writeFile.write(to_string(b).c_str(), 1);
		writeFile.write("개", 2);
		writeFile.write("\n",1);
	}
	if (sorder >= 1) {
		writeFile.write(side.at(sorder - 1).c_str(), side.at(sorder - 1).size());
		writeFile.write(" ", 1);
		writeFile.write(to_string(s).c_str(), 1);
		writeFile.write("개", 2);
		writeFile.write("\n", 1);
	}
	if (dorder >= 1) {
		writeFile.write(drink.at(dorder - 1).c_str(), drink.at(dorder - 1).size());
		writeFile.write(" ", 1);
		writeFile.write(to_string(d).c_str(), 1);
		writeFile.write("개", 2);
		writeFile.write("\n", 1);
	}
	writeFile.write("========================\n", 25);
	writeFile.write("총 가격:", 8);
	writeFile.write(to_string(cnt).c_str(), to_string(cnt).size());
	writeFile.write("\n", 1);
	writeFile.write("감사합니다.", 11);

	writeFile.close();

}

int main() {

	kiosk menu;
	int num;
	char exit;

	while (1) {
		cout << "======= 메뉴 분류 ========" << endl;
		cout << "1. 햄버거" << endl;
		cout << "2. 사이드" << endl;
		cout << "3. 음료" << endl;
		cout << "=========================" << endl << endl;
		cout << "몇번을 선택하시겠습니까? ";

		cin >> num;
		menu.select(num);
		cout << "계속 선택하시겠습니까?(y or 끝내려면 아무키나 눌러주세요)" << endl;
		cin >> exit;
		if (exit == 'y') {
			continue;
		}
		else {
			cout << "영수증이 출력되었습니다.";
			menu.price();
			break;
		}
	}
	return 0;
}