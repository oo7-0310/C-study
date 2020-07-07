#include <iostream>
using namespace std;

class ATM {
private:
	string name;//계좌주 이름
	int pw;//계좌 비밀번호
	int pw2;//한번 더 입력한 계좌 비밀번호, 비밀번호 확인용
	int money;//계좌 잔액

public:
	ATM();//생성자
	void Name();
	void Money();
	void Pw();
	void Pw2();
	void Pw3();
	void deposit();//입금
	void withdraw();//인출
	void send(string receiver, int sendMon);//이체-받음
	void receive(int receiveMon);//이체-보냄
	int getMoney();//얼마있는지 출력
	string getName();//이름 불러오기
};

ATM::ATM() {

}
void ATM::Name() {//이름 입력
	cin >> name;
};

void ATM::Money() {//금액 입력
	cin >> money;
}

void ATM::Pw() {//비밀번호 입력
	cin >> pw;
};

void ATM::Pw2() {//가입 시 비밀번호 확인
	cin >> pw2;
	while (pw2 != pw) {
		cout << "비밀번호가 서로 다릅니다." << endl;
		cout << endl;
		cout << "비밀번호를 입력해주세요 >> ";
		cin >> pw;
		cout << "한번 더 입력해주세요 >> ";
		cin >> pw2;
	}

};

void ATM::Pw3() {//은행업무 중 비밀번호 확인
	cin >> pw2;
	while (pw2 != pw) {
		cout << "비밀 번호가 틀렸습니다." << endl;
		cout << " 비밀 번호를 입력해 주세요 >> ";
		cin >> pw2;
	}
}


void ATM::deposit() {//입금
	int add;
	cin >> add;
	money += add;
}

void ATM::withdraw() {//인출
	int subtract;//나중에 금액 입력 따로, 인출 따로 나눠서 수정해보기
	cin >> subtract;
	money -= subtract;
}

void ATM::send(string receiver, int sendMon) {
	money -= sendMon;//잔액에서 보낸돈 빼기
}

void ATM::receive(int receiveMon) {
	money += receiveMon;//잔액에서 받은 돈 더하기
}

int ATM::getMoney() {
	return money;
}

string ATM::getName() {
	return name;
}

int main() {
	int num;//은행 가입 인원
	int j, k;
	string guest, receiver;//업무를 볼 고객명, 받는 고객명 -> for문 돌려서 인덱스 값을 임의의 변수에 저장 
	int order = 0;
	int check = 0;//계좌주 존재하는지 판단키 //check를 없애거나 j,k를 없애는 방법으로 수정해보기
	int sendMon;

	cout << "은행에 가입할 인원을 입력해주세요 >>";
	cin >> num;
	cout << endl;
	ATM* p = new ATM[num]; //입력한 값만큼 객체 배열 동적 생성(가입 인원)
	for (int i = 0; i < num; i++) {
		cout << i + 1 << "번째 손님" << endl << endl;
		cout << "성명을 적어주십시오 >> ";
		p[i].Name();
		cout << "비밀번호를 입력해주세요 >> ";
		p[i].Pw();
		cout << "한 번 더 입력해주세요 >> ";
		p[i].Pw2();
		cout << "입금할 금액을 입력해주세요 >> ";
		p[i].Money();
		cout << endl << endl;

	}

	while (1) {
		while (check == 0) {
			cout << endl<<"ㅡㅡㅡ SWING ATM ㅡㅡㅡ" << endl;
			cout << "성함을 입력해주세요 (종료라면 x를 입력해주세요) >> ";
			cin >> guest;
			cout << endl;
			if (guest == "x") {
				cout << "ATM을 종료합니다.";
				exit(1);//프로그램 종료
			}
			for (int i = 0; i < num; i++) {
				if (guest == p[i].getName()) {
					check = 1;//존재하는 계좌주
					j = i;//업무를 보고 있는 고객의 인덱스 번호 j에 저장
				}

			}
			if (check != 1) {//check가 1이 아니면 존재하지 않는 계좌주
				cout << "존재하지 않는 계좌주입니다." << endl;
			}
		}

		while (1) {//do-while은 조건이 맨 밑에 있어서 5를 눌러도 계속 반복됨
			cout << endl << "ㅡㅡㅡ SWING ATM " << guest << "님 ㅡㅡㅡ" << endl;
			cout << "1. 입금" << endl;
			cout << "2. 인출" << endl;
			cout << "3. 이체" << endl;
			cout << "4. 잔액 확인" << endl;
			cout << "5. 종료" << endl;
			cout << endl;
			cout << "번호를 선택해주세요 >> ";
			cin >> order;

			if (order == 1) {
				cout << "입금할 금액을 입력해주세요 >> ";
				p[j].deposit();//금액 입력 후 j+1번의 고객 계좌에 돈이 입금됨
				cout << endl << "현재 " << p[j].getName() << "님의 잔액은 " << p[j].getMoney() << "원 입니다." << endl;
				continue;
			}

			if (order == 2) {
				cout << "얼마를 인출하시겠습니까? >> ";
				p[j].withdraw();//금액 입력 후 j+1번의 고객 계좌에서 돈이 인출됨
				cout << "비밀번호를 입력해주세요 >> ";//비밀번호가 맞을 때까지 입력 받기 때문에 위에서 먼저 인출해도 결과에는 지장이 없으나 금액입력->번호입력->인출로 수정해보기
				p[j].Pw3();
				cout << endl;
				cout << endl << "현재 " << p[j].getName() << "님의 잔액은 " << p[j].getMoney() << "원 입니다." << endl;
				continue;
			}

			if (order == 3) {
				cout << "누구에게 보내겠습니까? >> ";
				cin >> receiver;
				for (int i = 0; i < num; i++) {
					if (receiver == p[i].getName()) {//받는 사람이 계좌주 중에 있으면
						check = 1;//계좌주 존재함
						k = i;//받는 사람의 인덱스 번호
					}

				}
				if (check!=1) {
					continue;//계좌주가 존재하지 않으면 메인으로 가기
				}

				cout << "얼마를 보내겠습니까? >> ";
				cin >> sendMon;
				cout << "비밀번호를 입력해 주세요 >> ";
				p[j].Pw3();//은행업무 중 비밀번호 확인 후 비밀번호 틀리면 맞을 때까지 비밀번호 입력
				p[j].send(p[k].getName(), sendMon);//이체-받음(받는 사람, 보낸(받은) 금액)
				p[k].receive(sendMon);//이체-보냄(보내는 금액)
				cout << endl;
				cout << p[k].getName() << "님께 " << sendMon << "원을 보냈습니다." << endl;
				cout << endl;
				cout << endl << "현재 " << p[j].getName() << "님의 잔액은 " << p[j].getMoney() << "원 입니다." << endl;
				continue;
			}

			if (order == 4) {
				cout << p[j].getName() << "님의 현재 잔액은 " << p[j].getMoney() << "입니다." << endl;//업무를 보고 있는 고객의 잔액
				continue;
			}
			if (order == 5) {
				break;
			}
			else
				cout << "번호를 다시 입력하세요" << endl;
			
		}
		check = 0;//안 쓰면 check가 계속 1이 남아 있기 때문에 반복문이 돌아가지 않는다.
	}

}