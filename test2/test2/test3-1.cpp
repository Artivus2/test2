
#include <iostream>
#include <windows.h> 
#include <string>
#define PI 3.14159
using namespace std;
HANDLE hConsole3 = GetStdHandle(STD_OUTPUT_HANDLE);

void fun (int a = 10, int b = 20){
	int temp;
	temp = a;
	a = b;
	b = temp;
	cout << "a: " << a << ", b: " << b;

	
}


int main_3_1()
{
	/*int a(1), b(1);
	float c(7.2), result;
	result = a * b * c;
	cout << result;*/
	system("chcp 1251");
	string mystring (" & %$(string with \backslash) & %$");
	//int x(1), y(2), z(4);
	/*bool foo(true);
	bool bar(false);
	int* p = nullptr;*/
	/*x = y = z = 0;
	x++;
	int a, b, c;

	a = 2;
	b = 7;
	c = (a > b) ? a : b;

	cout << c << '\n';

	(int) a = (b = 3, b + 2);

	a = 0;
	b = 3;
	b += 2;
	a = b;
	int i;
	float f(3.14);
	float zzz;
	x = sizeof(double);
	string str1("abcdefgh");
	char str2[] = "12345678";
	cout << str1[4];*/
	
	fun();
	fun(20, 40);
	fun(30, 50);
	
	return 0;
}