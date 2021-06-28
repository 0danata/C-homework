
#include <iostream>

/* Конкретный случай.У меня есть машина которую я продаю по запчастям.
*  Машина LADA, модель - Priora. Состоит из запчастей :  1) Мотор, 2) коробка, 3) глушитель, 4) стекла, 5 )сиденья.
*  + продаю 2)коробку по запчастя ( так не покупают ) моховик, лабуда, рычаг.*/ 

using namespace std;
const int Priora[5] = { 1,2,3,4,5 };

struct Lada
{
    int ID; // детали от 1 до 5
    int age; // возраст детали
    short int price; // цена
    char name; // имя детали. на всякий случай
    long long VIN;  // вин код
    bool Originl_or_not; // оригинал или херня
    float version; // дробные числа. версия
    double another_version; // большие дробные числа. версия
};
struct 
{  
    unsigned int ID : 2;
    unsigned int age : 2;


} flags;

int main() 
{
 
    struct Lada
    {
        int ID = 1; // детали от 1 до 5
        int age = 2; // возраст детали
        short int price = 30200; // цена
        char name  = 11111; // имя детали. на всякий случай
        long long VIN = 11221133;  // вин код
        bool Originl_or_not = false; // оригинал или херня
        float version = 1.22; // дробные числа. версия
        double another_version = 33.21; // большие дробные числа. версия
    };


    
  



    return 0;
}
