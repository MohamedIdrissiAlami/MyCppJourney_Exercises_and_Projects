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

stTaskDuration SecondsToTaskDuration(unsigned int TotalSeconds)
{
	const unsigned int SecondsPerDay = 24 * 3600;
	const unsigned short SecondsPerHour = 3600;
	const unsigned short SecondsPerMinutes = 60;
	unsigned short Reminder = 0;

	stTaskDuration TaskDuration;
	TaskDuration.NumberOfDays = floor(TotalSeconds / SecondsPerDay);
	Reminder = TotalSeconds % SecondsPerDay;

	TaskDuration.NumberOfHours = floor(Reminder / SecondsPerHour);
	Reminder %= SecondsPerHour;

	TaskDuration.NumberOfMinutes = floor(Reminder / SecondsPerMinutes);
	Reminder %= SecondsPerMinutes;

	TaskDuration.NumberOfSeconds = Reminder;

	return TaskDuration;


}

void PrintTaskDurationDetails(stTaskDuration TaskDuration)
{
	cout << "\n" << TaskDuration.NumberOfDays << " : "
		<< TaskDuration.NumberOfHours << " : "
		<< TaskDuration.NumberOfMinutes << " : "
		<< TaskDuration.NumberOfSeconds<<endl;
}

int main()
{
	unsigned int TotalSeconds = ReadPositiveNumber<unsigned int>("\nPlease enter total seconds : ");
	PrintTaskDurationDetails(SecondsToTaskDuration(TotalSeconds));
	system("pause>0");
	return 0;
}