#include <iostream>
#include <windows.h> 
#include <string>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <iomanip>

using namespace std;

//void swap(int *a) {
//	int tmp;
//	
//	for (int i = 0; i < 20; i++) {
//		if (i % 2 != 0) {
//			tmp = *(a+i);
//			a[i] = a[i - 1];
//			a[i - 1] = tmp;
//
//		}
//	}
//	
//}
//
//
//int main_18() {
//	system("chcp 1251");
//	srand(time(NULL));
//	int a[20], b[200], c[220];
//	int* ptr = a;
//	int* ptr2 = b;
//	int* ptr3 = c;
//
//	for (int i = 0; i < 20; i++) {
//		ptr[i] = 1 + rand() % (200);
//		cout << a[i] << " ";
//	}
//	for (int i = 0; i < 200; i++) {
//		ptr2[i] = 1 + rand() % (200);
//		cout << b[i] << " ";
//	}
//	for (int j = 0; j < 220; j++) {
//		if (j < 20) {
//			c[j] = a[j];
//		}
//		else {
//			c[j] = b[j-20];
//		}
//	}
//
//
//	int temp, k;
//	for (int i = 0; i < 220; i++) {
//		k = i;
//		temp = c[i];
//		for (int j = i + 1; j < 220; j++) {
//
//			if (c[j] < temp) {
//				k = j;
//				temp = c[j];
//			}
//		}
//
//		if (k != i) {
//			c[k] = c[i];
//			c[i] = temp;
//		}
//
//	}
//
//	//swap(ptr);
//
//	cout << endl; 
//
//	for (int i = 0; i < 220; i++) {
//		cout << ptr3[i] << " ";
//	}
//

int sum(int* a, int* b) {
	
	*a = 12;

	return *a + *b;
}

int main_18() {

	
	int x = 10;
	int* px = nullptr;

	px = &x;

	int y = 5;

	cout << &x << " " << *px << endl;
	cout << sum(&x, &y) << endl;
	cout << &x << " " << *px << endl;

	
	
	//int* ptr = 0;
	//int* ptr = NULL;
	//int* ptr = &x;
	//ptr = &x;
	//cout << *ptr;


	/*
	int* px;
	int* py;
	px = &x;
	cout << px << " " << &x << endl;
	cout << *px << " " << x << endl;
	*px = 99;
	cout << *px << " " << x << endl;
	py = &y;
	cout << py << " " << &y << endl;
	cout << *py << " " << y << endl;
	py = px;
	cout << *px << " " << *py << " " << x << endl << endl;
	*px += 1;
	cout << px << " " << *px;*/
	int a[10]{1,2,3,4,5,6,7,8,9,10};
	int* pa;
	//pa = &a[0];
	//x = *pa;
	pa = a;
	
	cout << pa << " " << pa[1] << " " << *(pa + 2)<< endl;
	//cout << &a[4] <<" " << * (pa+4) << endl;*/
	cout << *pa << endl;
	pa += 1;
	cout << *pa << endl;

	int* ptr = a;
	for (int i = 0; i < 10; i++) {
		cout << *(ptr + i) << " ";
	}

	*(pa + 1) = 55;

	for (int i = 0; i < 10; i++) {
		cout << *(a + i) << " ";
	}

	//for (int i = 0; i < 10; i++) {
	//	cout << ptr[i] << " ";
	//}

	//cout << "Amount of array elements: " <<
	//	GetAmount(ptr) << endl << endl;

	return 0;

}
	
