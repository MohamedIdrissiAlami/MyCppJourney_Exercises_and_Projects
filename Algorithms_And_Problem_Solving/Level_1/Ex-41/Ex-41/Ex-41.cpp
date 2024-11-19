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

struct stTaskDuration
{
	unsigned short NumberOfDays, NumberOfHours, NumberOfMinutes, NumberOfSeconds;
};

stTaskDuration ReadTaskDurationInSeconds()
{
	stTaskDuration TaskDuration;
	TaskDuration.NumberOfDays = ReadPositiveNumber<short>("\nDays = ");
	TaskDuration.NumberOfHours = ReadPositiveNumber<short>("\nHours = ");
	TaskDuration.NumberOfMinutes = ReadPositiveNumber<short>("\nMin = ");
	TaskDuration.NumberOfSeconds = ReadPositiveNumber<short>("\nSec = ");
	return TaskDuration;
}

unsigned int TaskDurationInSeconds(stTaskDuration TaskDuration)
{
	unsigned int DurationInSeconds = 0;
	DurationInSeconds += TaskDuration.NumberOfDays * 24 * 3600;
	DurationInSeconds += TaskDuration.NumberOfHours * 3600;
	DurationInSeconds += TaskDuration.NumberOfMinutes * 60;
	DurationInSeconds += TaskDuration.NumberOfSeconds;
	return DurationInSeconds;
}
int main()
{
	cout << "\nTask duration in seconds = " << TaskDurationInSeconds(ReadTaskDurationInSeconds()) << endl;
	system("pause>0");
	return 0;
}