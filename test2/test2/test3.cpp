#include <iostream>
#include <windows.h> 
#include <math.h> 

using namespace std;
HANDLE hConsole2 = GetStdHandle(STD_OUTPUT_HANDLE);
int main_3()
{
	system("chcp 1251");
	
	float A, B, RES;
	cout << "Enter first digit:\n";
	cin >> A;
	cout << "Enter second digit:\n";
	cin >> B;
	char key;
	cin >> key;
	
		switch (key) {
		case '+': // если пользователь выбрал сложение 
			RES = A + B;
			cout << "\nAnswer: " << RES << "\n";
			break; // parada do switch
		case '-': // если пользователь выбрал сложение 
			RES = A + B;
			cout << "\nAnswer: " << RES << "\n";
			break; // parada do switch
		case 27:
			cout << "\nЌажат ESCAPE";
			break;
		}
	



	return 0;
		

	
}