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

float CalculateTotalBill(float BillValue,float ServiceFee, float SalesTax)
{
		return BillValue * (1 + ServiceFee) * (1+SalesTax);
}
	
int main()
{
	float BillValue = ReadPositiveNumber<float>("\nbill value = ");
	const float ServiceFee = 0.10,SalesTax=0.16;
	cout << "\ntotal bill : " << CalculateTotalBill(BillValue, ServiceFee, SalesTax) << endl;
	system("pause>0");
	return 0;
	
}