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

string UpperFirstLettersOfEachWord(string S1)
{
	bool IsFirstLetter = true;
	for (short i = 0; i < S1.length(); i++)
	{
		if (S1[i] != ' ' && IsFirstLetter)
		{
			S1[i] = toupper(S1[i]);
		}
		IsFirstLetter = (S1[i]==' '? true:false);
	}
	return S1;
}

int main()
{
	string S1 = ReadString("\nPlease enter your string : ");
	cout<<"\nyour string after conversion is : \""<<UpperFirstLettersOfEachWord(S1)<<"\"\n";
	system("pause>0");
	return 0;
}