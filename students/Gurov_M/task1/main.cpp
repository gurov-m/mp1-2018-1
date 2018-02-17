#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
#include <ctime>
#include <math.h>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
using namespace std;

class Converter
{
private:
	int a;	// переменная отвечающая ща текущий вес в килограммах
public:
	Converter()
	{
		a = 0;
		cout << "Работа конструктора при создании нового объекта: " << endl;
		cout << "a = " << a << " текущий вес в киллограммах" << endl;

	}
	void setConverter()
	{
		cout << "Введите вес в килограммах = а: ";
		cin >> a;
	}

	void getConverter()
	{
		cout << "Текущий вес в килограммах a = " << a << endl;
	}
	void Conversion()
	{
		cout << "в каратах = " << a * 5000 << endl;
		cout << "в граммах = " << a * 1000 << endl;
		cout << "в граммах = " << a * 1000 << endl;
		cout << "в миллиграммах = " << a * 1000000 << endl;
		cout << "в каратах = " << a * 5000 << endl;
		cout << "в унциях = " << a * 35.27396194958 << endl;
		cout << "в пудах = " << a * 0.061 << endl;
		cout << "в фунтах = " << a * 2.2046226218 << endl;
		cout << "в аптечных фунтах  = " << a * 2.2679229035769 << endl;
	}
};
int main()
{
	int b = 0;
	int c = 1;
	setlocale(LC_ALL, "rus");
	Converter C1;
	system("pause");
	system("cls");
	while (c == 1)
	{
		cout << "чтобы изменить текущей вес в килограммах введите 1 = b " << endl;
		cout << "чтобы узнать текущий вес в килограммах введите 2 = b " << endl;
		cout << "чтобы узнать текущей вес в отличных от килограммов единицах веса введите 3 = b" << endl;
		cout << "чтобы чтобы выйти из программы введите любое число отличное от предложенных выше" << endl;
		cout << "введите b =" << " ";
		cin >> b;
		switch (b)
		{
		case 1:
		{
			C1.setConverter();
			system("pause");
			system("cls");
			break;
		}
		case 2:
		{
			C1.getConverter();
			system("pause");
			system("cls");
			break;
		}
		case 3:
		{
			C1.Conversion();
			system("pause");
			system("cls");
			break;
		}
		default:
		{

			c++;
		}
		}
	}
	system("pause");
}