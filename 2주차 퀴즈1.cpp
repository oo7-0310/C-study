#include <iostream>
using namespace std;

int main()
{
	int i, j;//반복문에 쓸 변수 선언
	for (i = 0; i < 5; i++)//이중반복문(세로로 5줄)
	{
		for (j = 0; j <= i; j++)//첫번째 줄에 1개, 두번째 줄에 2개
			cout << "*";

		cout << endl;
	}
}