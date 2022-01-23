#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Fraction
{
private:
    int _a;
    int _b;
public:
    Fraction(int a, int b) : _a(a), _b(b) {};

    int Get_a() const { return _a;}
    int Get_b() const
    {
        if (_b)
            return _b;
        else
            cout << "Error 404";
    }
    void print()
    {
        std::cout << Get_a() << "/" << Get_b() << "\n";
    }

    friend Fraction operator/(const Fraction &v1, const Fraction &v2);
    friend Fraction operator*(const Fraction &c1, const Fraction &c2);
};

Fraction operator/(const Fraction &v1, const Fraction &v2)
{
    return Fraction(v1._a,v2._b);
}

Fraction operator*(const Fraction &c1, const Fraction &c2)
{
   
    return Fraction(c1._a *c2._a, c1._b * c1._b);
}

int main()
{
    Fraction a(2, 9);
    a.print();
    Fraction b(3, 5);
    b.print();
    Fraction c = a * b;
    c.print();
    return 0;
}