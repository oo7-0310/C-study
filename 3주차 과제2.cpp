#include <iostream>
using namespace std;

void swap(int* px, int* py)
{
	int tmp;
	tmp = *px;
	*px = *py;
	*py = tmp;

}

int main()
{
	int a, b;

	cout << "first number >> ";
	cin >> a;
	cout << "second number >> ";
	cin >> b;
	cout << "swap �� >> " << a << " " << b << endl;

	swap(&a, &b);

	cout << "swap �� >> " << a << " " << b << endl;
}

