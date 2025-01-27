#include <iostream>
using namespace std; 

void PrintFibonacciSeries(short N)
{
	short FibNumber = 1,Prev1=0,Prev2=0;
	while (N-->0)
	{
		printf("%hd  ", FibNumber);
		Prev2 = Prev1;
		Prev1 = FibNumber;
		FibNumber = Prev1 + Prev2;
		
	}

}
int main()
{
	PrintFibonacciSeries(10);
	system("pause>0");
	return 0;
}