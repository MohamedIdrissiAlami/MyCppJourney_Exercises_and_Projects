#include<iostream>
#include <string >
using namespace std;

string ReadString(string Message = "")
{
	cout << Message;
	string S1;
	getline(cin >> ws, S1);
	return S1;
}
string ReadFullName()
{
	string FirstName = ReadString("\nFirst Name : "), LastName = ReadString("\nLast Name : ");
	return FirstName + " " + LastName;
}
int main()
{
	string FullName = ReadFullName();
	cout << "\nFull Name : " << FullName << endl;
	system("pause>0");
	return 0;
}