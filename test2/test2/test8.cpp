
#include <iostream>
#include <windows.h> 
#include <string>
#include <stdlib.h>
using namespace std;



int main_8() {

	system("chcp 1251");
	//int counter = 0, a = 0;
	//while (counter <= 7) // проверка утверждения
	//{
	//	// действие для повторения
	//	// вы увидели ... чудо света
	//	cout << "You seen " << counter <<
	//		" miracle of world!!!\n";
	//	counter++;// изменение управляющей переменной
	//	a = counter;
	//}
	//cout << "Now, you can start your work.\n";
	//int answer, A, B, RES;
	// запрос на выбор операции
	//cout << "\nSelect operation:\n";
	//cout << "\n 1 - if you want to see SUM.\n";
	//cout << "\n 2 - if you want to see DIFFERENCE.\n";
	//cout << "\n 3 - if you want to exit.\n";
	//cin >> answer;
	//while (answer != 3) {
	//	// проверка условия
	//	switch (answer) {
	//		case 1: // если пользователь выбрал
	//			// сложение
	//			cout << "Enter first digit:\n";
	//			cin >> A;
	//			cout << "Enter second digit:\n";
	//			cin >> B;
	//			RES = A + B;
	//			cout << "\nAnswer: " << RES << "\n";
	//			break; // остановка switch
	//		case 2: // если пользователь выбрал
	//			// вычитание
	//			cout << "Enter first digit:\n";
	//			cin >> A;
	//			cout << "Enter second digit:\n";
	//			cin >> B;
	//		
	//			RES = A - B;
	//			cout << "\nAnswer: " << RES << "\n";
	//			break; // остановка switch
	//		case 3: // если пользователь выбрал выход
	//			cout << "\nEXIT!!!\n";
	//			break;
	//		default: // если выбранное действие
	//			// некорректно
	//			cout << "\nError!!! This operator isn’t"
	//				" correct\n";
	//		}

	//}
	//cout << "\nBye. \n";

	//do { // вход в цикл
	//	// запрос на выбор операции
	//	cout << "\nSelect operation:\n";
	//	cout << "\n 1 - if you want to see SUM.\n";
	//	cout << "\n 2 - if you want to see DIFFERENCE.\n";
	//	cout << "\n 3 - if you want to exit.\n";
	//	cin >> answer;
	//	// анализ действия
	//	switch (answer) {
	//	case 1: // если пользователь выбрал сложение
	//		cout << "Enter first digit:\n";
	//		cin >> A;
	//		cout << "Enter second digit:\n";
	//		cin >> B;
	//		RES = A + B;
	//		cout << "\nAnswer: " << RES << "\n";
	//		break; // остановка switch
	//	case 2: // если пользователь выбрал вычитание
	//		cout << "Enter first digit:\n";
	//		cin >> A;
	//		cout << "Enter second digit:\n";
	//		
	//		cin >> B;
	//		RES = A - B;
	//		cout << "\nAnswer: " << RES << "\n";
	//		break; // остановка switch
	//	case 3: // если пользователь выбрал выход
	//		cout << "\nEXIT!!!\n";
	//		break;
	//	default: // если выбранное действие
	//		// некорректно
	//		cout << "\nError!!! This operator isn’t "
	//			"correct\n";
	//	}
	//} while (answer != 3);

	//cout << "\nBye. \n";

	//int BEGIN = 1; // начало диапазона суммируемых
	//// значений
	//int END = 5; // конец диапазона суммируемых
	//// значений
	//int SUMM = 0; // переменная для накопления суммы
	//int i = BEGIN; // управляющая переменная цикла
	//int a = 0;

	// проверка условия
	//while (i <= END && a == -1) {// (сравнение управляющей переменной
	//	// с окончанием диапазона)
	//	SUMM += i; // накапливание суммы
	//	i++; // изменение управляющей переменной
	//};
	//// показ результата
	//cout << "Result " << SUMM << "\n\n";


//string line(5, '\t');
//int COUNT = 1; // количество звездочек (длина линии)
//int COUNT_probel = 40; // количество пробелов (длина линии)
//int count2 = 42;
//int i = 1, j = 0, x; // управляющая переменная цикла
//
//while (j <= count2) {
//	cout << line; // вывод звездочки
//	if (j <= 20) {
//		string line1(j * 2 + 1, '*'); // 41
//		string line2(count2 - j, ' '); // 22
//		cout << line2 << line1 << "\n";
//	}
//	else {
//		string line1((85 - j * 2), '*'); //39 // 22
//		string line2(j, ' ');
//		cout << line2 << line1 << "\n";
//	}
//
//	j++;
//}
//cout << "\n\n";

	/*int a = 10, b = 17;
	int res = 0;
	
	while (a <= b) {
		
		if (a % 2 != 0) {
			res += a;
		}
		a++;
	}

	cout << res;*/


	/*int i = 0, a = 7, res = 0;

	while (i <= a) {
		if (i == 0) {
			res += 1;
		}
		else {
			res *= i;
		}
		i++;
	}

	cout << res;*/

	int i = 0, count = 0, L=1000, P=70;

	while (i < L) {
		L = L - P;
		if (L > i) {
			i++;
			count++;
		}

	}
	cout << count;

	return 0;

}