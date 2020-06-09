#include <iostream>
using namespace std;

#include "Random.h"//선언부 들어있는 헤더파일을 include

int main() {
	cout << "--0에서 " << RAND_MAX << "까지의 랜덤 정수 10개--" << endl; //<cstdlib>에 들어있는 RAND_MAX의 값은 32767이다.
	Random next0;//함수 next와 다름, class 안에 있는 함수들을 쓰기 위해 생성자를 호출한 것.
	for (int i = 0; i < 10; i++) {//10번 출력한다.
		int random = next0.next();//반복할 때마다 새로 받기 때문에 값이 매번 다르게 나온다.
		cout << random << " ";// 해당 함수에서 나오는 return값을 10번 반복한다. (return될 때마다 값이 다르다)
	}

	cout << endl << endl;
	int x, y;//범위 받을 변수
	cout << "==2에서 4까지의 랜덤 정수 10개==" << endl;
	for (int i = 0; i < 10; i++) {
		int random = next0.nextlnRange(2, 4);// 앞에서 쓴 next0 생성자 같이 써도 되고 새로 만들어도 된다.
		cout << random << " ";
	}

}