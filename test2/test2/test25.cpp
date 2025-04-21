#include <iostream>
#include <string>
#include <vector> 

using namespace std;

string removeChar(const string& str, int index) {
    // Проверяем, что индекс находится в допустимом диапазоне
    if (index < 0 || index >= str.length()) {
        // Возвращаем исходную строку, если индекс некорректен
        return str;
    }

    // Создаем новую строку, исключая символ с заданным индексом
    string result = str.substr(0, index) + str.substr(index + 1);
    return result;
}

int main_25() {
    string myString = "Hello, world!";
    int indexToRemove = 7;
    std::vector<int> vec1 = { 1, 2, 3, 4, 5 };
    

    string newString = removeChar(myString, indexToRemove);

    cout << "Исходная строка: " << myString << std::endl;
    cout << "Строка после удаления символа с индексом " << indexToRemove << ": " << newString << std::endl;

    // Пример с некорректным индексом
    string newString2 = removeChar(myString, 20);
    cout << "Попытка удалить символ с индексом 20 (некорректный): " << newString2 << std::endl; // Выведет исходную строку

    return 0;
}