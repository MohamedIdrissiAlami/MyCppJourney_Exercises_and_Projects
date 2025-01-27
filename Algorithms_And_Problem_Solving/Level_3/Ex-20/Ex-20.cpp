#include <iostream>
using namespace std;

void PrintMatrix(short Matrix[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			printf("%0*hd  ", 2, Matrix[i][j]);
		}
		printf("\n");
	}
}

bool IsPalindromeMatrix(short Matrix[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols / 2; j++)
		{
			if (Matrix[i][j] != Matrix[i][Cols - 1 - j])
			{
				return false;
			}
		}
	}
	//if you reached here this means that the matrix is palindrome
	return true;

}

int main()
{
	short Matrix[3][3] = { {1,2,1},{5,8,5},{9,7,9} };
	cout << "\nMatrix1 : \n";
	PrintMatrix(Matrix, 3, 3);
	cout << "\nMatrix1 is " << (IsPalindromeMatrix(Matrix,3,3)? "":"Not ") << "Palindrome\n";

	system("pause>0");
	return 0;
}