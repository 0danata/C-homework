
#include <iostream>

using namespace std;

bool Prime(int a) // Функция провыерки простого числа
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


int main()
{
    cout << (Prime(197) ? "True" : "False");
}
 
