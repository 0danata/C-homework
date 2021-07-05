

#include <iostream>
using namespace std;
setlocale(LC_ALL, "ru");

int main()
{
	{
		int a; // 1e задание
		cout << "Number" << endl;
		cin >> a;
		if (a == 10 && a > 10 || a == 20 && a < 20)
		{
			cout << "True" << endl;
		}
		else if (a < 10 || a > 20)
		{
			cout << "False" << endl;
		}
	} return;

	//////////////////////////////////////////////////////////////////////
	{
		const int a = 5, b = 5;//2e задание
		if (a == 10 && b == 10)
			cout << "True";
		if (a + b == 10)
			cout << "True";
		else
			cout << "False";

		

	}
	
	/// ///////////////////////////////////////////////////////////////////////////////////
		
	int a;     // 3e задание
	int b = 50;
	int number = 0;

	cout << "Введите начало диапазона для вывода нечет чисел от 1 до 50" << endl;
	cin >> a;



	while (a <= b)
	{
		if (a % 2 != number)
		{
			cout << "Список нечетные чисел в диапазоне = " << a << endl;
		}

		a++;
	}

	return 0;
}