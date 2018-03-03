#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
using namespace std;
class Line
{
private:
	int   length;
	char *string;
public:
	Line()
	{
		string = new char[41];
	}
	~Line()
	{
		delete[]string;
	}
	void SetString(char* word)
	{
		int length = strlen(word);
		delete[]string;
		string = new char[length + 1];
		strcpy(string, word);
	}
	char* GetString()
	{
		return string;
	}
	int GetStringLength()
	{
		return length;
	}
	bool isPalindrom()
	{
		for (int i = 0; i < length / 2; i++)
			if (string[i] != string[length - 1 - i])
				return -1;
		return 1;
	}
	Line& operator=(Line &obj1)
	{
		if (this == &obj1)
			return *this;
		else
			if (length != obj1.length)
			{
				delete[] string;
				string = new char[obj1.length + 1];
			}
		strcpy(string, obj1.string);
		length = obj1.length;
		return *this;
	}
	Line(const Line &obj2)
	{
		length = obj2.length;
		string = new char[length + 1];
		strcpy(string, obj2.string);
	}
	char GetSymbol(int index)
	{
		return string[index];
	}
	void ChangeSymbolFromString(int index2, char change)
	{
		string[index2] = change;
	}
	char GetPartOfString(int k)
	{
		return string[k];
	}
	int HowManyDifferentLatinSymbolsInString()
	{
		int counter = 0;
		int indicator;
		for (int i = 0; i < length; i++)
		{
			indicator = 0;
			for (int j = 0; j < i; j++)
			{
				if (string[i] != string[j])					
						if (isalpha(string[i]))
							indicator++;
			}
			if (indicator == i)
				counter++;
		}
		return counter;
	}
};
int main()
{

	char word;
	int start = 0;
	int _length = 0;
	int index = 0;
	int h = 1;
	int index2 = 0;
	char change = 0;
	int j = 0;
	Line S1;
	cout << "Enter the string: ";
	cin >> word;
	S1.SetString(&word);
	while (h == 1)
	{
		cout << "Set string                     inter 0 \n" <<
			"Get string                     inter 1 \n" <<
			"Get lenght of string           inter 2 \n" <<
			"Get symbol                     inter 3 \n" <<
			"Change symbol                  inter 4 \n" <<
			"Get part of string             inter 5 \n" <<
			"Check on palindrom             inter 6 \n" <<
			"Different symbols              inter 7 \n" <<
			"Exit                           inter 8 \n" << endl;
		cin >> j;
		switch (j)
		{
		case 0:
		{
			cout << "Enter the string: ";
			cin >> word;
			S1.SetString(&word);
			system("pause");
			system("cls");
			break;
		}
		case 1:
		{
			cout << "\n" << S1.GetString() << endl;
			system("pause");
			system("cls");
			break;
		}
		case 2:
		{
			cout << "\n" << S1.GetStringLength() << endl;
			system("pause");
			system("cls");
			break;
		}
		case 3:
		{
			cout << "Enter index: ";
			cin >> index;
			cout << S1.GetSymbol(index) << endl;
			system("pause");
			system("cls");
			break;
		}
		case 4:
		{
			cout << "\n" << "Enter index: ";
			cin >> index2;
			cout << "\n" << "Enter text: ";
			cin >> change;
			S1.ChangeSymbolFromString(index2, change);
			system("cls");
			break;
		}
		case 5:
		{
			cout << "\n" << "Enter index: ";
			cin >> start;
			cout << "\n" << "Enter length: ";
			cin >> _length;
			for (int i = start; i < (start + _length); i++)
			{
				cout << S1.GetPartOfString(i);
			}
			cout << "\n";
			system("pause");
			system("cls");
			break;
		}
		case 6:
		{
			if (S1.isPalindrom() == 1)
				cout << "Word is a Palindrom" << endl;
			else
			{
				cout << "Word is not a Palindrom" << endl;
			}
			system("pause");
			system("cls");
			break;
		}
		case 7:
		{
			cout << "\n" << S1.HowManyDifferentLatinSymbolsInString() << endl;
			system("pause");
			system("cls");
			break;
		}
		case 8:
		{
			h = 0;
			break;
		}
		}
	}
}