#include <iostream>
using namespace std;

int main()
{
	int n1, n2; //���������� ����1,2 ����
	cout << "First number>>";
	cin >> n1;
	cout << "Second nmber>>";
	cin >> n2;
	cout << endl;
	cout << "==========��� ���===========" << endl;
	cout << n1 << "+" << n2 << "= " << n1 + n2 << endl;
	cout << n1 << "-" << n2 << "= " << n1 - n2 << endl;
	cout << n1 << "*" << n2 << "= " << n1 * n2 << endl;
	cout << n1 << "/" << n2 << "= " << (float)n1 / (float)n2 << endl;//����ȯ�� ������ ������ ������ ����
	
	return 0;
}