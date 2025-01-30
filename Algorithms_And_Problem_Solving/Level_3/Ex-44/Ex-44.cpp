#include <iostream>
#include <string>
using namespace std;

string ReadString(string Message = "")
{
	string S1 = "";
	cout << Message;
	getline(cin >> ws, S1);
	return S1;
}

string RemovePunctuations(string S1)
{
	string S2 = "";
	for (short i = 0; i < S1.length(); i++)
	{
		if (!ispunct(S1[i]))
		{
			S2 += S1[i];
		}
	}
	return S2;
}

int main()
{
	string  S1 = "\nWelcom to jordan , jordan is a nice country; it's amazing!.";
	cout << "\nOriginal String : " << S1;
	cout << "\nstring after replace : " << RemovePunctuations(S1);
	system("pause>0");
	return 0;
}
