#include <iostream>
using namespace std;

template <typename T>
T ReadNumber(string Message)
{
	T Number = 0;
	cout << Message;
	while ((cin >> Number).fail())
	{
		//user didn't input a valid number .
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "\ninvalid input " << Message;

	}
	return Number;
}
template <typename T>
T ReadPositiveNumber(string Message)
{
	T Number = 0;
	do
	{
		if ((Number = ReadNumber<T>(Message)) < 0)
			cout << "try again with a positive number..";

	} while (Number < 0);
	return Number;
}

short TotalMonthsToPay(float LoanAmount, float MonthlyPayment)
{
	return ceil(LoanAmount/MonthlyPayment);
}

int main()
{
	float LoanAmount = ReadPositiveNumber<float>("\nLoan Amount : ");
	float MonthlyPayment = ReadPositiveNumber<float>("\nMonthlyPayment : ");
	cout << "\nmonths to pay the loan " << TotalMonthsToPay(LoanAmount, MonthlyPayment)<<" month(s)\n";
	system("pause>0");
	return 0;
}