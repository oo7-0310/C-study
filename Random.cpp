#include <iostream>
#include <cstdlib>//RAND_MAX에 매크로로 작성(0~32767)
#include <ctime>
using namespace std;

#include "Random.h"//선언부 들어있는 헤드파일을 include

// Random 클래스 구현부

Random::Random() {//무작위로 나오게끔 만드는 공간
	srand((unsigned int)time(NULL)); //ctime 헤더에 포함, 진짜 랜덤 값 나오게 하기 위해, 안 그러면 일정한 랜덤값 나옴.
}

int Random::next() {

	return rand() % RAND_MAX;//0~32767이 return된다.
}
int Random::nextlnRange(int x, int y) {
	return 2 + rand() % (y - x + 1);//rand()%(4-2+1) -> rand()%3 -> 0,1,2을 뱉는다. 2~4가 필요하므로 앞에 +2 해준다.
}