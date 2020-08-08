#include <iostream>
#include <vector>
using namespace std;

class kiosk {
private:
	vector<string>burger = { "새우버거","불고기 버거","싸이버거","딥치즈버거" };
	vector<string>side = { "치즈스틱","감자튀김","샐러드","아이스크림" };
	vector<string>drink = { "사이다","콜라","환타","오렌지주스" };

public:
	kiosk();
	int order, n;//메뉴 번호와 수량 저장하는 변수
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

	cout << "주문할 버거의 번호와 수량을 입력해주세요" << endl;
	cout << "ex>새우버거 2개 : 1 2" << endl;
	cin >> order;
	cin >> n;
	while (order > 4) {
		cout << "존재하지 않는 메뉴를 선택하셨습니다." << endl;
		cout << "다시 선택해 주십시오." << endl;
		cin >> order;
		cin >> n;
	}
	cout << burger.at(order - 1) << " " << n << "개가 주문되었습니다.";
	cout << endl;
}

void kiosk::getside() {
	for (int i = 0; i < 4; i++) {
		cout << i+1 << ". " << side.at(i) << endl;
	}
	cout << endl;

	cout << "주문할 사이드의 번호와 수량을 입력해주세요" << endl;
	cout << "ex>치즈스틱 2개 : 1 2" << endl;
	cin >> order;
	cin >> n;
	while (order > 4) {
		cout << "존재하지 않는 메뉴를 선택하셨습니다." << endl;
		cout << "다시 선택해 주십시오." << endl;
		cin >> order;
		cin >> n;
	}
	cout << side.at(order - 1) << " " << n << "개가 주문되었습니다.";
	cout << endl;

}

void kiosk::getdrink() {
	for (int i = 0; i < 4; i++) {
		cout << i+1 << ". " << drink.at(i) << endl;
	}
	cout << endl;

	cout << "주문할 음료의 번호와 수량을 입력해주세요" << endl;
	cout << "ex>사이다 2개 : 1 2" << endl;
	cin >> order;
	cin >> n;
	while (order > 4) {
		cout << "존재하지 않는 메뉴를 선택하셨습니다." << endl;
		cout << "다시 선택해 주십시오." << endl;
		cin >> order;
		cin >> n;
	}
	cout << drink.at(order - 1) << " " << n << "개가 주문되었습니다.";
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
			cout << "존재하지 않는 분류를 선택하셨습니다." << endl;
			cout << "다시 선택해 주십시오." << endl;
			cin >> a;
			select(a);
		}
	
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
		else
			break;
	}
	return 0;
}