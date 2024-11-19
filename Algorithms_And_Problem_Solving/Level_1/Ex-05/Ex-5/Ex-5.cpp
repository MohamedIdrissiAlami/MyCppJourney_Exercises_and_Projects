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

bool CheckHiringConditionsCase1()
{
	char Answer = 'n';
	cout << "\nDo you have Driver License [Y/N] ? ";
	cin >> Answer;
	return (tolower(Answer) == 'y' && ReadPositiveNumber<short>("\nHow old are you : ") >= 21);
}
bool CheckHiringConditionsCase2()
{
	char Answer = 'n';
	cout << "\nDo you have Recommendation [Y/N] ? ";
	cin >> Answer;
	return (tolower(Answer) == 'y') ? true : CheckHiringConditionsCase1();

}
int main()
{
	cout << (CheckHiringConditionsCase2() ? " Hired." : " Rejected.") << endl;
	system("pause>0");
	return 0;
}