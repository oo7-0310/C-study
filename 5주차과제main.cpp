#include <iostream>
#include <string.h>
#include "5주차과제class.h"
using namespace std;


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
			cout << phnum.getName();//해당 함수에서 return 했던 값을 출력한다.
			cout << "::";
			cout << phnum.getPnum();//그냥 return하면 값 출력 안한다. 반드시 cout 쓰기
			cout << endl;
			continue; //1,,2,3중에 다시 고를 수 있도록 반복문 다시 실행
		}

		if (n == 2) {
			phnum.editPhone();//전화번호를 수정하는 함수이다.
			continue;
		}

		if (n == 3) {
			exit(1);//반복 끝내고 아예 종료한다.
		}
	}
}