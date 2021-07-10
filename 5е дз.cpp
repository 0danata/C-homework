#include <iostream>
using namespace std;
/* Я уже сам запутался где какое задание.В след раз буду аккуратнее.
Старался делать все сам. B 3м задании застрял */


void ARR(int arr[], const int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = rand() % 2;
		cout << arr[i] << " ";
	}
	cout << endl;
}

void ARR2(int arr[], const int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = arr[i] == 1 ? 0 : 1;
		cout << arr[i] << " ";
	}
} 



bool PrintArray(double anyarr[], const int mysize)
{
	for (size_t i = 0; i < mysize; i++)
	{
		cout << anyarr[i] << " ";
	}
	cout << endl;
	return true;
	}
int main()
{
	const int mysize = 5;
	double myarr[] = { 10.13, 20.21, 30.11, 20.44, 10.01 };
	if (PrintArray(myarr, mysize))
	{
		cout << "Array was successfuly printed" << endl;
	}
	{
		const int SIZE = 5;
		int arr[SIZE];

		ARR(arr, SIZE);
		ARR2(arr, SIZE);
	}//2e задание
	return 0;
	
}

bool homework_3(int* array, int SIZE)
{
	int nmr = 1;
	int plus = 3;
	for (int i = 0; i < SIZE; i++)
	{
		array[i] = nmr;
		nmr = nmr + plus;
		std::cout << array[i] << std::endl;
	}
	return true;
}

void Task3()
{
	const int SIZE = 8;
	int aRR[SIZE];
	

	homework_3(aRR, SIZE);


	cout << aRR[SIZE]<<endl;


}
