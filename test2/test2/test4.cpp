
#include <iostream>
#include <windows.h> 

using namespace std;

HANDLE hConsole4 = GetStdHandle(STD_OUTPUT_HANDLE);
int main_4()
{
    /*�������� ������� �������� :
    ������� ������������ ���������(���.) � > 3000
        ����������������������������
        �������� ������ :
    ����������� ������� : 9000 ���.*/

    system("chcp 1251");
    SetConsoleTextAttribute(hConsole4, 10);
    float min_volume;
    cout << "������� ������������ ���������(���.) � > ";
    cin >> min_volume;
    string line(20, '-');
    cout << "�������� ������ :";
    cout << "����������� ������� : " << min_volume * 3;




    return 0;
}


