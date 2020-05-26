#include <iostream>
using namespace std;

void swap(int *x, int *y);

int main()
{
	int x, y;
	cout << "first number >> ";
	cin >> x;

	cout << "second number >> ";
	cin >> y;

	int* xp = &x;
	int* yp = &y;

	cout << "swap Àü >>" << x << " " << y << endl;

	swap(xp, yp);

	cout << "swap ÈÄ >>" << x << " " << y << endl;


	return 0;
}

void swap(int *x, int *y)
{
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;

}

