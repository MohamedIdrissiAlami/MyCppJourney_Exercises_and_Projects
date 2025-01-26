#include <iostream>
#include <cstdlib>
using namespace std;

short RandomNumber(short From, short To)
{
	return rand() % (To - From + 1) + 1;
}

void Fill3x3MatrixWithRandomNumbers(short arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			arr[i][j] = RandomNumber(1, 10);
		}
	}
}

void Print3x3Matrix(short arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			printf("%0*hd  ", 2, arr[i][j]);
		}
		printf("\n");
	}
}

void MultiplyTwo3x3Matrixes(short arr1[3][3], short arr2[3][3],short arrMultiply[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			arrMultiply[i][j] = arr1[i][j] * arr2[i][j];
		}
	}
}

int main()
{
	short arr1[3][3], arr2[3][3], arrMultiply[3][3];
	Fill3x3MatrixWithRandomNumbers(arr1, 3, 3);
	cout << "\nMatrix1 : \n";
	Print3x3Matrix(arr1, 3, 3);
	Fill3x3MatrixWithRandomNumbers(arr2, 3, 3);
	cout << "\nMatrix2 : \n";
	Print3x3Matrix(arr2, 3, 3);
	MultiplyTwo3x3Matrixes(arr1, arr2, arrMultiply,3,3);
	cout << "\nMatrix results : \n";
	Print3x3Matrix(arrMultiply, 3, 3);

	system("pause>0");
	return 0;
}