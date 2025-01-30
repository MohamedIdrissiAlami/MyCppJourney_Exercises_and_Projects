#include <iostream> 
#include <string >
using namespace std;

template<typename T>  
T ReadNumber(string Message = "")
{
	T Number = 0;
	cout << Message;
	while ((cin >> Number).fail())
	{
		//user didn't input a valid number   
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "\nwrong input! try again with a valid number ..";
		cin >> Number;
	}
	return Number;
}

template<typename T>
T ReadPositiveNumber(string Message = "")
{
	T Number = 0;
	do
	{
		Number = ReadNumber<T>(Message);
	} while (Number<0);
	return Number;
}

string NumberToText(int Number)
{
	if (Number == 0)
		return "";
	if (Number > 0 && Number < 10)
	{
		string sNumber[9] = { "One","Two","Three","Four","Five","Six","Seven","Eight","Nine" };
		return sNumber[Number - 1];
	}
	if (Number >= 10 && Number < 20)
	{
		string sNumber[10] = { "Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };
		return sNumber[Number % 10 - 1];
	}
	if (Number >= 20 && Number < 100)
	{
		string sNumber[10] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
		return sNumber[Number / 10] + " " + NumberToText(Number % 10);
	}
	if (Number < 1000 && Number >= 100)
	{
		return NumberToText(int(Number / 100)) + " Hundred " + NumberToText(Number % 100);
	}
	if (Number >= 1000 && Number < 1000000)
	{
		return NumberToText(int(Number / 1000)) + " Thousand , " + NumberToText(Number % 1000);
	}
	if (Number >= 1000000 && Number < 1000000000)
	{
		return NumberToText(int(Number / 1000000)) + " Million , " + NumberToText(Number % 1000000);
	}
	if (Number >= 1000000000 && Number <= 4000000000)
	{
		return NumberToText(int(Number / 1000000000)) + " Billon , " + NumberToText(Number % 1000000000);
	}

	if (Number > 4000000000)
	{
		return " Zero ";
	}

}

int main()
{
	int Number = ReadPositiveNumber<int>("\nenter a positive number ? ");
	cout << "\n" << NumberToText(Number);

	system("pause>0");
	return 0;
}