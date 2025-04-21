#include <iostream>
#include <windows.h> 
#include <string>
#include <stdlib.h>
#include <time.h>
#include <chrono>
using namespace std;

int main_14() {

	system("chcp 1251");
	srand(time(NULL));
	//const int x = 5, y = 10;
	//int a[x][y];

	//for (int i = 0; i < size1; i++) {
	//	
	//	a[i][1] = 1 + rand() % (2000);
	//	a[i][3] = 1 + rand() % (2000);
	//	//cout << a[i][1] << "(" << i << "), ";
	//}

	/*int b[x] = {};
	for (int i = 0; i < size1; i++) {
		for (int j = 0; j < size1; j++) {
			a[i][j] = 1 + rand() % (2000);
			cout << a[i][j] << "(" << i << "," << j << ",) ";
			if (a[i][j] < b[i]) {
				b[i] = a[i][j];
			}
		}
		cout << "max: " << b[i] << endl;
	}
	*/
	/*int temp = 0;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			a[i][j] = 100 + rand() % (899);
			if (i == j || j > i) {
				cout << a[i][j] << " ";
				if (a[i][j] > temp) {
					temp = a[i][j];
				}
			}
			else cout << "    ";
		}
		cout << endl;
	}
	cout << "Max: " << temp;
	cout << endl;*/


	/*const int x = 5, y = 10;
	int a[x][y], b[x][x] = {};

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			a[i][j] =rand() % (50);
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}
	
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < x; j++) {
			b[i][j] = a[i][j * 2] + a[i][j * 2 + 1];
			cout << b[i][j] << "\t";
		}
		cout << endl;
	}*/
	const int size1 = 30;
	int ar1[size1];
	int temp(0);
	int i,j,k;

	
	for (i = 0; i < size1; i++) {
		ar1[i] = -1000 + rand() % (3000);
		cout << ar1[i] << " ";
	}

	double mid(0), sum(0);
	for (i = 0; i < size1; i++) {
		sum += ar1[i];
	}

	mid = sum / size1;
	int b;
	cout << "Среднее арифметическое: " << mid;
	if (mid > 0) {
		b = size1 / 3 * 2;
	}
	else {
		b = size1  / 3;
	}

	for (int i = 0; i < b; i++) {
		k = i;
		temp = ar1[i];
		for (int j = i + 1; j < b; j++) {

			if (ar1[j] < temp) {
				k = j;
				temp = ar1[j];
			}
		}
		
		if (k != i) {
			ar1[k] = ar1[i];
			ar1[i] = temp;
		}
		
	}

	cout << endl;
	for (int i = 0; i < size1; i++) {
		cout << ar1[i] << "   ";
	}

	return 0;
}