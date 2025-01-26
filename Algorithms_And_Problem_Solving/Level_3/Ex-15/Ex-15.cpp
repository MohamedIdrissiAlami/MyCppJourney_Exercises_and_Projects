#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

template <typename T>
T ReadNumber(string Message = "")
{
	T Number = 0;
	cout << Message;

	while ((cin >> Number).fail())
	{
		//user entered a nonvalid input 
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "\ninvalid input!";
		cin >> Number;
	}
	return Number;
}

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
			arr[i][j] = RandomNumber(1, 100);
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

short CountElementInMatrix(short arr[3][3], short Rows, short Cols, short NumberToCheck)
{
	short Counter=0;
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (arr[i][j] == NumberToCheck)
				++Counter;
		}

	}
	return Counter;
}

int main()
{
	//seeds the random numbers generator in C++,called only once.  
	srand((unsigned)time(NULL));
	short arr[3][3];
	Fill3x3MatrixWithRandomNumbers(arr, 3, 3);
	cout << "\nMatrix : \n";
	Print3x3Matrix(arr, 3, 3);
	short NumberToCheck = ReadNumber<short>("\nEnter the number to count in matrix : ");
	cout << "\nnumber \'" << NumberToCheck << "\' count is : " << CountElementInMatrix(arr, 3, 3, NumberToCheck) << endl;
	system("pause>0");
	return 0;
}