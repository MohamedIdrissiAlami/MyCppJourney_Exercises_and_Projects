#include <iostream>
#include <cstdlib>
using namespace std;

short RandomNumber(short From, short To)
{
	return rand() % (To - From + 1) + From;
}

void FillMatrixWithRandomNumbers(short arr[3][3],short Rows,short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			arr[i][j] = RandomNumber(1, 99);
		}
	}
}

void PrintMatrix(short arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			printf("%0*d ", 2, arr[i][j]);
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

short RowSum(short arr[3][3], short RowNumber, short Cols)
{
	short Sum = 0;
	for (short j = 0; j < Cols; j++)
	{
		Sum += arr[RowNumber - 1][j];
	}
	return Sum;
}

void SumMatrixRowsInArray(short arr[3][3], short arrSum[3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		arrSum[i] = RowSum(arr, i+1, Cols);
	}
}

void PrintRowsSumArray(short arrSum[3], short arrLength)
{
	for (short i = 0; i < arrLength; i++)
	{
		cout << "\nRow  " << i + 1 << " sum = " << arrSum[i];
	}
}

int main()
{
	//seeds the random numbers generator in C++, called only once .
	srand((unsigned)time(NULL));
	short arr[3][3], arrSum[3];
	FillMatrixWithRandomNumbers(arr,3,3);
	cout << "\nThe following is a 3x3 random matrix : \n";
	PrintMatrix(arr,3,3);

	SumMatrixRowsInArray(arr,arrSum,3,3);
	cout << "\nThe following are sum of each row of matrix from a separate array : ";
	PrintRowsSumArray(arrSum, 3);
	system("pause>0");
	return 0;
}