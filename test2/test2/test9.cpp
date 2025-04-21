
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
	//for (;;) { // реализация бесконечного цикла
	//	cout << "Enter digit:";
	//	cin >> digit; // ввод числа
	//	if (digit == 0) // если введен 0
	//		break; // остановить цикл
	//	sum += digit; // накопление суммы

	//	cout << "число: " << digit;
	//	
	//}
	//// показ результата
	//cout << "Sum of digits" << sum << "\n\n";

	//int digit;
	//cout << "Enter digit:";
	//cin >> digit;
	//// цикл перебирает числа от 2 до введенного числа
	//for (int i = 2; i < digit; i++) {
	//	// если число не делится на текущее значение i
	//	// без остатка остановить данный шаг и перейти
	//	// к следующему
	//	if (digit % i != 0) continue;
	//	// показать i на экран
	//	cout << i << " ";
	//}
	//cout << endl << endl;

	/*int a, b, x;

	do {
		cout << "МИН ";
		cin >> a;
		cout << "МАКС ";
		cin >> b;
		cout << "Число ";
		cin >> x;

	} while (!(x >= a && x <= b));
	cout << "Все";*/
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
	(count % 2 == 0) ? cout << "Положительное" : cout << "Отрицательное";*/
	return 0;
}