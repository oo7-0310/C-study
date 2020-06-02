#include <iostream>
using namespace std;

class Phonebook { //class 선언
	string name; //문자열을 입력받아야 하기 때문에 string
	string pnum;// private 변수 (class 안에서만 쓸 거라서)
public:
	void addPhone(); //특정 값을 return 하는 게 아니라 실행이 목적-> void
	void editPhone();// main에서 쓸 거라 public
	string getPnum();//문자열을 return할 예정->string
	string getName();
};

void Phonebook::addPhone() {//처음에 쓸 매개함수이다. 이름과 번호를 입력받는다.
	cout << "--- swing 전화번호부 ---" << endl;
	cout << "이름을 입력해 주세요>> ";
	cin >> name;//클래스 선언할 때 private 설정했던 name 변수, 사용자에게서 이름을 입력받는다.
	cout << "번호를 입력해 주세요>> ";
	cin >> pnum;// 클래스 선언할 때 private 설정했던 pnum 변수, 사용자에게서 전화번호를 입력받는다.
}

void Phonebook::editPhone() {// 이름 검색하여 번호를 수정하는 함수이다.
	string edit;// 수정할 번호 입력받을 문자열 선언
	cout << "이름을 입력해 주세요 >>";
	cin >> edit;
	while (1) {// 올바른 이름을 입력할 때까지 반복한다.
		if (edit != name) {
			cout << "연락처가 존재하지 않습니다 다시 입력해 주세요>>";
			cin >> edit;
			continue;
		}
		else {//저장된 이름과 변경하고자 하는 이름이 같으면 변경할 전화번호를 새로 입력한다.
			cout << "변경할 전화번호를 입력해 주세요 >>";
			cin >> pnum;//전화번호를 입력받았던 pnum 변수에 다시 입력받는다.
			break;
		}
	}
}

string Phonebook::getPnum() {
	return pnum;// 최종적으로 저장된 번호를 return하는 함수이다.
}

string Phonebook::getName() {
	return name;// 최종적으로 저장된 이름을 return하는 함수이다.
}

int main()
{
	Phonebook phnum;// 매개변수 없는 생성자를 호출한다.
	phnum.addPhone();//바로 함수를 불러들인다. 매개변수.함수이름(); 
	while (1)//3 누를 때가지 반복
	{
		int n;//1, 2, 3입력받을 변수를 선언한다.
		cout << "1. 최신 등록 전화번호 조회" << endl;
		cout << "2. 최신 등록 전화번호 수정" << endl;
		cout << "3. 종료 >>";
		cin >> n;

		if (n == 1)
		{
			cout <<phnum.getName();//해당 함수에서 return 했던 값을 출력한다.
			cout << "::";
			cout <<phnum.getPnum();//그냥 return하면 값 출력 안한다. 반드시 cout 쓰기
			cout << endl;
			continue; //1,,2,3중에 다시 고를 수 있도록 반복문 다시 실행
		}

		if (n == 2) {
			phnum.editPhone();//전화번호를 수정하는 함수이다.
			continue;
		}

		if(n == 3) {
			exit(1);//반복 끝내고 아예 종료한다.
		}
	}
}