
#include <iostream>
#include <windows.h> 
#include <string>
#include <stdlib.h>
using namespace std;



int main_10() {

	system("chcp 1251");

	//int A = 2, B = 1000, count = 0;

	/*for (int i = A; i <= B; i++) {
		cout << "Делители для числа: " << i << " - ";
		for (int j = 1; j <= i; j++) {
			if (i % j == 0) {
				cout << j << " ";
			}
		}
		cout << endl;
	}*/
	/*int A = 2, B = 1000, count = 0;

	for (int i = A; i <= B; i++) {
		count = 0;
		for (int j = 1; j <= i; j++) {
			if (i % j == 0) {
				count++;
			}
			if (count > 2) {
				break;
			}
		}
		if (count == 2) {
			cout << "Простое число: " << i << endl;
		}*/

	//int x(25);

	//for (int i = 0; i < x; ++i) {
	//	for (int j = 0;	j < x; j++)
	//	{
	//		//главная диагональ
	//		if (i == j)
	//			cout << " * ";
	//		else if (i == (int)x / 2) cout << " * ";
	//		else if (j == (int)x / 2) cout << " * ";
	//		//побочная диагональ
	//		else if (j + i == (int)x - 1) 
	//			cout << " * ";
	//		else cout << "   ";
	//	}
	//	
	//	cout << endl;

	int a1, a2, a3, A = 99999, count = 0;

	for (int i = 0; i <= A; i++) {
		
		a1 = i % 10; //3
		a2 = (i / 10) % 10; //4
		a3 = (i / 10) / 10; // 1
		if (a1 != a2 && a2 != a3 && a1 != a3) {
			cout << "Искомые числа: " << i << "\n";
			count++;
		}	
	}
	cout << a3 << ", " << a2 << ", " << a1 << "\nКол-во вариантов: ";
	cout << count << ", секунд: " << count * 3 << " секунд";

	
	return 0;

	


}