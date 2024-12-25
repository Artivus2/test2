#include <iostream>
#include <windows.h> 
using namespace std;
HANDLE hConsole2 = GetStdHandle(STD_OUTPUT_HANDLE);
int main_3()
{
	/*Входными данными являются :
	Диагональ телевизора(inch) – > 42
		––––––––––––––––––––––––
		Выходные данные :
	Диагональ телевизора : 107 см.*/
	system("chcp 1251");
	SetConsoleTextAttribute(hConsole2, 10);
	float diag_in_inches;
	cout << "Диагональ телевизора(inch) – > ";
	cin >> diag_in_inches;
	string line(20, '-');
	cout << "     " << line << "\n";
	cout << "      Выходные данные : \n";
	cout << "Диагональ телевизора : " << diag_in_inches * 2.54 << " см.\n";
	return 0;
}