
#include <iostream>
#include <windows.h> 
#include <string>
#include <stdlib.h>
using namespace std;



int main_9() {

	system("chcp 1251");

	/*int sum(0);

	for (int i = 1; i <= 12; i++) {
		sum += i;
	}
	cout << sum;*/


	//int digit, sum = 0;
	//for (;;) { // ���������� ������������ �����
	//	cout << "Enter digit:";
	//	cin >> digit; // ���� �����
	//	if (digit == 0) // ���� ������ 0
	//		break; // ���������� ����
	//	sum += digit; // ���������� �����

	//	cout << "�����: " << digit;
	//	
	//}
	//// ����� ����������
	//cout << "Sum of digits" << sum << "\n\n";

	//int digit;
	//cout << "Enter digit:";
	//cin >> digit;
	//// ���� ���������� ����� �� 2 �� ���������� �����
	//for (int i = 2; i < digit; i++) {
	//	// ���� ����� �� ������� �� ������� �������� i
	//	// ��� ������� ���������� ������ ��� � �������
	//	// � ����������
	//	if (digit % i != 0) continue;
	//	// �������� i �� �����
	//	cout << i << " ";
	//}
	//cout << endl << endl;

	/*int a, b, x;

	do {
		cout << "��� ";
		cin >> a;
		cout << "���� ";
		cin >> b;
		cout << "����� ";
		cin >> x;

	} while (!(x >= a && x <= b));
	cout << "���";*/
	/*string number, rez, rev;
	int itog;
	cin >> number;
	for (int i = 0; i <= number.length(); i++) {
		string rez{ number[number.length() - i] };
		rev += stoi(rez);
	}
	cout << rev;*/
	/*int number;
	cin >> number;*/
	//res1 = (int)(number[0] - '0'
	
	//string number, rez, rev;
	//int itog = 0;
	//cin >> number;
	//for (int i = 0; i < number.length(); i++) {
	//	itog += (int)number[i] - '0';
	//	//cout << (int)number[i] << " ";
	//	
	//}
	//cout << itog;
	

	/*int ul = 15;
	int step = -2;
	int n, itog = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		step += 2;
		itog += ul + step;
	}
	cout << itog;*/


	/*int moneta;
	int count = 0;
	for (int i = 1; i <= 9; i++) {
		cin >> moneta;
		if (moneta == 1) count++;
	}
	(count % 2 == 0) ? cout << "�������������" : cout << "�������������";*/
	return 0;
}