#include <iostream>
#include <string >
using namespace std;

string ReadString(string Message = "")
{
	string S1 = "";
	cout << Message;
	getline(cin >> ws, S1);
	return S1;
}

void PrintEachWordInString(string S1,string Delim=" ")
{
	string sWord = "";
	short Pos = 0;
	cout << "\nyour string words are : \n";
	while ((Pos = S1.find(Delim)) != std::string::npos)
	{
		sWord = S1.substr(0, Pos);
		S1.erase(0, Pos + Delim.length());
		if (sWord != "")
			cout << sWord << endl;
	}
	//print the last word 
	if (S1 != "")
	{
		cout << S1<<endl;
	}
}

int main()
{
	PrintEachWordInString(ReadString("\nPlease enter your string ? "));
	system("pause>0");
	return 0;
}