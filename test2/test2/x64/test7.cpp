#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;


//enum ConsoleColor
//{
//    Black = 0,
//    Blue = 1,
//    Green = 2,
//    Cyan = 3,
//    Red = 4,
//    Magenta = 5,
//    Brown = 6,
//    LightGray = 7,
//    DarkGray = 8,
//    LightBlue = 9,
//    LightGreen = 10,
//    LightCyan = 11,
//    LightRed = 12,
//    LightMagenta = 13,
//    Yellow = 14,
//    White = 15
//};

// устанавливает цвет текста и подложки в консоли
//void SetColor(int text, int background)
//{
//    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
//    SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
//}

int main_7()
{
    system("chcp 1251");

    /*SetColor(Red, Black);*/

    //double x,result = 1;
    //int y;

    //cout << "введите число: ";
    //cin >> x;
    //cout << "введите степень: ";
    //cin >> y;

    //for (int i = 1; i <= y; i++) {
    //    if (y == 0) {
    //        result = 1;
    //    }
    //    else {
    //        result *= x;
    //    }
    //}
    //cout << "      Result!!!!      " << result << "\n";
    ////x^y
    //cout << "       Hello!!!!      " << pow(8,3);

   /* char a;

    cin >> a;
    cout << "Символ " << (int)a;
        if ((int)(a >= 48 && (int)a <= 57)) {
            cout << "Символ является числом: " << a;
        }
        else if (
            (int)(a == 33) || ((int)a == 44) || ((int)a == 46) || ((int)a == 63)
            ) {
            cout << "Знаки препинания: " << a;
        }

        else if (
            (int)(a >= 65) && ((int)a <= 90) || ((int)a >= 97) && ((int)a <= 122)
            ) {
            cout << "Буквы алфавита: " << a;
        }
        else {
            cout << "Другие символы: " << a;
        }*/


    /*double zp = 50, result1, result2, result3;
    int codes = 100;
    int opozdanie, future_zp;
    int fails = 20;*/

    /*cout << "Введите желаемую зп: ";
    cin >> future_zp;
    cout << "Введите количествто опозданий: ";
    cin >> opozdanie;


    result1 = future_zp * codes / zp + ((int)opozdanie / 3) * fails * codes / zp;

    cout << "Количество строк: " << result1;*/

    //int codes1;
    //cout << "Введите желаемую зп: ";
    //cin >> future_zp; //500
    //cout << "Введите количество строк кода: ";
    //cin >> codes1; //1100

    //// 500 1100кодв 500*2=1000 строк , 1100-1000  /  (int) 100 * zp / codes     / fails

    //result2 = (int)(( codes1 - future_zp * codes / zp ) * zp /codes) / (fails / 3);

    //(result2 > 0) ? cout << result2 : cout << "0";


    //int codes2;
    //cout << "Введите код: ";
    //cin >> codes2; //500
    //cout << "Введите опоздания: ";
    //cin >> opozdanie; //10

    //result3 = zp * codes2 / codes - ((int)opozdanie / 3) * fails;

    //(result3 > 0) ? cout << result3 : cout << "Бесплатно";




    return 0;

}