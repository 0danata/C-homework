
#include <iostream>
using namespace std;

extern const int a, b, c, d; // 4е задание
int main()
{
	
	float J = a * (b + static_cast <float> ((d) / c));
	cout << J << endl;
	
	/// //////////////////////////////////////////////////////////////////////////////////////////////
	
	int array[3][3][3]; // 3e задание
	
       int *Arr = &array[1][1][1];
	       *Arr = 32;

	cout << Arr << endl;


	/// //////////////////////////////////////////////////////////////////////////////////////////////
	
		

	int S = 15, V = 21;          // 2е задание 
	int M;

	if (S < V || S == V)
	{
		cout << V - S << endl;
	}

	
	M = (S > V) ? M = (S - V) * 2 : NULL ; // когда ставил nullptr вместо  NULL, вызодила ошибка. Почему ? 
	    cout << M << endl;
		
		

	return 0;
}
