#include <iostream>
#include <math.h>
using namespace std;
void ArgumentEntry(double *_x);
void NumberOfElementsEntry(int *_n);
void NumberOfElementEntry(int *_n);
class TaylorSeries
{
	double x;
	int    n;
public:
	TaylorSeries(double _argument = 0, int _number_of_elements = 0)
	{
		x = _argument;
		n = _number_of_elements;
	}
	~TaylorSeries()
	{
		cout << "Destructor was called  " << endl;
	}
	TaylorSeries& operator=(const TaylorSeries& obj)
	{
		x = obj.x;
		n = obj.n;
		return *this;
	}
	int GetNumberOfElements()
	{
		return n;
	}
	double GetArgument()
	{
		return x;
	}
	double CalculateSin()
	{
		double y = x;
		double sum1 = 0.0;
		for (int i = 1; i <= n; i++)
		{
			sum1 += y;
			y *= -1.0 * x * x / ((2 * i) * (2 * i + 1));
		}
		return sum1;
	}
	double CalculateCos()
	{
		double y = 1.0;
		double sum2 = 0.0;
		for (int i = 1; i <= n; i++)
		{
			sum2 += y;
			y *= -1.0 * x * x / ((2 * i - 1) * (2 * i));
		}
		return sum2;
	}
	double CalculateExponent()
	{
		double y = 1.0;
		double sum3 = 1.0;
		for (int i = 1; i <= n; i++)
		{
			y *= (x / i);
			sum3 += y;
		}
		return sum3;
	}
	void SetArgument(double *_argument)
	{
		x = *_argument;
	}
	void SetNumberOfElements(int *_number)
	{
		n = *_number;
	}
	friend void PrintExponent(const TaylorSeries &q1);
	friend void PrintSin(const TaylorSeries &q2);
	friend void PrintCos(const TaylorSeries &q3);
	friend  double ReferenceValueOfCos(const TaylorSeries &s1);
	friend	double ReferenceValueOfSin(const TaylorSeries &s2);
	friend	double ReferenceValueOfExponent(const TaylorSeries &s3);
	double CalculateCurrentElementOfExponent(int *k)
	{
		double u = 1.0;
		double i = 0.0;
		int num = *k;
		if (num == 1)
			return 1.0;
		else
			i = pow(x, num);
		for (int j = 1; j <= num; j++)
			u *= j;
		return (i / u);
	}
	double CalculateCurrentElementOfSin(int *k)
	{
		double u = 1.0;
		double i = 0.0;
		int num = *k;
		if (num == 1)
			return x;
		else
			return
			i = pow(-1, (2 * num - 1))*pow(x, (2 * num - 1));
		for (int j = 1; j <= (2 * num - 1); j++)
			u *= j;
		return (i / u);
	}
	double CalculateCurrentElementOfCos(int *k)
	{
		double u = 1.0;
		double i = 0.0;
		int num = *k;
		if (num == 1)
			return 1.0;
		else
			return
			i = pow(-1, num)*pow(x, 2 * num);
		for (int j = 1; j <= (2 * num); j++)
			u *= j;
		return (i / u);
	}
};
double ReferenceValueOfCos(const TaylorSeries &s1)
{
	return cos(s1.x);
}
double ReferenceValueOfSin(const TaylorSeries &s2)
{
	return sin(s2.x);
}
double ReferenceValueOfExponent(const TaylorSeries &s3)
{
	return exp(s3.x);
}
void PrintExponent(const TaylorSeries &q1)
{
	cout << "1";
	for (int i = 1; i < q1.n; i++)
	{
		cout << "+" << "x^" << i << "/" << i << "!";
	}
	cout << endl;
}
void PrintSin(const TaylorSeries &q2)
{
	cout << "x";
	for (int i = 2; i <= q2.n; i++)
	{
		if (fmod(i, 2) == 0)
			cout << "-";
		else
			cout << "+";
		cout << "x^" << (2 * i - 1) << "/" << (2 * i - 1) << "!";
	}
	cout << endl;
}
void PrintCos(const TaylorSeries &q3)
{
	cout << "1";
	for (int i = 2; i <= q3.n; i++)
	{
		if (fmod(i, 2) == 0)
			cout << "-";
		else
			cout << "+";
		cout << "x^" << (2 * i - 2) << "/" << (2 * i - 2) << "!";
	}
	cout << endl;
}
void NumberOfElementsEntry(int *_n)
{
	cout << "Enter number of elements: ";
	cin >> *_n;
}
void ArgumentEntry(double *_x)
{
	cout << "Enter argument x: ";
	cin >> *_x;
}
void NumberOfElementEntry(int *_n)
{
	cout << "Enter number of element: ";
	cin >> *_n;
}
int main()
{
	int choice = 0;
	double _x;
	int _n;
	int  k = 0;
	int h = 1;
	int j = 0;
	TaylorSeries T;
	while (h == 1)
	{
		cout << " 0)Set function\n "
			<< "1)Get current function\n "
			<< "2)Set number of elements\n "
			<< "3)Get number of elements\n "
			<< "4)Get formula of series\n "
			<< "5)Calculate the value of series\n "
			<< "6)Calculate the value of current element\n "
			<< "7)Calculate deviation from the reference value\n "
			<< "8)Exit\n " << endl;
		cin >> j;
		switch (j)
		{
		case 0:
		{
			cout << "Choose function \n"
				<< "Enter 1 = cosx  \n"
				<< "Enter 2 = sinx  \n"
				<< "Enter 3 = exponent" << endl;
			cin >> choice;
			system("pause");
			system("cls");
			break;
		}
		case 1:
		{
			if (choice == 1)
				cout << "cosx" << endl;
			if (choice == 2)
				cout << "sinx" << endl;
			if (choice == 3)
				cout << "exponent" << endl;
			system("pause");
			system("cls");
			break;
		}
		case 2:
		{
			NumberOfElementsEntry(&_n);
			T.SetNumberOfElements(&_n);
			system("pause");
			system("cls");
			break;
		}
		case 3:
		{
			cout << "\n" << T.GetNumberOfElements() << endl;
			system("pause");
			system("cls");
			break;
		}
		case 4:
		{
			if (choice == 1)
				PrintCos(T);
			if (choice == 2)
				PrintSin(T);
			if (choice == 3)
				PrintExponent(T);
			system("pause");
			system("cls");
			break;
		}
		case 5:
		{
			NumberOfElementsEntry(&_n);
			T.SetNumberOfElements(&_n);
			ArgumentEntry(&_x);
			T.SetArgument(&_x);
			if (choice == 1)
				cout << "\n" << T.CalculateCos() << endl;
			if (choice == 2)
				cout << "\n" << T.CalculateSin() << endl;
			if (choice == 3)
				cout << "\n" << T.CalculateExponent() << endl;
			system("pause");
			system("cls");
			break;
		}
		case 6:
		{
			ArgumentEntry(&_x);
			T.SetArgument(&_x);

			NumberOfElementEntry(&k);
			if (choice == 1)
				cout << "\n" << T.CalculateCurrentElementOfCos(&k) << endl;
			if (choice == 2)
				cout << "\n" << T.CalculateCurrentElementOfSin(&k) << endl;
			if (choice == 3)
				cout << "\n" << T.CalculateCurrentElementOfExponent(&k) << endl;
			system("pause");
			system("cls");
			break;
		}
		case 7:
		{
			NumberOfElementsEntry(&_n);
			T.SetNumberOfElements(&_n);
			ArgumentEntry(&_x);
			T.SetArgument(&_x);
			if (choice == 1)
				cout << "\n" << abs(T.CalculateCos() - ReferenceValueOfCos(T)) << endl;
			if (choice == 2)
				cout << "\n" << abs(T.CalculateSin() - ReferenceValueOfSin(T)) << endl;
			if (choice == 3)
				cout << "\n" << abs(T.CalculateExponent() - ReferenceValueOfExponent(T)) << endl;
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
		system("pause");
	}
}

