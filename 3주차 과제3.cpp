#include <iostream>
using namespace std;

void print(int* arr)
{
	for (int i = 0; i < 5; i++)
	{
		cout << i + 1 << ". " << arr[i];
		cout << endl;
	}
}

void sort(int* arr)
{
	for (int j = 0; j < 5; j++)
	{
		for (int i = 0; i <4; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				int tmp;
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
			}
		}
	}
}


int main()
{
	cout << "���� �ټ����� �Է��� �ּ���(����� ����) >>";
	int arr[5];
	for (int i=0; i < 5; i++)
	{
		cin >> arr[i];
	}
	cout << "<���� ��>" << endl << endl;
	print(arr);
	sort(arr);
	cout << endl;
	cout << "<���� ��>" << endl << endl;
	print(arr);



}

