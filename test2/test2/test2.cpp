
#include <iostream>
#include <windows.h> 
using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
int main_2()
{
    const int n = 15;
    string line(89, '=');
    SetConsoleTextAttribute(hConsole, 10);
    cout << line << "\n";
    cout << "|\tX\t|\tY\t|\tX AND Y \t|\tX OR Y  |\tNOT X   |\n";
    cout << line << "\n";
    SetConsoleTextAttribute(hConsole, 240);
    cout << "|\t0\t|\t0\t|\t0\t\t|\t0\t|\t0\t|\n";
    cout << "|\t0\t|\t1\t|\t0\t\t|\t1\t|\t1\t|\n";
    cout << "|\t1\t|\t0\t|\t0\t\t|\t1\t|\t0\t|\n";
    cout << "|\t1\t|\t1\t|\t1\t\t|\t1\t|\t0\t|\n";
    cout << line << "\n";
    return 0;
}


