#include <iostream>
using namespace std;

int main()
{
	int i, j;//�ݺ����� �� ���� ����
	for (i = 0; i < 5; i++)//���߹ݺ���(���η� 5��)
	{
		for (j = 0; j <= i; j++)//ù��° �ٿ� 1��, �ι�° �ٿ� 2��
			cout << "*";

		cout << endl;
	}
}