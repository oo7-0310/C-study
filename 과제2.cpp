#include <iostream>
using namespace std;

int main()
{
	int shape;
	cout << "----------별 찍기 시스템------------" << endl;
	cout << "만들고 싶은 모양을 선택해주세요." << endl;
	cout << "1.직각삼각형" << endl;
	cout << "2.정삼각형" << endl;
	cout << "3.나비" << endl;
	cout << "4.나가기" << endl;
	cin >> shape;
	cout << endl << endl;
	
	if (shape == 1)
	{
		int num;
		cout << "직각삼각형을 선택하였습니다." << endl;
		cout << "행의 개수를 선택해주세요." << endl;
		cin >> num;
		cout << endl;

		for (int i = 0; i < num; i++)
		{
			for (int j = 0; j < num-i ; j++)
				cout << " ";
			for (int k = 0; k <= i; k++)
				cout << "*";
			cout << endl;
		}

		cout << endl;

		for (int i = 0; i < num; i++)
		{
			for (int j = num; j > i; j--)
				cout << "*";
			cout << endl;
		}

		cout << endl;

		for (int i = 0; i < num; i++)
		{
			for (int j = 0; j < i; j++)
				cout << " ";
			for (int j = num; j > i; j--)
				cout << "*";
			cout << endl;

		}

		cout << endl;


	}

	if (shape == 2)
	{
		int num;
		cout << "정삼각형을 선택하였습니다." << endl;
		cout << "행의 개수를 선택해주세요." << endl;
		cin >> num;
		cout << endl;

		for (int i = 0; i < num; i++)
		{
			for (int j = num - 1; j > i; j--)
				cout << " ";
			for (int k = 0; k < (2 * i + 1); k++)
				cout << "*";
			
			cout << endl;
		}

		cout << endl;


	}

	if (shape == 3)
	{
		int num;
		cout << "나비를 선택하였습니다." << endl;
		do{
			cout << "행의 개수를 선택해주세요." << endl;
			cin >> num;
		} while (num % 2 == 0);
		
		for (int i = 0; i < (num / 2)+1; i++)
		{
			for (int j = 0; j < i; j++)
				cout << "*";
			for (int k = 0; k < num - (2 * i); k++)
				cout << " ";
			for (int j = 0; j < i; j++)
				cout << "*";
			cout << endl;
		}
		for (int i = 0; i < num; i++)
			cout << "*";
		cout << endl;
		for (int i = 0; i < (num / 2) + 1; i++)
		{
			for (int j = num/2; j >i; j--)
				cout << "*";
			for (int j = 0; j < 2 * i + 1 ; j++)
				cout << " ";
			for (int j = num / 2; j > i; j--)
				cout << "*";
			cout << endl;
		}

	}

	if (shape == 4)
	{
		cout << "나가기를 선택하셨습니다." << endl;
		cout << "감사합니다." << endl;
	}
	cout << endl;
	
}