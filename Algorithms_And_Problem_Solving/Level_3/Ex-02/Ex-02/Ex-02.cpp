#include <iostream>
#include <cstdlib>
using namespace std;

short RandomNumber(short From, short To)
{
	return rand() % (To - From + 1) + From;
}

void FillA3x3MatrixWithRandomNumbers(short arr[3][3])
{
	for (short i = 0; i < 3; i++)
	{
		for (short j = 0; j < 3; j++)
		{
			arr[i][j] = RandomNumber(1, 99);
		}
	}
}

void Print3x3Matrix(short arr[3][3])
{
	for (short i = 0; i < 3; i++)
	{
		for (short j = 0; j < 3; j++)
		{
			printf("%0*d ",2, arr[i][j]);
		}
		cout << endl;
	}
}

template<typename T> T Sum(T Number1, T Number2)
{
	return (T)(Number1 + Number2);
}


template<typename T> T Sum(T Number1, T Number2, T Number3)
{
	return Sum(Number1, Number2) + Number3;
}

void SumEachRowInMatrix(short arr[3][3])
{
	for (short i = 0; i < 3; i++)
	{
		cout << "\nrow " << i + 1 << " = " << Sum<short>(arr[i][0], arr[i][1], arr[i][2]);
	}
}

int main()
{
	//seeds the random numbers generator in C++, called only once .
	srand((unsigned)time(NULL));
	short arr[3][3];
	FillA3x3MatrixWithRandomNumbers(arr);
	cout << "\nThe following is a 3x3 random matrix : \n";
	Print3x3Matrix(arr);
	cout << "\nThe following are sum of each row in the matrix : ";
	SumEachRowInMatrix(arr);
	system("pause>0");
	return 0;
}