#include <iostream>
#include <string>
#include <vector> 

using namespace std;

string removeChar(const string& str, int index) {
    // ���������, ��� ������ ��������� � ���������� ���������
    if (index < 0 || index >= str.length()) {
        // ���������� �������� ������, ���� ������ �����������
        return str;
    }

    // ������� ����� ������, �������� ������ � �������� ��������
    string result = str.substr(0, index) + str.substr(index + 1);
    return result;
}

int main_25() {
    string myString = "Hello, world!";
    int indexToRemove = 7;
    std::vector<int> vec1 = { 1, 2, 3, 4, 5 };
    

    string newString = removeChar(myString, indexToRemove);

    cout << "�������� ������: " << myString << std::endl;
    cout << "������ ����� �������� ������� � �������� " << indexToRemove << ": " << newString << std::endl;

    // ������ � ������������ ��������
    string newString2 = removeChar(myString, 20);
    cout << "������� ������� ������ � �������� 20 (������������): " << newString2 << std::endl; // ������� �������� ������

    return 0;
}