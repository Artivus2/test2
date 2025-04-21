//#include <iostream>
//using namespace std;
//
//unsigned long Fact(long int N)
//{
//	if (N < 1) return 0;
//
//	else if (N == 1) return 1;
//
//	else return N * Fact(N - 1);
//}
//
//long int Fact2(long int N)
//{
//	long int F = 1;
//	// цикл осуществляет подсчет факториала
//	for (int i = 2; i <= N; i++)
//		F *= i;
//	return F;
//}
//
//int main() {
//	long number = 20;
//	// первый вызов рекурсивной функции
//	unsigned long result = Fact(number);
//	cout << "Result " << number << "! is - " << result << "\n";
//	long result2 = Fact2(number);
//	cout << "Result " << number << "! is - " << result2 << "\n";
//	return 0;
//}


//
//using namespace std;
//
//template <class T>
//
//void quickSortR(T a[], long N) {
//	long i = 0, j = N;
//	T temp, p;
//	p = a[N / 2];
//	do {
//		while (a[i] < p) i++;
//		while (a[j] > p) j--;
//		if (i <= j) {
//			temp = a[i];
//			a[i] = a[j];
//			a[j] = temp;
//			i++;
//			j--;
//		}
//	} while (i <= j);
//	if (j > 0) quickSortR(a, j);
//	if (N > i) quickSortR(a + i, N - i);
//
//}
//
//int main() {
//	srand(time(NULL));
//	const long SIZE = 100000;
//	int ar[SIZE], c[SIZE];
//	// до сортировки
//	for (int i = 0;i < SIZE;i++) {
//		ar[i] = rand() % 100;
//		c[i] = ar[i];
//		//cout << ar[i] << " ";
//	}
//	cout << "\n\n";
//	SYSTEMTIME st;
//
//	GetLocalTime(&st);
//	double time_start1 = st.wSecond * 1000 + st.wMilliseconds;
//	cout << "timstart1" << time_start1 << endl;
//	quickSortR(ar, SIZE - 1);
//	
//	GetLocalTime(&st);
//	double time_end1 = st.wSecond * 1000 + st.wMilliseconds;
//	cout << "timend1" << time_end1 << endl;
//	cout << "\nElapsed time1: " << time_end1 - time_start1<<endl;
//	/*for (int i = 0;i < SIZE;i++) {
//		cout << ar[i] << " ";
//	}*/
//	cout << "\n\n";
//
//	int temp, k;
//	GetLocalTime(&st);
//	double time_start2 = st.wSecond * 1000 + st.wMilliseconds;
//	cout << "timstart2" << time_start2 << endl;
//	for (int i = 0; i < SIZE; i++) {
//		k = i;
//		temp = c[i];
//		for (int j = i + 1; j < SIZE; j++) {
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
//	GetLocalTime(&st);
//	double time_end2 = st.wSecond * 1000 + st.wMilliseconds;
//	cout << "timend2" << time_end2 << endl;
//	cout << "\nElapsed time2: " << time_end2 - time_start2 << endl;
//	/*for (int i = 0;i < SIZE;i++) {
//		cout << c[i] << " ";
//	}*/
//	cout << "\n\n";
//
//	return 0;
//}

#include <iostream>
#include <windows.h> 
#include <string>
#include <stdlib.h>
#include <time.h>
#include <chrono>

using namespace std;

int pow1(int x, int a) {
	
	cout << a << " " << x << endl;
	//a -= 1;
	if (a == 1) return x;
	return x*pow1(x, a - 1);
}

int main_19() {
	int x = 3;
	int a = 4;
	long result = pow1(x, a);
	cout << result << endl;
	
	return 0;
}