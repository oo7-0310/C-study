#include <iostream>
#include <string.h>
#include "5주차과제class.h"
using namespace std;



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