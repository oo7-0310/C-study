#include <iostream>
#include <string>
using namespace std;

int main()
{
	char name[100], birth[100], age[100], major[100];

	cout << "�̸��� �Է��ϼ���:";
	cin >> name;
	while(getchar() != '\n');//buffer error 
	cout << "������ �Է��ϼ���:";
	cin.getline(birth, 100); 
	cout << "���̸� �Է��ϼ���:";
	cin >> age;
	cout << "�а��� �Է��ϼ���:";
	cin >> major;

	cout << "==============================================" << endl;
	cout << "<ȸ�� ����>"<< endl;
	cout << "�̸�: " << name <<endl;
	cout << "����: " << birth << endl;
	cout << "����: " << age << endl;
	cout << "�а�: " << major << endl;

	return 0;
	
}