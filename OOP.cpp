#include <iostream>
#include <cmath>
#include <cstdint>
#include <string>
using namespace std;

////1. Создать класс Person(человек) с полями : имя, возраст, пол и вес.
//Определить методы переназначения имени, изменения возраста и веса.
//Создать производный класс Student(студент), имеющий поле года обучения.
//Определить методы переназначения и увеличения этого значения.Создать счетчик количества созданных студентов.
//В функции main() создать несколько(не больше трёх) студентов.

class Person
{
    string _name;
    short _age;
    string _sex;
    short _weight;
public:
    void SetPar(string name, short age, string sex, short weight)
    {
        _name = name;
        _age = age;
        _sex = sex;
        _weight = weight;
    }
    string GetName() { return _name; }
    short GetAge() { return _age; }
    string GetSex() { return _sex; }
    short GetWeight() { return _weight; }
};

class Student : public Person
{
    int _years;
    short _St_num;

public:


    void SetStud(const int year, const short st_num)
    {
        _years = year;
        _St_num = st_num;
    }
   
    int GetYears() { return _years; }
    short GetStud() { return _St_num; }

    friend void Print(Student &stud);
};

void Print(Student &stud)
{
    cout << "Stud name - " << stud.GetName()<< '\n';
    cout << "Age - " << stud.GetAge() << '\n';
    cout << "Sex - " << stud.GetSex() << '\n';
    cout << "Weight -" << stud.GetWeight() << '\n';
    cout << "Date of study - " << stud.GetYears() << '\n';
    cout << "Stud number - №" << stud.GetStud() << '\n';
}


////2. Создать классы Apple (яблоко) и Banana (банан), которые наследуют класс Fruit (фрукт). 
// У Fruit есть две переменные-члена: name (имя) и color (цвет).
//  Добавить новый класс GrannySmith, который наследует класс Apple.
// 
//int main()
//{
//    Apple a("red");
//    Banana b;
//    GrannySmith c;
//
//    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
//    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
//    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";
//
//    return 0;
//}
//
//Код, приведенный выше, должен давать следующий результат :
//
//My apple is red.
//My banana is yellow.
//My Granny Smith apple is green.


class Fruit
{
    string _name;
    string _color;
public:

    void SetColor(string color)
    {
        _color = color;
    }
    string GetColor()
    {
        return _color;
    }
    friend class Apple;

    void SetName(string name)
    {
        _name = name;
    }
    string GetName()
    {
        return _name;
    }
};

class Apple : public Fruit
{
public:
    Apple()
    {

    }
    Apple(string color)
    {
        SetColor(color);
        SetName("Apple");
    }
    friend class GrannySmith;
};

class Banana : public Fruit
{
public:
    Banana()
    {
        SetName("Banana");
        SetColor("Yellow");
    }
};

class GrannySmith : public Apple
{
public:
    GrannySmith()
    {
        SetName("apple");
        SetColor("green");
    }

};


////3. Изучить правила игры в Blackjack.
//классы : 
//Game
//{
//    Cards;
//
//}
//Players
//{
//    AI;
//    Human;
//}

int main()
{
    setlocale(LC_ALL, "Russian");

    Student a;
    a.SetPar("Roma", 31, "M", 66);
    a.SetStud(2007, 1);
    Print(a);

    Student c;
    c.SetPar("Jira", 17, "W", 3);
    c.SetStud(2011, 2);
    Print(c);


    Apple b("Red");
    Banana s;
    GrannySmith fss;
    

    std::cout << "My " << b.GetName() << " is " << b.GetColor() << ".\n";
    std::cout << "My " << s.GetName() << " is " << s.GetColor() << ".\n";
    std::cout << "My " << fss.GetName() << " is " << fss.GetColor() << ".\n";
    return 0;
}