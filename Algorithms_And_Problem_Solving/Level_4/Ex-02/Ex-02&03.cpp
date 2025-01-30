#include <iostream >
using namespace std;

short ReadPositiveNumber(string Message = "")
{
	short Number = 0;
	do
	{
		cout << Message;
		cin >> Number;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "\ntry again..";
			cin >> Number;
		}
	} while (Number<0);
	return Number;
}

bool IsLeapYear(short Year)
{
	/*all years which are perfectly divisible by 4 are leap years,
	except for century years(Years ending with 00),which are leap years only if they are perfectly divisible by 400*/
	return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);

}

int main()
{
	if (IsLeapYear(ReadPositiveNumber("\nPlease enter a year : ")))
	{
		cout << "\nLeap year.";
	}
	else
		cout << "\nNot leap year.";
	system("pause>0");
	return 0;
}
