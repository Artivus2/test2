
#include <iostream>
#include <windows.h> 

using namespace std;

HANDLE hConsole4 = GetStdHandle(STD_OUTPUT_HANDLE);
int main_4()
{
    /*Входными данными являются :
    Емкость аккумулятора смартфона(мАч.) – > 3000
        ––––––––––––––––––––––––––––
        Выходные данные :
    Минимальная емкость : 9000 мАч.*/

    system("chcp 1251");
    SetConsoleTextAttribute(hConsole4, 10);
    float min_volume;
    cout << "Емкость аккумулятора смартфона(мАч.) – > ";
    cin >> min_volume;
    string line(20, '-');
    cout << "Выходные данные :";
    cout << "Минимальная емкость : " << min_volume * 3;




    return 0;
}


