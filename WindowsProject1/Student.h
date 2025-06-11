#pragma once

class Point {
    int x{ 0 };
    int y{ 0 };
public:
    static int max1;

};

int Point::max1(30);


class Student {

public:
    char name[21];
    //Point point1;
    int marks[3];
    int countmarks;
    uint16_t age;
    double sum;
    wchar_t buffer[256];
    HWND labelInline;

    double getAver(); //прототип

    Student() {
        sum = 0;
        SetWindowTextW(labelInline, L"Создали экземлпяр");
    }

    Student(const char* studentName)
    {
        setName(studentName);
    }

    /*LPCWSTR setTextD(double a) {

        wsprintfW(buffer, L"%d", a);
        if (a == -1) {
            wsprintfW(buffer, L"-", a);
        }
        if (a == 0) {
            wsprintfW(buffer, L" ", a);
        }
        return ::buffer;

    }*/


    void Print(double sum) {
        std::wstringstream wss;
        wss << std::fixed << std::setprecision(5) << sum; // Форматирование вывода
        std::wstring resultString = wss.str();

        SetWindowTextW(labelInline, resultString.c_str());
        
        //SetWindowTextW(labelInline, buffer);
    }

    const char* getName() {
        SetWindowTextW(labelInline, (LPCWSTR)name);
        return name;
    };
    void setName(const char* studentName) {
        strcpy_s(name, 20, studentName);
    };
    // доступ к элементам массива marks
    int getMark(int index) {


        return marks[index];
    };
    void setMark(int mark, int index) {
        if (mark < 1 or mark > 12)
        {
            mark = 0;
        }
        marks[index] = mark;
    };


    ~Student() {
       delete[] name;
       delete[] marks;
    };


};



//реализация функции
double Student::getAver()
{
    double sum = 0;
    for (int i = 0; i < 3; i++)
    {
        sum += marks[i];
    }
    return sum / 3;
}



    /*Student() {


        countmarks = 0;
    }
    Student(const char* nameP, const int countmarksP, const int marksP) :
        name{ nameP ? new char[strlen(nameP) + 1] : nullptr },
        countmarks{ countmarksP }
    {
        if (name)
        {
            strcpy_s(name, strlen(nameP) + 1, nameP);
        }
    }*/
        



    /*Student(const char* name, const int* countmarks,const int* marks) {
        strcpy_s(Student::name, 20, name);
        for (int i = 0; i < 3; i++)
        {
            Student::marks[i] = marks[i];
        }
    }

    Student(const char* name, const int* marks) {
        strcpy_s(Student::name, 20, name);
        for (int i = 0; i < 3; i++)
        {
            Student::marks[i] = marks[i];
        }
    }

    Student(const char* nameP)
        : name{ new char[strlen(nameP) + 1] }, age{ 0 }
    {
        strcpy_s(name, strlen(nameP) + 1, nameP);
        
    }*/




    //const char* getName()
    //{
    //    return name;
    //}
    //void setName(const char* studentName) {
    //    strcpy_s(name, 20, studentName);
    //};
    //// доступ к элементам массива marks
    //int getMark(int index) {
    //    return marks[index];
    //};
    //void setMark(int mark, int index) {
    //    if (mark < 1 or mark > 12)
    //    {
    //        mark = 0;
    //    }
    //    marks[index] = mark;
    //};

    //~Student() {
    //    delete[] name;
    //    delete[] marks;
    //};

    //LPCWSTR setText(int a) {

    //    wsprintfW(buffer, L"%d", a);
    //    if (a == -1) {
    //        wsprintfW(buffer, L"-", a);
    //    }
    //    if (a == 0) {
    //        wsprintfW(buffer, L" ", a);
    //    }
    //    return ::buffer;

    //}

//};

