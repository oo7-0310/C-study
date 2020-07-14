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



		for (j = 0; j < n; j++)
			cout << list[j] << " ";
		cout << endl;

	}
	return 0;
}

