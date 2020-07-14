#include <iostream>
#include <string>
using namespace std;

int main() {
	int n = 0;
	int min=1;
	
	int i, j;
	cin >> n;
	int list[100];
	//int list2[100];
	//int k = 0, m = 0;

	for (int i = 0; i < n; i++) {
		cin >> list[i];
	}

	cout << "=============" << endl;

	for (i = 0; i < n - 1; i++) {
		min = i;
		for (j = i + 1; j < n; j++) {
			if (list[min] > list[j]) {
				min = j;
			}
		}
		swap(list[i], list[min]);

		//copy(list, list + 100, list2);
		//memcmp(list,list2,sizeof(list);
		//list2에 list를 넣고 swap으로 list의 첫번째 자리의 값과 최소값을 바꾼 후 반복문을 돌리면 list와 list2가 다른 배열이므로 반복문을 종료하도록..하고 싶었음..



		for (j = 0; j < n; j++)
			cout << list[j] << " ";
		cout << endl;

	}
	return 0;
}

