
#include <iostream>
#include <windows.h> 
#include <string>
#include <stdlib.h>
#include <time.h>
#include <chrono>
using namespace std;

int main_13() {

	system("chcp 1251");
	srand(time(NULL));
	//const unsigned int size1 = 30000;
	//unsigned int ar1[size1], ar2[size1], ar3[size1];
	//long i, j, k;
	//for (i = 0; i < size1; i++) {
	//	ar1[i] = 1 + rand() % (2000);
	//	ar2[i] = ar1[i];
	//	ar3[i] = ar1[i];
	//	/*cout << ar1[i] << "(" << i << "), ";*/
	//}

	//cout << endl;

	////int key = 11;
	////int index;

	///*for (int i = 0; i < 20; i++) {
	//	if (ar[i] == key) {
	//		cout << i << endl;
	//		index = i;
	//		break;
	//	} else { index = 0; }
	//	
	//}*/

	////cout << ar[index] << endl;
	//
	//
	//unsigned int x[size1];
	//unsigned int counter(0);
	// // ���������� ������� �������
	//for (i = 0; i < size1; i++) {
	//	k = i;
	//	x[i] = ar1[i];
	//	// ���� ������ ����������� ��������
	//	for (j = j ; j < size1; j++)
	//		
	//			if (ar1[j] < x[i]) {
	//				k = j;
	//				x[i] = ar1[j];
	//				counter++;
	//				// k - ������ ����������� ��������
	//			}
	//			if (k != i) {
	//				ar1[k] = ar1[i];
	//				ar1[i] = x[i];
	//				// ������ ������� ���������� � a[i]
	//			}
	//		
	//}

	///*for (int i = 0; i < 20; i++) {
	//	cout << ar1[i] << "(" << i << "), ";
	//}
	//cout << "���-�� ��������: " << counter << endl;*/

	//// �����������

	//SYSTEMTIME st;

	//GetLocalTime(&st);
	//double time_start = st.wSecond * 1000 + st.wMilliseconds;
	///*printf("%d-%02d-%02d %02d:%02d:%02d.%03d",
	//	st.wYear,
	//	st.wMonth,
	//	st.wDay,
	//	st.wHour,
	//	st.wMinute,
	//	st.wSecond,
	//	st.wMilliseconds);*/
	//counter = 0;
	//unsigned int temp(0);
	//for (i = 0; i < size1; i++) { // i - ����� �������
	//	for (j = size1 - 1; j > i; j--) { // ���������� ����
	//		// �������
	//		if (ar2[j - 1] > ar2[j]) {
	//			temp = ar2[j - 1];
	//			ar2[j - 1] = ar2[j];
	//			ar2[j] = temp;
	//			counter++;
	//		}
	//	}
	//}
	//GetLocalTime(&st);
	//double time_end = st.wSecond * 1000 + st.wMilliseconds;
	//cout << "Elapsed time: " << time_end - time_start;

	//Sleep(1000);

	//
	//
	//cout << endl;

	///*for (int i = 0; i < 20; i++) {
	//	cout << ar2[i] << "(" << i << "), ";
	//}
	//cout << "���-�� ��������: " << counter << endl;*/
	//GetLocalTime(&st);
	//time_start = st.wSecond * 1000 + st.wMilliseconds;
	//cout << endl;
	//
	//
	//counter = 0;
	//unsigned int temp2(0);
	//for (i = 0; i < size1; i++) {
	//	temp2 = ar3[i];
	//	// ����� ����� �������� � �������
	//	// ������������������
	//	for (j = i - 1; j >= 0 && ar3[j] > temp2; j--) {
	//		// �������� ������� �������,���� �� �����
	//		ar3[j + 1] = ar3[j];
	//		counter++;
	//	}

	//	// ����� �������, �������� �������
	//	ar3[j + 1] = temp2;
	//}
	//GetLocalTime(&st);
	//time_end = st.wSecond * 1000 + st.wMilliseconds;
	//cout << endl;
	//cout << "Elapsed time: " << time_end - time_start;
	///*for (int i = 0; i < 20; i++) {
	//	cout << ar3[i] << "(" << i << "), ";
	//}
	//cout << "���-�� ��������: " << counter << endl;*/
	return 0;
}