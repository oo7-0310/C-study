#include <iostream>
using namespace std;

int main()
{
	while (1) {
		int shape;
		cout << "----------별 찍기 시스템------------" << endl;
		cout << "만들고 싶은 모양을 선택해주세요." << endl;
		cout << "1.직각삼각형" << endl;
		cout << "2.정삼각형" << endl;
		cout << "3.나비" << endl;
		cout << "4.나가기" << endl;
		cin >> shape; //1~4중 번호 받기
		cout << endl << endl;

		if (shape == 1)//직각삼각형을 택할 경우
		{
			int num;
			cout << "직각삼각형을 선택하였습니다." << endl;
			cout << "행의 개수를 선택해주세요." << endl;
			cin >> num;
			cout << endl;

			for (int i = 0; i < num; i++)//행의 개수만큼 반복
			{
				for (int j = 0; j < num - i; j++)//i가 하나씩 늘어나므로 j는 하나씩 줄어든다.
					cout << " ";
				for (int k = 0; k <= i; k++)//i가 늘어남에 따라 빈칸 옆에 별이 하나씩 늘어난다.
					cout << "*";
				cout << endl;
			}

			cout << endl;

			for (int i = 0; i < num; i++)
			{
				for (int j = num; j > i; j--)//--는 역순
					cout << "*";
				cout << endl;
			}

			cout << endl;

			for (int i = 0; i < num; i++)
			{
				for (int j = 0; j < i; j++)//빈칸 0부터 시작해서 num개까지 만들어진다.
					cout << " ";
				for (int j = num; j > i; j--)//num개부터1개까지 하나씩 감소
					cout << "*";
				cout << endl;

			}

			cout << endl;

			continue;
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
				for (int j = num - 1; j > i; j--)//별 앞에 하나씩 줄어드는 빈칸
					cout << " ";
				for (int k = 0; k < (2 * i + 1); k++)//별의 개수가 2개씩 늘어난다.
					cout << "*";

				cout << endl;
			}

			cout << endl;
			continue;

		}

		if (shape == 3)
		{
			int num;
			cout << "나비를 선택하였습니다." << endl;
			do {
				cout << "행의 개수를 선택해주세요." << endl;
				cin >> num;
			} while (num % 2 == 0);//짝수이면 다시 반복
			//3등분 한다.
			for (int i = 0; i < (num / 2) + 1; i++)//별 num개가 되기 전까지
			{
				for (int j = 0; j < i; j++)//별은 하나씩 늘어난다.
					cout << "*";
				for (int k = 0; k < num - (2 * i); k++)//빈칸은 2개씩 줄어든다.
					cout << " ";
				for (int j = 0; j < i; j++)//별은 하나씩 늘어난다.
					cout << "*";
				cout << endl;
			}
			for (int i = 0; i < num; i++)//별 num개만큼 출력하고 다음줄로 넘어간다.
				cout << "*";
			cout << endl;
			for (int i = 0; i < (num / 2) + 1; i++)
			{
				for (int j = num / 2; j > i; j--)//num/2개부터 하나씩 줄어든다.
					cout << "*";
				for (int j = 0; j < 2 * i + 1; j++)//1개부터 2개씩 늘어난다.
					cout << " ";
				for (int j = num / 2; j > i; j--)
					cout << "*";
				cout << endl;
			}
			continue;
		}

		if (shape == 4)//나가기 안내문 출력
		{
			cout << "나가기를 선택하셨습니다." << endl;
			cout << "감사합니다." << endl;
			break;
		}
		cout << endl;
	}
}