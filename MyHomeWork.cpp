

#include <iostream>
#include <stack>

using namespace std;


const auto SIZE = 100;
int arr[SIZE];
int first = -1;

int bin(int num); // Прот функ перевода чисел

// Стековая функ с переводом числа в бинарный формат
int stack_push(int data)
{
    int bin = 0, k = 1;

    while (data)
    {
        bin += (data % 2) * k;
        k *= 10;
        data /= 2;
    }

    if (first < SIZE)
    {

        arr[++first] = bin;
        return arr[bin];
    }
    else
    {
        cout << "Stack overflow";
        return -1;
    }
}

int pop()
{
    if (first != -1)
    {
        return arr[first--];
    }
    else
        cout << " Its over";
        return -1;
}

// С подключением библы
void stack_upgr(int num)
{
    stack <int> ST;


    int bin = 0, k = 1;

    while (num)
    {
        bin += (num % 2) * k;
        k *= 10;
        num /= 2;
    }

    ST.emplace(bin);

    if (!ST.empty())
        cout << "Your bin number is = " << ST.top();
}

int bin(int num)
{

    int bin = 0, k = 1;

    while (num)
    {
        bin += (num % 2) * k;
        k *= 10;
        num /= 2;
    }

    return bin;
}




int main()
{
    /*stack_push(15);
    stack_push(11);
    stack_push(5);
    stack_push(6);
    stack_push(4);

    while (first != -1)
        cout << pop() << " ";*/

    const int SIZE = 6;
    int arr[] = { 1,2,-1,16,44,-31 };
    int a = sizeof(arr) / sizeof(int);
    a--;
    for (size_t i = 0; i < a; i++)
    {
        if (arr[i] == 1 || arr[i] == -1)
        {
            arr[i] = NULL;
        }

        cout << arr[i] << " ";
    }
}
