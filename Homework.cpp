
#include <iostream>

using namespace std;

// Работа с массивами 

// Функ нахождения медианы из 3х
int Median(int num1, int num2, int num3)
{
	if ((num2 < num1 && num1 < num3) || (num2 > num1 && num1 > num3))
	{
		return num1;
	}

	if ((num1 < num2 && num2 < num3) || (num1 > num2 && num2 > num3))
	{
		return num2;
	}

	return num3;
}

// Выделение динамического массива
int** init_arr( const int row, const int col )
{
	int** arr = new int* [row];
	for (size_t i = 0; i < row; i++) 
	{
		arr[i] = new int[col];
	}
	return arr;
}

//Заполнение динамического массива
void fill_arr(int** arr, const int row, const int col)
{
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0;  j < col;  j++)
		{
			arr[i][j] = rand() % 99;
		}
	}
}

//Печать массива (двумерный)
void print_arr(int** arr, const int row, const int col)
{
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			cout << arr[i][j] << " ";;
		}
		cout << endl;
	}
	cout << endl;
}

// Удание динамического массива
void delete_arr(int** arr, const int row, const int col)
{
	for (size_t i = 0; i < row; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}

// Замена значений
void swap(int *a, int *b)
{
	int s = *a;
	*a = *b;
	*b = s;
}

// Пузырьковая сортировка двумерного массива
void bubble_sort(int** arr, int row, int col)
{
	for (size_t i = 0; i < row ; i++)
	{
		for (size_t i = 0; i < col; i++)
		{
			for (size_t j = 0; j < col - 1; j++)
			{
				if (arr[i][j] > arr[i][j + 1])
				{
					swap(arr[i][j], arr[i][j + 1]);
				}
			}
		}
	}
}

// Сортировка вставкой ( не изученно доконца)
void insert_sort(int* arr, int size)
{
	int temp, pos;
	for (size_t i = 1; i < size; i++)
	{
		temp = arr[i];
		pos = i - 1;
		while (pos >= 0 && arr[pos] > temp)
		{
			arr[pos + 1] = arr[pos];
			pos--;
		}
		arr[pos + 1] = temp;

	}

}

// Простая для понимания сортировка вставкой
void insert_sort_easy(int* arr, int size)
{
	for (size_t i = 1; i < size; i++)
	{
		while (i > 0 && arr[i - 1] > arr[i])
		{
			swap(arr[i - 1], arr[i]);
			i--;
		}
	}
}


//Выделение и инициализация одномерного массива
void just_arr(int* arr, const int size)
{
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = rand() % 50;
	}
}

// Вывод одномерного массива
void pinnt_just_arr(int* arr, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

// Алгоритм быстрой сортировки массива
void quick_sort(int* arr, int first, int last)
{
	
	int i = first;
	int j = last;
	int x = arr[(first + last) / 2];

	int med = Median(arr[first], arr[x], arr[last]); // Вызвается функ нахождения медины их 3х чисел

	if (j > 10)
	{
		insert_sort_easy(arr,last); // То вызовем функцию вставкой
	}

	do
	{
		while (med > arr[i]) i++;
		while (med < arr[j]) j--;

		if (i <= j)
		{
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
	} 
	while (i <= j);
	{
		if (i < last)
		{
			quick_sort(arr, i, last);
		}
		if (first < j)
		{
			quick_sort(arr, first, j);
		}
	}
}

// Алгоритм блочной сортировки
void bucket_sort(int* arr, int size)
{
	const int max = size;
	const int b = 10;

	
}




int main()
{
	const int row = 30;
	const int col = 10;
	
	int arr[row];
	just_arr(arr, row);
	pinnt_just_arr(arr, row);
	quick_sort(arr,0,row - 1);
	pinnt_just_arr(arr, row);








}
 
