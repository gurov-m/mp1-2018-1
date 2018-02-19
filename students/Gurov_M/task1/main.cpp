#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
#include <math.h>
#include <conio.h>
#include <stdio.h>
using namespace std;
void DataEntry(int _w);
class WeightConverter
{
private:
	int weight;	// argument responsible for the current weight in kilograms
public:
	WeightConverter(int _weight = 0);
	void SetWeightInKilograms(int _weight);
	int GetWeightInKilograms();
	int GetWeightInGrams();
	int GetWeightInCarats();
	int GetWeightInMilligrams();
	double GetWeightInOunces();
	double GetWeightInPonds();
	double GetWeightInPounds();
	double GetWeightInPharmacyPounds();
	WeightConverter& operator=(const WeightConverter& obj)
	{
		weight = obj.weight;
		return *this;
	}
};
int main()
{
	int j = 0;
	int _w = 0;
	int b = 0;
	int c = 1;
	int h = 1;
	setlocale(LC_ALL, "rus");
	WeightConverter C1;
	system("pause");
	system("cls");
	while (c == 1)
	{
		cout << "Set weight in kilograms                b = 1 " << endl;
		cout << "Get current weight in kilograms       b = 2 " << endl;
		cout << "Get weight in other weight units       b = 3 " << endl;
		cout << "Exit b = 4 " << endl;
		cout << "enter b =" << " ";
		cin >> b;
		switch (b)
		{
		case 1:
		{
			DataEntry(_w);
			C1.SetWeightInKilograms(_w);
			system("pause");
			system("cls");
			break;
		}
		case 2:
		{
			C1.GetWeightInKilograms();
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
					C1.GetWeightInGrams();
					cout << " \n";
					system("pause");
					system("cls");
					break;
				}
				case 2:
				{
					cout << " \n";
					C1.GetWeightInCarats();
					cout << " \n";
					system("pause");
					system("cls");
					break;
				}
				case 3:
				{
					cout << " \n";
					C1.GetWeightInMilligrams();
					cout << " \n";
					system("pause");
					system("cls");
					break;
				}
				case 4:
				{
					cout << " \n";
					C1.GetWeightInOunces();
					cout << " \n";
					system("pause");
					system("cls");
					break;
				}
				case 5:
				{
					cout << " \n";
					C1.GetWeightInPonds();
					cout << " \n";
					system("pause");
					system("cls");
					break;
				}
				case 6:
				{
					cout << " \n";
					C1.GetWeightInPounds();
					cout << " \n";
					system("pause");
					system("cls");
					break;
				}
				case 7:
				{
					cout << " \n";
					C1.GetWeightInPharmacyPounds();
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
WeightConverter::WeightConverter(int _weight)
{
	weight = _weight;
}
int WeightConverter::GetWeightInKilograms()
{
	return weight;	
}
void WeightConverter::SetWeightInKilograms(int _weight)
{
	weight = _weight;
}
int WeightConverter::GetWeightInGrams()
{
	return weight * 1000;
}
int WeightConverter::GetWeightInCarats()
{
	return weight * 5000;
}
int WeightConverter::GetWeightInMilligrams()
{
	return weight * 1000000;
}
double WeightConverter::GetWeightInOunces()
{
	return weight * 35.27396194958;
}
double WeightConverter::GetWeightInPonds()
{
	return weight * 0.061;
}
double WeightConverter::GetWeightInPounds()
{
	return weight * 2.2046226218;
}
double WeightConverter::GetWeightInPharmacyPounds()
{
	return weight * 2.2679229035769;
}
void DataEntry(int _w)
{
	cout << "Enter Weight ";
	cin >> _w;
}


