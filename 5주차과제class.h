#include <iostream>
#include <string.h>
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
