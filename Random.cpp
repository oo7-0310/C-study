#include <iostream>
#include <cstdlib>//RAND_MAX�� ��ũ�η� �ۼ�(0~32767)
#include <ctime>
using namespace std;

#include "Random.h"//����� ����ִ� ��������� include

// Random Ŭ���� ������

Random::Random() {//�������� �����Բ� ����� ����
	srand((unsigned int)time(NULL)); //ctime ����� ����, ��¥ ���� �� ������ �ϱ� ����, �� �׷��� ������ ������ ����.
}

int Random::next() {

	return rand() % RAND_MAX;//0~32767�� return�ȴ�.
}
int Random::nextlnRange(int x, int y) {
	return 2 + rand() % (y - x + 1);//rand()%(4-2+1) -> rand()%3 -> 0,1,2�� ��´�. 2~4�� �ʿ��ϹǷ� �տ� +2 ���ش�.
}