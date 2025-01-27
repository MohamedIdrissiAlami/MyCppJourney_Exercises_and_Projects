#include <iostream>
using namespace std;

void PrintFibonacciSeries(short Number,short Prev1,short Prev2)
{
	if (Number > 0)
	{
		short FibNumber = Prev1+ Prev2;
		Prev2 = Prev1;
		Prev1 = FibNumber;
		printf("%hd  ", FibNumber);
		PrintFibonacciSeries(--Number, Prev1, Prev2);
	}
}
int main()
{
	PrintFibonacciSeries(20,0,1);
	system("pause>0");
	return 0;
}