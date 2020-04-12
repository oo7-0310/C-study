#include <iostream>
#include <string>
using namespace std;

int main()
{
	char name[100], birth[100], age[100], major[100];

	cout << "이름을 입력하세요:";
	cin >> name;
	while(getchar() != '\n');//buffer error 
	cout << "생일을 입력하세요:";
	cin.getline(birth, 100); 
	cout << "나이를 입력하세요:";
	cin >> age;
	cout << "학과를 입력하세요:";
	cin >> major;

	cout << "==============================================" << endl;
	cout << "<회원 정보>"<< endl;
	cout << "이름: " << name <<endl;
	cout << "생일: " << birth << endl;
	cout << "나이: " << age << endl;
	cout << "학과: " << major << endl;

	return 0;
	
}