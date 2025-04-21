#include <iostream>
#include <windows.h> 
#include <string>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <iomanip>


using namespace std;
const int SIZE1 = 5;



//template <typename T1, typename T2> double func(T1 a, T2 b) {
//	//cout << "число: " << a << " . " << b;
//	int rez1(0);
//	rez1 = pow(10, b);
//	cout << round(a * rez1) / rez1 << endl;
//	return round(a * rez1) / rez1;
//}
//
//template <typename T> double func(T a, T b, T c) {
//	double x1(0), x2(0);
//	double d = (b / 2) * (b / 2) - a * c;
//	if (d > 0) {
//		x1 = ((-b / 2) - sqrt(d)) / a;
//		x2 = ((-b / 2) + sqrt(d)) / a;
//		cout << "x1:" << x1 << ",   x2: " << x2;
//	}
//	else {
//		cout << "Ответов нет: ";
//	}
//	
//	return x1, x2;
//}
//template <typename T1> double AVG(T1 A[]) {
//	
//	float result(0);
//	for (int i = 0; i < SIZE1; i++) {
//		result += A[i];
//	}
//	cout << endl;
//	
//	return result / SIZE1;
//}
//
//int main() {
//	float res1;
//	
//	system("chcp 1251");
//	srand(time(NULL));
//	double arr[SIZE1];
//	for (int i = 0; i < SIZE1; i++) {
//		
//		arr[i] = 1 + rand() % (1000);
//		
//		cout << arr[i] << " ";
//	}
//
//	res1 = AVG(arr);
//
//	cout << "Средне:" << res1 << endl;
	
template <typename T> double Max2(T a, T b) {
	//максимум из двух 
}

template <typename T> double Max2(T a, T b, T c) {
	//максимум ИЗ трех чисел
}

template <typename T> double Max(T Ar[], T x, T y, T z) {
	//максимум
	int temp(0);
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			for (int k = 0; k < z; z++) {
				if (temp < Ar[x][y][z]) temp = Ar[x][y][z];
			}
		}
	}
}


int main_16() {

	system("chcp 1251");
	int a, b, c;

	//cout << func(1, 2) << endl;

	//cout << "число: " << setprecision(8) << func(0.3222332, 6);

	return 0;

	

}