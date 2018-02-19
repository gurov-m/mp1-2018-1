#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
#include <ctime>
#include <math.h>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
using namespace std;
void data_entry(int *_w);
class Weight_Converter
{
private:

	int weight;	// argument responsible for the current weight in kilograms

public:

	Weight_Converter(int _weight = 0);

	void Set_Weight_In_Kilograms(int *_weight);

	void Show_Current_Weight_In_Kilograms();

	void Get_Weight_In_Grams();

	void Get_Weight_In_Carats();

	void Get_Weight_In_Milligrams();

	void Get_Weight_In_Ounces();

	void Get_Weight_In_Ponds();

	void Get_Weight_In_Pounds();

	void Get_Weight_In_Pharmacy_Pounds();

};
int main()
{
	int j = 0;
	int _w = 0;
	int b = 0;
	int c = 1;
	int h = 1;
	setlocale(LC_ALL, "rus");
	Weight_Converter C1;
	system("pause");
	system("cls");
	while (c == 1)
	{
		cout << "Set weight in kilograms                b = 1 " << endl;
		cout << "Show current weight in kilograms       b = 2 " << endl;
		cout << "Get weight in other weight units       b = 3 " << endl;
		cout << "Exit b = 4 " << endl;
		cout << "enter b =" << " ";
		cin >> b;
		switch (b)
		{
		case 1:
		{
			data_entry(&_w);
			C1.Set_Weight_In_Kilograms(&_w);
			system("pause");
			system("cls");
			break;
		}
		case 2:
		{
			C1.Show_Current_Weight_In_Kilograms();
			system("pause");
			system("cls");
			break;
		}
		case 3:
		{
			while (h == 1)
			{
				cout << "Get weight in grams           j = 1 " << endl;
				cout << "Get weight in carats          j = 2 " << endl;
				cout << "Get weight in milligrams      j = 3 " << endl;
				cout << "Get weight in ounces          j = 4 " << endl;
				cout << "Get weight in ponds           j = 5 " << endl;
				cout << "Get weight in pounds          j = 6 " << endl;
				cout << "Get weight in pharmacy pounds j = 7 " << endl;
				cout << "Exit                          j = 8 " << endl;
				cout << "enter j =" << " ";
				cin >> j;
				switch (j)
				{
				case 1:
				{
					cout << " \n";
					C1.Get_Weight_In_Grams();
					cout << " \n";
					system("pause");
					system("cls");
					break;
				}
				case 2:
				{
					cout << " \n";
					C1.Get_Weight_In_Carats();
					cout << " \n";
					system("pause");
					system("cls");
					break;
				}
				case 3:
				{
					cout << " \n";
					C1.Get_Weight_In_Milligrams();
					cout << " \n";
					system("pause");
					system("cls");
					break;
				}
				case 4:
				{
					cout << " \n";
					C1.Get_Weight_In_Ounces();
					cout << " \n";
					system("pause");
					system("cls");
					break;
				}
				case 5:
				{
					cout << " \n";
					C1.Get_Weight_In_Ponds();
					cout << " \n";
					system("pause");
					system("cls");
					break;
				}
				case 6:
				{
					cout << " \n";
					C1.Get_Weight_In_Pounds();
					cout << " \n";
					system("pause");
					system("cls");
					break;
				}
				case 7:
				{
					cout << " \n";
					C1.Get_Weight_In_Pharmacy_Pounds();
					cout << " \n";
					system("pause");
					system("cls");
					break;
				}
				case 8:
				{
					h = 0;
					system("pause");
					system("cls");
					break;
				}
				}
			}
			break;
		}
		case 4:
		{
			c = 0;
			break;
		}

		}
	}
	system("pause");
}
Weight_Converter::Weight_Converter(int _weight)
{
	weight = _weight;
}
void Weight_Converter::Show_Current_Weight_In_Kilograms()
{
	cout << weight << "     \n";
}
void Weight_Converter::Set_Weight_In_Kilograms(int *_weight)
{
	weight = *_weight;
}
void Weight_Converter::Get_Weight_In_Grams()
{
	cout << weight * 1000;
}
void Weight_Converter::Get_Weight_In_Carats()
{
	cout << weight * 5000;
}
void Weight_Converter::Get_Weight_In_Milligrams()
{
	cout << weight * 1000000;
}
void Weight_Converter::Get_Weight_In_Ounces()
{
	cout << weight * 35.27396194958;
}
void Weight_Converter::Get_Weight_In_Ponds()
{
	cout << weight * 0.061;
}
void Weight_Converter::Get_Weight_In_Pounds()
{
	cout << weight * 2.2046226218;
}
void Weight_Converter::Get_Weight_In_Pharmacy_Pounds()
{
	cout << weight * 2.2679229035769;
}
void data_entry(int *_w)
{
	cout << "Enter Weight ";
	cin >> *_w;
}


