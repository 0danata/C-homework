
#include <iostream>

using namespace std;

// Работа с массивами
//					  строка         столбец
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

//Печать массива
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
void swap(int &a, int &b)
{
	int s = a;
	a = b;
	b = s;
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

// Сортировка вставкой
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

int just_arr(int* arr,int size)
{
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = rand() % 50;
		cout << arr[i];
	}
}



char* KMP(char)
{

}




int main()
{
	const int row = 10;
	const int col = 10;
	

	int **arr = init_arr(row,col);
	
	fill_arr(arr, row, col);
	print_arr(arr, row, col);
	bubble_sort(arr, row, col);
	print_arr(arr, row, col);

	for (size_t i = 0; i < row; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;




}
 
