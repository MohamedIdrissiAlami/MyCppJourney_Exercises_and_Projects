#include <iostream>
#include <string >
using namespace std;

string ReadString(string Message = "")
{
	string S1 = "";
	cout << Message;
	getline(cin, S1);
	return S1;
}

string TrimLeft(string S1)
{
	for (short i = 0; i < S1.length(); i++)
	{
		if (S1[i] != ' ')
		{
			return S1.substr(i, S1.length());
		}
	}
	return "";
}
//string TrimLeft(string S1)
//{
//	for (short i = 0; i < S1.length(); i++)
//	{
//		if (S1[i] != ' ')
//		{
//			return S1.substr(i, S1.length());
//		}
//	}
//	return "";
//}

string TrimRight(string S1)
{
	for (short i = S1.length()-1; i >=0; i--)
	{
		if (S1[i] != ' ')
		{
			return S1.substr(0, i+1);
		}
	}
	return "";

}

//
//string TrimRight(string S1)
//{
//	for (short i =S1.length()-1; i >= 0; i--)
//	{
//		if (S1[i] != ' ')
//		{
//			return S1.substr(0,i+1);
//		}
//	}
//	return "";
//}
//
//string Trim(string S1)
//{
//	return TrimRight(TrimLeft(S1));
//}


string Trim(string S1)
{
	return TrimRight(TrimLeft(S1));
}

int main()
{
	string S1 = ReadString("\nPlease enter your string ? ");
	cout << "\nyour string : \"" <<S1<< "\"";
	cout << "\nTrim left : \"" << TrimLeft(S1) << "\"";
	cout << "\nTrim right : \"" << TrimRight(S1) << "\"";
	cout << "\nTrim : \"" << Trim(S1) << "\"\n";

	system("pause>0");
	return 0;
}