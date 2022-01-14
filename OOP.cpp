#include <iostream>
#include <cmath>
#include <cstdint>
using namespace std;

//1. Создать класс Power, который содержит два вещественных числа. Этот класс должен иметь две переменные-члена для хранения этих вещественных чисел.
// Еще создать два метода: один с именем set, который позволит присваивать значения объявленным в классе переменным,
// второй — calculate, который будет выводить результат возведения первого числа в степень второго числа. Задать значения этих двух чисел по умолчанию.

class Power
{
    int a;
    int b;

public:
    void SetAandB(int a_val, int b_val)
    {
        a = a_val;
        b = b_val;
    }
    int calculate()
    {
        return pow(a, b);
    }
};

//2. Написать класс с именем RGBA, который содержит 4 переменные-члена типа std::uint8_t: m_red, m_green, m_blue и m_alpha (#include cstdint для доступа к этому типу).
// Задать 0 в качестве значения по умолчанию для m_red, m_green, m_blue и 255 для m_alpha.
// Создать конструктор со списком инициализации членов, который позволит пользователю передавать значения для m_red, m_blue, m_green и m_alpha.
// Написать функцию print(), которая будет выводить значения переменных-членов.

class RGBA
{
    uint8_t m_red;
    uint8_t m_green;
    uint8_t m_blue;
    uint8_t m_alpha;
public:
    RGBA()
    {
        m_red = 0;
        m_green = 0;
        m_blue = 0;
        m_alpha = 255;
    }
    RGBA(uint8_t r,uint8_t g,uint8_t b,uint8_t a)
    {
        m_red = r;
        m_green = g;
        m_blue = b;
        m_alpha = a;
    }
    void Print()
    {
        cout << static_cast<int>(m_red) << endl << static_cast<int> (m_green) << endl;
        cout << static_cast<int> (m_blue) << endl << static_cast<int> (m_alpha);
    }
};

//3. Написать класс, который реализует функциональность стека. Класс Stack должен иметь:
//• private - массив целых чисел длиной 10;
//• private целочисленное значение для отслеживания длины стека;
//• public - метод с именем reset(), который будет сбрасывать длину и все значения элементов на 0;
//• public - метод с именем push(), который будет добавлять значение в стек.push() должен возвращать значение false, если массив уже заполнен, и true в противном случае;
//• public - метод с именем pop() для вытягивания и возврата значения из стека.Если в стеке нет значений, то должно выводиться предупреждение;
//• public - метод с именем print(), который будет выводить все значения стека.

 class Stack
{
     int arr[10];
     int stack_size = NULL;
public:
    void reset()
    {
            for (size_t i = 0; i < 10; i++)
            {
                arr[i] = NULL;
            }
            stack_size = NULL;
    }

    bool push(int num)
    {
        if (stack_size <= 10)
        {
            for (size_t i = stack_size; i <= stack_size; i++)
            {
                arr[i] += num;
            }
            stack_size++;
            return true;
        }
        else
        {
            cout << "Limit over";
            return false;
        }
    }

    int pop()
    {
        if (stack_size)
        {
            stack_size--;
            arr[stack_size] = NULL;
        }
        else
        {
            cout << "Your stack is empty";
            return -1;
        }
    }

    void print()
    {
        for (size_t i = stack_size; i < 10; i--)
        {
            if (arr[i] != 0)
            {
                cout << arr[i] << ", ";
            }
        }
        cout << endl;
    }
};

int main()
{
    //task 2
    //RGBA def;
    //def.Print();
    //RGBA another(12,13,1,16);
    //another.Print();

    //Task3
    Stack stack;
    stack.reset();
    stack.print();

    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();
    stack.print();



    return 0;
}