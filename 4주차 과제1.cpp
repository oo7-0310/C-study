#include <iostream>
#include <cstdlib>//RAND_MAX�� ��ũ�η� �ۼ�(0~32767)
#include <ctime>
using namespace std;

class Random {
public:
	Random();
	int next();
	int nextlnRange(int x, int y);//2,4�Է¹��� �Ŵϱ� �μ�2��!
};

Random::Random() {//�������� �����Բ� ����� ����
	srand((unsigned int)time(NULL)); //ctime ����� ����, ��¥ ���� �� ������ �ϱ� ����, �� �׷��� ������ ������ ����.
}

int Random::next() {
	
		return rand() % RAND_MAX;//0~32767�� return�ȴ�.
}
int Random::nextlnRange(int x, int y) {
	return 2 + rand() % (y - x + 1);//rand()%(4-2+1) -> rand()%3 -> 0,1,2�� ��´�. 2~4�� �ʿ��ϹǷ� �տ� +2 ���ش�.
}

int main() {
	cout << "--0���� " << RAND_MAX << "������ ���� ���� 10��--" << endl; //<cstdlib>�� ����ִ� RAND_MAX�� ���� 32767�̴�.
	Random next0;//�Լ� next�� �ٸ�, class �ȿ� �ִ� �Լ����� ���� ���� �����ڸ� ȣ���� ��.
	for (int i = 0; i < 10; i++) {//10�� ����Ѵ�.
		int random = next0.next();//�ݺ��� ������ ���� �ޱ� ������ ���� �Ź� �ٸ��� ���´�.
		cout << random<< " ";// �ش� �Լ����� ������ return���� 10�� �ݺ��Ѵ�. (return�� ������ ���� �ٸ���)
	}
		
	cout << endl << endl;
	int x, y;//���� ���� ����
	cout << "==2���� 4������ ���� ���� 10��==" << endl;
	for (int i = 0; i < 10; i++) {
		int random = next0.nextlnRange(2,4);// �տ��� �� next0 ������ ���� �ᵵ �ǰ� ���� ���� �ȴ�.
		cout << random<<" ";
	}

}
