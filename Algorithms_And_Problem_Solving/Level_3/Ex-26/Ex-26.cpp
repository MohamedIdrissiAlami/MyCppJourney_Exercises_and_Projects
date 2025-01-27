#include <iostream >
#include <string >
using namespace std;

string ReadString(string Message = "")
{
	cout << Message;
	string S1 = "";
	getline(cin >> ws, S1);//ignore whitespaces
	return S1;
}

string UpperAllString(string S1)
{
	for (short i = 0; i < S1.length(); i++)
	{
		S1[i] = toupper(S1[i]);
	}
	return S1;
}

string LowerAllString(string S1)
{
	for (short i = 0; i < S1.length(); i++)
	{
		S1[i] = tolower(S1[i]);
	}
	return S1;
}


int main()
{
	string S1 = ReadString("\nPlease enter your string : ");
	cout << "\nstring after upper : \"" << (S1=UpperAllString(S1)) << "\"\n";
	cout << "\nstring after lower : \"" << (S1=LowerAllString(S1)) << "\"\n";


	system("pause>0");
	return 0;
}