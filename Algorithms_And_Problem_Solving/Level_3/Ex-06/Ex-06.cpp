#include <iostream >
using namespace std;

void FillMatrixOrderedNumbers(short arr[3][3], short Rows, short Cols)
{
	short Counter = 1;
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			arr[i][j] = Counter++;
		}
	}
}

void PrintMatrix(short arr[3][3], short Rows, short Cols)
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

int main()
{
	short arr[3][3];
	FillMatrixOrderedNumbers(arr, 3, 3);
	cout << "\nthe following is a 3x3 ordered matrix : \n";
	PrintMatrix(arr, 3, 3);

	system("pause>0");
	return 0;

}