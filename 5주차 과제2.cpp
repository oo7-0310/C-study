
#include <iostream>
#include <string>
using namespace std;

class VendingMachine {
private:
	string name; //음료 이름
	int price;//가격
	int total=0;//음료 합산 값

public:
	VendingMachine() {};//생성자
	void purchase(double v1); //총 금액 출력, 지폐 입력, 거스름돈 출력
	void menu(); //메뉴판
	void menu2(); //새 메뉴판 (입력 받은 후)
	string getName(); // name 반환
	double getPrice();// price반환
	double getTotal();//총 합계 반환
	void setName(string n); //음료 이름 저장
	void setPrice(int p);// 음료 가격 저장
	void setTotal(int t);// 금액 계속 더해주는 곳
};

void VendingMachine::purchase(double v1) {
	int money;// 내가 낼 돈
	int change; // 거스름 돈

	cout << "총금액 : " << v1 << endl;
	cout << "지폐를 입력하세요 : ";
	cin >> money;
	cout << endl;
	while (1) {

		if (v1 > money) {
			cout << "금액이 부족합니다. 다시 넣어주세요.";
			cin >> money;
			continue;//부족하면 다시 돈 넣어야 하니까 반복
		}
		if (v1 < money) {
			change = money - v1;
			if (money % 100 != 0)
			{
				cout << "거스름돈은 500원과 100원만 가능합니다.";
				cout << "500원 : " << change / 500 << "개" << endl;
				cout << "100원 : " << change % 500 / 100 << "개" << endl;
				break;// 계산 끝났으므로 break; 반복문 탈출하기
			}
			else {
				cout << "거스름돈 입니다." << endl;
				cout << "500원 : " << change / 500 << "개" << endl;
				cout << "100원 : " << change % 500 / 100 << "개" << endl;
				break;
			}
		}
		if (v1 == money) {
			cout << "거스름돈이 없습니다. 안녕히 가세요" << endl;
			break;
		}
	}
}

void VendingMachine::menu() {
	cout << "===== SWING 자판기 =====" << endl;
	cout << "1. 코카콜라 : 1500원" << endl;
	cout << "2. 비타500 : 900원" << endl;
	cout << "3. 파워에이드 : 2000원" << endl;
	cout << "4. 준비중" << endl;
	cout << "5. 계산" << endl;
}

void VendingMachine::menu2() {//새로 입력 받은 음료수와 가격 수정
	cout << endl;
	cout << "===== SWING 자판기 =====" << endl;
	cout << "1. 코카콜라 : 1500원" << endl;
	cout << "2. 비타500 : 900원" << endl;
	cout << "3. 파워에이드 : 2000원" << endl;
	cout << "4. " << name << " : " << price << "원" << endl;
	cout << "5. 계산" << endl;
}

string VendingMachine::getName() {//내보내는 공간
	return name;
}
double VendingMachine::getPrice() {//내보내는 공간
	return price;
}
double VendingMachine::getTotal() {//내보내는 공간
	return total;
}

void VendingMachine::setName(string n) { //내보내는 거 아니고 저장하는 공간!
	name = n;
};

void VendingMachine::setPrice(int p) { //입력받은 걸 저장하는 공간!
	price = p;
};

void VendingMachine::setTotal(int t) { //입력받은 걸 저장하는 공간!
	total += t;

};


int main() {
	string newName;//새로 추가할 음료수 이름
	int newPrice;//새로 추가할 음료수 가격
	int num;//사고 싶은 음료수
	int amount;//사고 싶은 음료수의 개수
	VendingMachine jp; //객체 생성
	VendingMachine* p; //포인터 선언
	p = &jp; //객체 주소 저장

	jp.menu();

	cout << "추가할 음료 이름을 입력해주세요 : ";
	cin >> newName;
	(*p).setName(newName);//객체 포인터

	cout << endl;

	cout << "판매할 가격을 입력하세요 : ";
	cin >> newPrice;
	p->setPrice(newPrice);//객체 포인터

	cout << endl;

	while (1) {
		jp.menu2();

		cout << "번호를 선택해주세요 : ";
		cin >> num;

		switch (num) {
		case 1:
			cout << "구매할 수량을 선택해 주세요 : ";
			cin >> amount;
			amount *= 1500;//양 곱하기 가격
			p->setTotal(amount);// 이 제품에 대한 총 가격을 total에 추가하기 위해
			break;//break; 안 넣으면 "구매할 수량 선택하세요 계속 뜸"
		case 2:
			cout << "구매할 수량을 선택해 주세요 : ";
			cin >> amount;
			amount *= 900;
			p->setTotal(amount);
			break;
		case 3:
			cout << "구매할 수량을 선택해 주세요 : ";
			cin >> amount;
			amount *= 2000;
			p->setTotal(amount);
			break;
		case 4:
			cout << "구매할 수량을 선택해 주세요 : ";
			cin >> amount;
			amount *= newPrice;
			p->setTotal(amount);
			break;
		}

		if (num == 5) {
			cout << "계산 중입니다. 기다려 주세요..." << endl;
			break;
		}

	}

	jp.purchase(jp.getTotal()); //거스름돈(get total에 총 합계금액 들어감)


}