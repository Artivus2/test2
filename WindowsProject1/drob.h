#pragma once

class Drob {
private:
    //int numerator; //числитель
    //int denominator; //знаменатель
    

    //4/6
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;  
            b = a % b; 
            a = temp; 
        }
        return a < 0 ? -a : a;
    } // наибольшее число деления обоих числе

    void simplify() {
        int gcd1 = gcd(numerator, denominator); 
        numerator /= gcd1;  
        denominator /= gcd1;
        
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    //HWND resn;
    //HWND resd;
    int numerator; //числитель
    int denominator; //знаменатель
    // Default constructor
    Drob(int numerator = 0, int denominator = 1) {
        if (denominator == 0) {
            //throw std::invalid_argument("Denominator cannot be zero.");

        }
        this->numerator = numerator;
        this->denominator = denominator;
        simplify();
    }

    // Method for inputting the drob
    //void input() {
    //    /*std::cout << "Enter numerator: ";
    //    std::cin >> numerator;
    //    std::cout << "Enter denominator: ";
    //    std::cin >> denominator;*/
    //    if (denominator == 0) {
    //        throw std::invalid_argument("Denominator cannot be zero.");
    //    }
    //    simplify();
    //}

    // Method for adding drobs
    Drob operator+(const Drob& other) const {
        int new_numerator = numerator * other.denominator + other.numerator * denominator;
        int new_denominator = denominator * other.denominator;
        return Drob(new_numerator, new_denominator);
    }

    // Method for subtracting drobs
    Drob operator-(const Drob& other) const {
        int new_numerator = numerator * other.denominator - other.numerator * denominator;
        int new_denominator = denominator * other.denominator;
        return Drob(new_numerator, new_denominator);
    }

    // Method for multiplying drobs
    Drob operator*(const Drob& other) const {
        int new_numerator = numerator * other.numerator;
        int new_denominator = denominator * other.denominator;
        return Drob(new_numerator, new_denominator);
    }

    // Method for dividing drobs
    Drob operator/(const Drob& other) const {
        if (other.numerator == 0) {
            //throw std::invalid_argument("Division by zero.");
        }
        int new_numerator = numerator * other.denominator;
        int new_denominator = denominator * other.numerator;
        return Drob(new_numerator, new_denominator);
    }

    // Method for outputting the drob
    void output() {
        //std::cout << numerator << "/" << denominator << std::endl;

        

    }
};

//int main() {
//    Drob drob1(1, 2);
//    Drob drob2(3, 4);
//
//    std::cout << "Drob 1: ";
//    drob1.output();
//    std::cout << "Drob 2: ";
//    drob2.output();
//
//    Drob sum = drob1 + drob2;
//    Drob difference = drob1 - drob2;
//    Drob product = drob1 * drob2;
//    Drob quotient = drob1 / drob2;
//
//    std::cout << "Sum: ";
//    sum.output();
//    std::cout << "Difference: ";
//    difference.output();
//    std::cout << "Product: ";
//    product.output();
//    std::cout << "Quotient: ";
//    quotient.output();
//
//    return 0;
//}

