#include <iostream>
#include <string.h>
using namespace std;

class Phonebook { //class ����
	string name; //���ڿ��� �Է¹޾ƾ� �ϱ� ������ string
	string pnum;// private ���� (class �ȿ����� �� �Ŷ�)
public:
	void addPhone(); //Ư�� ���� return �ϴ� �� �ƴ϶� ������ ����-> void
	void editPhone();// main���� �� �Ŷ� public
	string getPnum();//���ڿ��� return�� ����->string
	string getName();
};
