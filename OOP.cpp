#include <iostream>
#include <string>
#include <vector>

#include "ARRAYINT.h"
using namespace std;
vector<int> init_arr(vector<int>&arr, const int SIZE)
{
    for (size_t i = 0; i < SIZE; i++)
    {
        arr.push_back(rand() % 10);
    }

    return arr;
}


int main()
{
   //1е задание
    {
        //ArrayInt array(10);

        //// Заполняем массив числами от 1 до 10
        //for (int i = 0; i < 10; i++)
        //    array[i] = i + 1;

        //// Изменяем размер массива до 7 элементов
        //array.resize(7);

        //// Вставляем число 15 перед элементом с индексом 4
        //array.insertBefore(15, 4);

        //// Удаляем элемент с индексом 5
        //array.remove(5);

        //// Добавляем числа 35 и 50 в конец и в начало
        //array.Push_back(35);
        //array.Push_pop(50);
        //array.Pop_back();

        //// Выводим все элементы массива
        //array.PrintArr();
        //array.insert_sort();
        //array.PrintArr();
    }

    //2 задание
    const int SIZE = 100;
    vector<int>arr;
    init_arr(arr, SIZE);
    int counter = 0;
    for (size_t i = 0; i < SIZE; i++)
    {
        cout << arr[i] << " ";
    }
    int i = 1;
    int rep = 0;
    while (i < arr.size()) {
        if (arr[i] == arr[i - 1])
            rep += 2;
        i++;    
    }
    counter = i - rep;
    //for (size_t i = 1; i < arr.size(); i++)
    //{
    //    if (arr[i] == arr[i - 1])
    //        --r_coun;
    //}
    cout << endl << "===" << counter;
	return 0;
}