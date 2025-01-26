#include <iostream >
#include <cstdio>
using namespace std;

void PrintMatrix(short arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			printf("%hd  ", arr[i][j]);
		}
		printf("\n");
	}
}

bool IsScalarMatrix(short arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (i == j)
			{
				if (arr[i][j] != arr[0][0])
					return false;
			}
			else
			{
				if (arr[i][j] != 0)
					return false;
			}

		}
	}
	//if you reached here this means that the matrix is identity
	return true;
}

int main()
{
	short arr[3][3] = { {7,0,0},{0,7,0},{0,0,7} };
	cout << "\nMatrix 1: \n";
	PrintMatrix(arr, 3, 3);
	cout << "\n" << (IsScalarMatrix(arr, 3, 3) ? "Yes,matrix is scalar." : "No,matrix is not scalar") << endl;
	system("pause>0");
	return 0;
}