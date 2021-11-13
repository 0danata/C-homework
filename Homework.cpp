
#include <iostream>

using namespace std;

bool Prime(int a) // Функция проверки простого числа
{
    if (a < 2)
        return false;

    else
    {
        for (size_t i = 2; i * i <= a; i++)
        {
            if (a % i == 0)
            {
                return false;
            }
        }
        return true;
    }
}

void bin(int a) // Функция перевода из десятичного в доичную систему 
{
    if (a >= 2) 
    {
        bin(a / 2);
    }
    cout << a % 2;
}

int pow(int a, int b) // Функция возведения числа в степень
{
    if (b == 0) 
    {
        return 1;
    }
    if (b % 2 == 0) 
    {
        return pow(a * a, b / 2);
    }
    return a * pow(a, b - 1);
}





int main()
{
 

    
}
 
