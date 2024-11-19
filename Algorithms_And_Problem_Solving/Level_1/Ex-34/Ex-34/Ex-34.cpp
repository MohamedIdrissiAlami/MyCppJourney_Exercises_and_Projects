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

short  CalculateTotalInPennies(short Penney, short Nickel, short Dime, short Quarter, short Dollar)
{
	return Penney + Nickel * 5 + Dime * 10 + Quarter * 25 + Dollar * 100;
}
float CalculateTotalInDollars(short Penney, short Nickel, short Dime, short Quarter, short Dollar)
{
	return (float)CalculateTotalInPennies(Penney, Nickel, Dime, Quarter, Dollar) / 100;
}
int main()
{
	short Penney = ReadPositiveNumber<short>("\nPennies : ");
	short Nickel = ReadPositiveNumber<short>("\nNickels : ");
	short Dime = ReadPositiveNumber<short>("\nDimes : ");
	short Quarter = ReadPositiveNumber<short>("\nQuarters : ");
	short Dollar = ReadPositiveNumber<short>("\nDollars : ");

	cout << "\nTotal In Pennies : " << CalculateTotalInPennies(Penney, Nickel, Dime, Quarter, Dollar);
	cout << "\nTotal In Dollars : " << CalculateTotalInDollars(Penney, Nickel, Dime, Quarter, Dollar);


}
