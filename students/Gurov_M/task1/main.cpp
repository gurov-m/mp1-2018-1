# include <iostream>
# include <conio.h>
using namespace std;

class Converter
{
private:
	double w;
	double b;
	double m;
	int a;	// переменная отвечающая ща текущий вес в килограммах
public:
	Converter()
	{
		a = 0;
		cout << "Работа конструктора при создании нового объекта: " << endl;
		cout << "a = " << a << endl;

	}
	void setConverter()
	{
		cout << "Введите вес в килограммах = а: ";
		cin >> a;
	}
	void getConverter() //выведем на экран измененные значения
	{
		cout << "Текущий вес в килограммах a = " << a << endl;
	}
};
int main()
{
	int a = 0;
	setlocale(LC_ALL, "rus");
	Converter C1;

	C1.setConverter();
	C1.getConverter();
	system("pause");
}