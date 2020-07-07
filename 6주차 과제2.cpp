#include <iostream>
using namespace std;

class PhoneBook {
	string name; //이름
	string number;//전화번호
public:
	PhoneBook();//생성자
	void setPnum(string number);//전화번호 저장
	void setName(string name);//이름 저장
	void addPhone(string name, string number);//이름과 전화번호 저장
	string getPnum();//전화번호 가져오기
	string getName();//이름 가져오기

};

PhoneBook::PhoneBook() {//생성자
};

void PhoneBook::setPnum(string number) {//전화번호 저장
	this->number = number;//매개 변수로 갖고오는 number을 객체에 있는 멤버 변수 number로 사용한다.
}

void PhoneBook::setName(string name) {//이름 저장
	this->name = name;//매개 변수로 갖고오는 name을 객체에 있는 멤버 변수 name으로 사용한다.
}

void PhoneBook::addPhone(string name, string number) {//이름과 전화번호 저장
	this->name = name;
	this->number = number;
}

string PhoneBook::getPnum() {//번호 반환
	return number;
}

string PhoneBook::getName() {//이름 반환
	return name;
}

class PhoneBookmenu {
private:
	PhoneBook* phnum;// PhoneBookmenu의 클래스 함수에서 PhoneBook에 대한 값들을 쓸 것임.
	int i;//반복분에서 사용, i번째 사람에서 사용
	int num;//저장할 전화번호의 수
	int check = 9999;
	string SearchName;//번호 검색할 이름
	string name;//i번째 사람의 이름
	string number;//i번째 사람의 번호
	string newName;//추가할 (i+1)번째 사람의 이름
	string newNumber;//추가할 (i+1)번째 사람의 번호
	string editName;//수정할 사람의 이름
	string editNumber;//수정할 사람의 번호

public:
	PhoneBookmenu();//생성자
	void savePB();//num 명의 이름, 전화번호 저장
	void showPB();//전화번호부 보기
	void searchPB();//전화번호 검색
	void addPB();//전화번호 추가하기
	void editPB();//전화번호 수정하기
	void close();//전화번호부 종료하기
};

PhoneBookmenu::PhoneBookmenu() {
	
};

void PhoneBookmenu::savePB() {
	cout << "--- swing 전화번호부 ---" << endl;
	cout << "저장할 전화번호의 수를 입력해주세요 >> ";
	cin >> num;//몇명 저장할 건지 입력
	cout << endl;
	phnum = new PhoneBook[num];//입력 받은 만큼 객체 배열 동적 생성
	
	for (i = 0; i < num; i++) {
		cout << i + 1 << "번째 사람의 이름을 입력해주세요 >> ";
		cin >> name;//매개변수로 활용
		cout << i + 1 << "번째 사람의 전화번호를 입력해주세요 >> ";
		cin >> number;
		phnum[i].setName(name);
		phnum[i].setPnum(number);//num 명의 이름, 번호 저장
		cout << endl;
	}

}
void PhoneBookmenu::showPB() {
	for (i = 0; i < num; i++) {
		cout << i + 1 << ".";
		cout << phnum[i].getName();
		cout << "::";
		cout << phnum[i].getPnum() << endl;//num 명의 이름, 번호 저장
	}
	cout << endl << endl;
};
void PhoneBookmenu::searchPB() {
	cout << "누구의 번호를 검색하겠습니까? >> ";
	cin >> SearchName;
	for (i = 0; i < num; i++) {
		if (SearchName == phnum[i].getName()) {
			check = i;
		}
	}
	if (check < num) {
		cout << SearchName << "님의 전화번호 : " << phnum[check].getPnum() << endl;
	}
	else
		cout << "연락처가 존재하지 않습니다." << endl;
	check = 9999;// 밑에서 반복문 돌릴거니까 초기값인 9999로 초기화
	cout << endl << endl;
};
void PhoneBookmenu::addPB() {
	cout << "이름을 입력해주세요 >> ";
	cin >> newName;
	cout << "전화번호를 입력해주세요 >> ";
	cin >> newNumber;
	//new/delete는 재할당 불가능,  malloc/free는 realloc으로 크기 변경 가능
	PhoneBook* tmp = new PhoneBook[num + 1];
	memcpy(tmp, phnum, num * sizeof(PhoneBook));
	//memcpy 메모리 복사, 차례로(데이터가 복사될 곳의 주소, 복사할 데이터들이 위치한 주소, 복사할 데이터의 byte 수)
	num = num + 1;//배열 크기를 하나 늘린다.
	delete[] phnum;//기존의 할당받은 것은 삭제하고
	phnum = tmp; //복사해 두었던 것 다시 받아오기

	phnum[num - 1].addPhone(newName, newNumber); //배열의 마지막 자리에 전화번호 추가
	cout << "전화번호가 추가되었습니다." << endl;
	cout << endl << endl;
};
void PhoneBookmenu::editPB() {
	cout << "누구의 번호를 수정하시겠습니까? >> ";
	cin >> editName;
	for (i = 0; i < num; i++) {
		if (editName == phnum[i].getName()) {
			check = i;//수정할 이름과 일치하는 이름을 갖고있는 배열의 인덱스값을 check에 임의로 저장
		}
	}
	if (check < num)
	{
		cout << "변경할 번호를 입력해주세요 >> ";
		cin >> editNumber;
		phnum[check].setPnum(editNumber);//아까 일치했던 곳의 번호를 다시 입력하여 넣는다.
		cout << "전화번호가 변경되었습니다." << endl;
	}
	else
		cout << "연락처가 존재하지 않습니다.";

	check = 9999;//인덱스값 원래대로 되돌려 놓기(반복 해야하니까)
	cout << endl << endl;
};
void PhoneBookmenu::close() {
	cout << endl << "프로그램을 종료합니다.";
	cout << endl << endl;
};

int main()
{

	PhoneBookmenu menu; //PhoneBookmenu 클래스를 menu라는 이름으로 쓰겠다.

	menu.savePB();

	while (1)
	{
		int n;
		cout << "--- swing 전화번호부 ---" << endl;
		cout << "1. 전화번호부 보기" << endl;
		cout << "2. 전화번호 검색" << endl;
		cout << "3. 전화번호 추가하기" << endl;
		cout << "4. 전화번호 수정하기" << endl;
		cout << "5. 종료" << endl;
		cout << "번호를 입력해주세요 >> ";
		cin >> n;
		cout << endl << endl;

		if (n == 1)
		{
			menu.showPB();
			continue;//다시 반복
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
			exit(1); //종료!
		}
		else {
			cout << "잘못 입력하셨습니다." << endl;
			continue;//번호 다시 입력받기 위해
		}

	}
}