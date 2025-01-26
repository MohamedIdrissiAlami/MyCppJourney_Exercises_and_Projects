#include <iostream>
#include <cstdlib>
using namespace std;


void Print3x3Matrix(short arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			printf("%0*hd   ", 2, arr[i][j]);
		}
		printf("\n");
	}
}

bool CheckMatrixesEquality(short arr1[3][3], short arr2[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (arr1[i][j] != arr2[i][j])
				return false;
		}
	}
	//if you reached here this means that the two matrixes are equal.
	return true;
}

int main()
{
	short arr1[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
	short arr2[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
	cout << "\nMatrix 1 : \n";
	Print3x3Matrix(arr1, 3, 3);
	cout << "\nMatrix 2 : \n";
	Print3x3Matrix(arr2, 3, 3);

	cout << "\n" << ((CheckMatrixesEquality(arr1, arr2, 3, 3)) ? "Yes,the two matrixes are equal.":"No,the two matrix are not equal")<<"\n";
	system("pause>0");
	return 0;
}