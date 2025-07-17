#include <iostream>
using namespace std;

class Complex {
private:
    float real;
    float imag;

public:
    Complex(float r = 0, float i = 0) : real(r), imag(i) {}

    Complex operator + (const Complex& other) {
        return Complex(real + other.real, imag + other.imag);
    }

    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

class Time {
private:
    int hours;
    int minutes;

public:
    Time(int h = 0, int m = 0) : hours(h), minutes(m) {}

    Time operator + (const Time& t) {
        Time result;
        result.minutes = minutes + t.minutes;
        result.hours = hours + t.hours + (result.minutes / 60);
        result.minutes %= 60;
        return result;
    }

    void display() {
        cout << hours << " hours " << minutes << " minutes" << endl;
    }
};

int main() {
    // Complex Numbers
    Complex c1(2.5, 3.5), c2(1.5, 4.5);
    Complex c3 = c1 + c2;
    cout << "Sum of Complex numbers: ";
    c3.display();

    // Time Addition
    Time t1(2, 50), t2(1, 30);
    Time t3 = t1 + t2;
    cout << "Sum of Time durations: ";
    t3.display();

    return 0;
}