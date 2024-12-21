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

string EncryptText(short EncryptionKey, string OriginalText)
{
	for (short i = 0; i < OriginalText.length(); i++)
	{
		OriginalText[i] =char(int(OriginalText[i])+ EncryptionKey);
	}
	return OriginalText;
}
string DescryptText(short EncryptionKey, string EncryptedText)
{
	for (short i = 0; i < EncryptedText.length(); i++)
	{
		EncryptedText[i] = char(int(EncryptedText[i]) - EncryptionKey);
	}
	return EncryptedText;

}

int main()
{
	string Text = ReadString("\nEnter a text to encrypt : ");
	cout << "\nText before encryption : " << Text;
	cout << "\nText after Encryption : " <<(Text= EncryptText(2, Text));
	cout << "\nText after descyption : " << DescryptText(2, Text);
	system("pause>0");
	return 0;
}