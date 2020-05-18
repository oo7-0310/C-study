#include <iostream>
using namespace std;//cout,cin 쓰기 위해

int main()
{
	int list[5];//숫자를 5번 입력받는다
	int count1=0;//홀수 개수
	int count2=0;//짝수 개수
	

	for (int i = 0; i < 5; i++)
	{
		cout << "숫자를 입력해주세요:";
		cin >> list[i];//배열로 받아준다
	}
	cout << endl;
	cout << "-----------결과------------" << endl;


	cout << "홀수: ";
	for (int i = 0; i < 5; i++)//5번 반복
	{
		if (list[i] % 2 == 1)//나머지가 1, 즉 홀수일 경우
		{
			cout << list[i] << " ";//바로 출력
			count1++;//반복문을 돌며 홀수일 경우에 하나씩 증가한다
		}
	}
	cout << endl;
	cout << "홀수는 총 " << count1 << "개 입니다." << endl;
	cout << endl << endl;

	cout << "짝수: ";
	for (int i = 0; i < 5; i++)//다섯번 반복
	{
		if (list[i] % 2 != 1)//나머지가 1일 아닐 경우 즉, 짝수
		{
			cout << list[i] << " ";//바로 출력
			count2++;//짝수 개수 하나씩 증가
		}
	}
	cout << endl;
	cout << "짝수는 총 " << count2 << "개 입니다." << endl;
	cout << endl;



}