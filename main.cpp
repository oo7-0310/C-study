#include <iostream>
using namespace std;

#include "Random.h"//����� ����ִ� ��������� include

int main() {
	cout << "--0���� " << RAND_MAX << "������ ���� ���� 10��--" << endl; //<cstdlib>�� ����ִ� RAND_MAX�� ���� 32767�̴�.
	Random next0;//�Լ� next�� �ٸ�, class �ȿ� �ִ� �Լ����� ���� ���� �����ڸ� ȣ���� ��.
	for (int i = 0; i < 10; i++) {//10�� ����Ѵ�.
		int random = next0.next();//�ݺ��� ������ ���� �ޱ� ������ ���� �Ź� �ٸ��� ���´�.
		cout << random << " ";// �ش� �Լ����� ������ return���� 10�� �ݺ��Ѵ�. (return�� ������ ���� �ٸ���)
	}

	cout << endl << endl;
	int x, y;//���� ���� ����
	cout << "==2���� 4������ ���� ���� 10��==" << endl;
	for (int i = 0; i < 10; i++) {
		int random = next0.nextlnRange(2, 4);// �տ��� �� next0 ������ ���� �ᵵ �ǰ� ���� ���� �ȴ�.
		cout << random << " ";
	}

}