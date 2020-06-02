#include <iostream>
#include <cstdlib>//RAND_MAX에 매크로로 작성(0~32767)
#include <ctime>
using namespace std;

class Random {
public:
	Random();
	int next();
	int nextlnRange(int x, int y);//2,4입력받을 거니까 인수2개!
};

Random::Random() {//무작위로 나오게끔 만드는 공간
	srand((unsigned int)time(NULL)); //ctime 헤더에 포함, 진짜 랜덤 값 나오게 하기 위해, 안 그러면 일정한 랜덤값 나옴.
}

int Random::next() {
	
		return rand() % RAND_MAX;//0~32767이 return된다.
}
int Random::nextlnRange(int x, int y) {
	return 2 + rand() % (y - x + 1);//rand()%(4-2+1) -> rand()%3 -> 0,1,2을 뱉는다. 2~4가 필요하므로 앞에 +2 해준다.
}

int main() {
	cout << "--0에서 " << RAND_MAX << "까지의 랜덤 정수 10개--" << endl; //<cstdlib>에 들어있는 RAND_MAX의 값은 32767이다.
	Random next0;//함수 next와 다름, class 안에 있는 함수들을 쓰기 위해 생성자를 호출한 것.
	for (int i = 0; i < 10; i++) {//10번 출력한다.
		int random = next0.next();//반복할 때마다 새로 받기 때문에 값이 매번 다르게 나온다.
		cout << random<< " ";// 해당 함수에서 나오는 return값을 10번 반복한다. (return될 때마다 값이 다르다)
	}
		
	cout << endl << endl;
	int x, y;//범위 받을 변수
	cout << "==2에서 4까지의 랜덤 정수 10개==" << endl;
	for (int i = 0; i < 10; i++) {
		int random = next0.nextlnRange(2,4);// 앞에서 쓴 next0 생성자 같이 써도 되고 새로 만들어도 된다.
		cout << random<<" ";
	}

}
