
#include <iostream>
#include <windows.h> 
#include <string>
#include <stdlib.h>
using namespace std;



int main_5() {

	system("chcp 1251");
	/*int a;
	cin >>a;
	!(a % 2) ? cout << "������" : cout << "�� ������";

	if (!(a % 2)) {
		cout << "������";
	}
	else {
		cout << "�� ������";
	}*/
	
	/*string b;

	cin >> b;

	cout << "�����: "<<b.length() << ", ����� ���� �����: " << (int)(b[0] - '0' + b[1] - '0');*/

	/*int a;
	float b, result;
	cout << "1: �� -> ����, 2: ���� � ��\n";
	cin >> a;
	cout << "������� �����: ";
	cin >> b;
	(a == 1) ? cout << "��������: " << b / INCH << endl : cout << "��������: " << b * INCH << endl;
	return 0;*/

	//2�� * 2048 �� * 1000 4096000000 * 8 = 32768000000
	//10��/�   10*1024*1024  10485760

	/*unsigned int f = 32768000000;
	unsigned int s = 10485760;

	unsigned int cur_seconds = f / s;*/

	//int cur_seconds = 60*60*19 + 60*30 + 45; // 19:30:30 = 19*60*60 + 30*60 + 30 70230

	//int full_time = 60 * 60 * 24; // ���������� ������ � ������

	//int minutes = (cur_seconds / 60) % 60; // ���������� �����
	//int hours = (int)(cur_seconds / 60) / 60; // ���������� �����
	//int seconds = cur_seconds % (hours * 60 * 60 + minutes * 60);

	//int midnight = full_time - cur_seconds;
	//int m_minutes = (midnight / 60) % 60; // ���������� �����
	//int m_hours = (int)(midnight / 60) / 60; // ���������� �����
	//int m_seconds = midnight % (m_hours * 60 * 60 + m_minutes * 60);


	/*cout << hours <<" : " << minutes << " : " << seconds << "\n";*/
	//cout << m_hours << " : " << m_minutes << " : " << m_seconds << "\n";
	int a;
	cin >> a;
	int b;
	cin >> b;

	(a > b) ? cout << "b: " << b << "a: " << a : cout << "a: " << a << "b: " << b;
	return 0;
}