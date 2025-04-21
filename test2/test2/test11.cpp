
#include <iostream>
#include <windows.h> 
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;

HANDLE hConsole11 = GetStdHandle(STD_OUTPUT_HANDLE);


int main_11() {

	system("chcp 1251");
	SetConsoleTextAttribute(hConsole11, 4);
	/*int a, a1, a2, b, result;
	float c1(0), c2(0);

	srand(time(NULL));
	a = 1;
	b = 10;

	do {
		a1 = a + rand() % (b - a);
		a2 = a + rand() % (b - a);
		cout << a1 << " * " << a2 << endl;
		cout << "¬ведите ответ: \n";
		cin >> result;
		if (result != 0) {
			if (a1 * a2 != result) {
				cout << "ќтвет не верный: \n";
				c1++;
			}
			else {
				cout << "ќтвет верный: \n";
				c2++;
			}
		}

	} while (result != 0);
	cout << "\n% ответов " << c2 / (c1 + c2) * 100;
	*/

	char s('+');
	int a = 30, b = 14;
	
	for (int i = 1; i <= b; i++) {
		for (int j = 1; j <= a; j++) {
			Sleep(10);
			if (i == 1 || i == b) cout << s;
			else if (j == 1 || j == a) cout << s; 
			else cout << " ";
		}
		cout << endl;
	}
	return 0;
}