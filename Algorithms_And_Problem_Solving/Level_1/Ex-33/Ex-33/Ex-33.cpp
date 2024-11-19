#include <iostream >
using namespace std;

template <typename T>
T ReadNumber(string Message = "")
{
	T Number = 0;
	cout << Message;
	while ((cin >> Number).fail())
	{
		//user did'nt input a valid number:
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "\nInvalid input ! " << Message;

	}
	return Number;
}
template <typename T>
T ReadPositiveNumber(string Message = "")
{
	T Number = 0;
	do
	{
		Number = ReadNumber<T>(Message);
		if (Number <= 0)
			cout << "\ntry again with a positive number..";
	} while (Number < 0);
	return Number;
}

int CalculateCommission(int SalesAmount)
{ 
	return SalesAmount * (SalesAmount >= 1e6 ? 0.01 : SalesAmount >= 5e5 ? 0.02 : SalesAmount >= 1e5 ? 0.03 : SalesAmount >= 5e4 ? 0.05 : 0);
}

int main()
{
	int SalesAmount = ReadPositiveNumber<int>("Sales Amount : ");
	cout << "\nyour commission is : " << CalculateCommission(SalesAmount) << endl;
	system("pause>0");
	return 0;
}