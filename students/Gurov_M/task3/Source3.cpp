#include <iostream>
#include <math.h>
using namespace std;
class TaylorSeries
{
	double x;
	int    n;
	int choice;
public:
	TaylorSeries(double _argument = 0, int _number_of_elements = 0, int _choice = 0)
	{
		x = _argument;
		n = _number_of_elements;
		choice = _choice;
	}
	~TaylorSeries()
	{
		cout << "Destructor was called  " << endl;
	}
	TaylorSeries& operator=(const TaylorSeries& obj)
	{
		x = obj.x;
		n = obj.n;
		choice = obj.choice;
		return *this;
	}
	int GetNumberOfElements()
	{
		return n;
	}
	void SetArgument(double _argument)
	{
		x = _argument;
	}
	void SetChoice(int _choice)
	{
		choice = _choice;
	}
	void SetNumberOfElements(int _number)
	{
		n = _number;
	}
	friend  double CalculateSeries(const TaylorSeries &s1);
	friend  void   PrintSeries(const TaylorSeries &q1);
	friend  double ReferenceValue(const TaylorSeries &s1);
	double CalculateCurrentElementOfExponent(int k)
	{
		double u = 1.0;
		double i = 0.0;
		int num = k;
		if (num == 1)
			return 1.0;
		else
		{
			i = pow(x, num);
			for (int j = 1; j <= num; j++)
				u *= j;
			return (i / u);
		}
	}
	double CalculateCurrentElementOfSin(int k)
	{
		double u = 1.0;
		double i = 0.0;
		int num = k;
		if (num == 1)
			return x;
		else
		{
			i = pow(-1, (2 * num - 1))*pow(x, (2 * num - 1));
			for (int j = 1; j <= (2 * num - 1); j++)
				u *= j;
			return (i / u);
		}
	}
	double CalculateCurrentElementOfCos(int k)
	{
		double u = 1.0;
		double i = 0.0;
		int num = k;
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
double CalculateSeries(const TaylorSeries &s1)
{
	double g = s1.x;
	if (s1.choice == 1)
		g = 1.0;

	double sum2 = 0.0;
	for (int i = 1; i <= s1.n; i++)
	{
		sum2 += g;
		g *= -1.0 * s1.x * s1.x / ((2 * i - 1) * (2 * i));
	}
	return sum2;
	if (s1.choice == 2)
		g = s1.x;
	double sum1 = 0.0;
	for (int i = 1; i <= s1.n; i++)
	{
		sum1 += g;
		g *= -1.0 * s1.x * s1.x / ((2 * i) * (2 * i + 1));
	}
	return sum1;
	if (s1.choice == 3)
		g = 1.0;
	double sum3 = 1.0;
	for (int i = 1; i <= s1.n; i++)
	{
		g *= (s1.x / i);
		sum3 += g;
	}
	return sum3;
}
double ReferenceValue(const TaylorSeries &s1)
{
	if (s1.choice == 1)
		return cos(s1.x);
	if (s1.choice == 2)
		return sin(s1.x);
	if (s1.choice == 3)
		return exp(s1.x);
	return cos(s1.x);
}
void   PrintSeries(const TaylorSeries &q1)
{
	if (q1.choice == 1)
	{
		cout << "1";
		for (int i = 2; i <= q1.n; i++)
		{
			if (fmod(i, 2) == 0)
				cout << "-";
			else
				cout << "+";
			cout << "x^" << (2 * i - 2) << "/" << (2 * i - 2) << "!";
		}
		cout << endl;
	}
	if (q1.choice == 2)
	{
		cout << "x";
		for (int i = 2; i <= q1.n; i++)
		{
			if (fmod(i, 2) == 0)
				cout << "-";
			else
				cout << "+";
			cout << "x^" << (2 * i - 1) << "/" << (2 * i - 1) << "!";
		}
		cout << endl;
	}
	if (q1.choice == 3)
	{
		cout << "1";
		for (int i = 1; i < q1.n; i++)
		{
			cout << "+" << "x^" << i << "/" << i << "!";
		}
		cout << endl;
	}
}
int main()
{
	int choice = 0;
	double _x = 0;
	int _n = 0;
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
			T.SetChoice(choice);
			system("pause");
			system("cls");
			break;
		}
		case 1:
		{
			if (choice == 0)
				cout << "You didnt choose any function" << endl;
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
			cout << "\n" << "Enter number of elements: ";
			cin >> _n;
			T.SetNumberOfElements(_n);
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
			cout << "\n" << "Enter number of elements: ";
			cin >> _n;
			T.SetNumberOfElements(_n);
			PrintSeries(T);
			system("pause");
			system("cls");
			break;
		}
		case 5:
		{
			cout << "\n" << "Enter number of elements: ";
			cin >> _n;
			T.SetNumberOfElements(_n);
			cout << "\n" << "Enter argument x: ";
			cin >> _x;
			T.SetArgument(_x);
			cout << "\n" << CalculateSeries(T) << endl;
			system("pause");
			system("cls");
			break;
		}
		case 6:
		{
			cout << "\n" << "Enter argument x: ";
			cin >> _x;
			T.SetArgument(_x);
			cout << "\n" << "Enter number of element: ";
			cin >> k;
			if (choice == 1)
				cout << "\n" << T.CalculateCurrentElementOfCos(k) << endl;
			if (choice == 2)
				cout << "\n" << T.CalculateCurrentElementOfSin(k) << endl;
			if (choice == 3)
				cout << "\n" << T.CalculateCurrentElementOfExponent(k) << endl;
			system("pause");
			system("cls");
			break;
		}
		case 7:
		{
			cout << "\n" << "Enter number of elements: ";
			cin >> _n;
			T.SetNumberOfElements(_n);
			cout << "\n" << "Enter argument x: ";
			cin >> _x;
			T.SetArgument(_x);
			cout << "\n" << abs(CalculateSeries(T) - ReferenceValue(T)) << endl;
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

