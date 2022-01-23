#include <iostream>
#include <string>

using namespace std;

////1. Создать абстрактный класс Figure (фигура). Его наследниками являются классы Parallelogram (параллелограмм) и Circle (круг). 
//Класс Parallelogram — базовый для классов Rectangle (прямоугольник), Square (квадрат), Rhombus (ромб). 
//Для всех классов создать конструкторы. Для класса Figure добавить чисто виртуальную функцию area() (площадь).
//Во всех остальных классах переопределить эту функцию, исходя из геометрических формул нахождения площади.

class Figure
{
public:
    virtual int Area() = 0;
};

class Parallelogram : public Figure
{
protected:
    int _length;
    int _height;
public:
    Parallelogram(int a, int b) : _length(a), _height(b) {};
    int Area() override
    {
        return _length * _height;
    }
    Parallelogram();
};

class Circle : public Figure
{
protected:
    const float _Pi = 3.14;
    float _R;
public:
    Circle(float R) : _R(R) {};
    int Area() override
    {
        return static_cast<int>(_Pi * (_R * _R));
    }
};

class Rectangle : public Parallelogram
{
public:
    Rectangle(int m_length, int m_height) : Parallelogram(m_length, m_height) {};
    int Area() override
    {
        return  _length * _height;
    }
};
// S = (AC · BD) / 2
class Square : public Parallelogram
{
public:
    Square(int a, int b) : Parallelogram(a, b) {};
    int Area() override
    {
        return  (_length * _height) / 2;
    }
};

////2. Создать класс Car (автомобиль) с полями company (компания) и model (модель). 
//Классы-наследники: PassengerCar (легковой автомобиль) и Bus (автобус). 
//От этих классов наследует класс Minivan (минивэн). Создать конструкторы для каждого из классов, чтобы они выводили данные о классах.
//Создать объекты для каждого из классов и посмотреть, в какой последовательности выполняются конструкторы. 
//Обратить внимание на проблему «алмаз смерти».


class Car
{
protected:
    string _company;
    string _model;
public:
    Car(string company, string model) : _company(company), _model(model)
    {
        cout << "Lest check out" << '\n';
    };
    Car() {};
    ~Car()
    {
        cout << "~ Car konstr is dead now" << '\n';
    };
};
class PassengerCar : virtual public Car
{
public:
    PassengerCar(string pas_company, string pas_model) : Car(pas_company, pas_model)
    {
        cout << "1. PassengerCar company is - " << _company << '\n';
        cout << "1. PassengerCar model is   - " << _model << '\n';
    }
    PassengerCar() {};
    ~PassengerCar()
    {
        cout << "~ PassengerCar konstr is dead" << '\n';
    };
};
class Bus : virtual public Car
{

public:
    Bus(string bus_company, string bus_model) : Car(bus_company, bus_model)
    {
        cout << "2. Bus company is  - " << _company << '\n';
        cout << "2. Bus model is    - " << _model << '\n';
    }
    Bus() {};
    ~Bus()
    {
        cout << "~ Bus konstr is dead now" << '\n';
    };
};

class Minivan : public PassengerCar, public Bus
{
public:
    Minivan(string min_company, string min_model) : Bus(min_company, min_model), PassengerCar(min_company, min_model), Car(min_company, min_model)
    {
        cout << "3. Mini company is  - " << _company << '\n';
        cout << "3. Mini model is    - " << _model << '\n';
    };
};

////4. Создать класс Card, описывающий карту в игре БлэкДжек.
//У этого класса должно быть три поля: масть, значение карты и положение карты (вверх лицом или рубашкой).
//Сделать поля масть и значение карты типом перечисления (enum). Положение карты - тип bool. Также в этом классе должно быть два метода:
//метод Flip(), который переворачивает карту, т.е.если она была рубашкой вверх, то он ее поворачивает лицом вверх, и наоборот.
//метод GetValue(), который возвращает значение карты, пока можно считать, что туз = 1.

class Card
{
public:
    enum rank { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };
    enum suit { CLUBS, DIAMONDS, HEARTS, SPADES };

    Card(rank r = ACE, suit s = SPADES, bool ifu = true) : m_Rank(r), m_Suit(s), m_IsFaceUp(ifu) { }

    int GetValue() const;
    void Flip();

private:
    rank m_Rank;
    suit m_Suit;
    bool m_IsFaceUp;
};

int Card::GetValue() const
{
    int value = 0;
    if (m_IsFaceUp)
    {
        value = m_Rank;
        if (value > 10)
        {
            value = 10;
        }
    }
    return value;
}

void Card::Flip()
{
    m_IsFaceUp = !m_IsFaceUp;
}



int main()
{
    /*   Parallelogram s(12,10);
       cout <<"Parallelogram area" <<  s.Area() << endl;
       Rectangle t(13,6);
       cout << "Rectangle area = " << t.Area() << endl;
       Square c(10, 5);
       cout << "Square area = " << c.Area() << endl;
       Circle v(4);
       cout << "Circle area = " << v.Area() << endl;*/



       //Task2. Ужас происходит 

       //PassengerCar b("Toyota", "Camry");
       //Bus c("Lada", "Kalina");
       //Minivan a("Mini", "BMW");
    std::cout << std::endl;


    return 0;
}