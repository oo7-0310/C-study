#include <iostream>
using namespace std;

int main()
{
	int n1, n2; //정수형으로 숫자1,2 선언
	cout << "First number>>";
	cin >> n1;
	cout << "Second nmber>>";
	cin >> n2;
	cout << endl;
	cout << "==========계산 결과===========" << endl;
	cout << n1 << "+" << n2 << "= " << n1 + n2 << endl;
	cout << n1 << "-" << n2 << "= " << n1 - n2 << endl;
	cout << n1 << "*" << n2 << "= " << n1 * n2 << endl;
	cout << n1 << "/" << n2 << "= " << (float)n1 / (float)n2 << endl;//형변환을 해주지 않으면 정수로 계산됨
	
	return 0;
}