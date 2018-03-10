#include <iostream>
#include <math.h>
using namespace std;
int factorial(int k);
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
		double sum1 = x;
		for (int i = 1; i <= n; i++)
		{
			sum1 += (pow(-1, (2*i - 1))*pow(x, (2 * i - 1))) / factorial(2 * i - 1);
		}
		return sum1;
	}

	double CalculateCos()
	{
		double sum2 = 1.0;
		for (int i = 1; i <= n; i++)
		{
			sum2 += (pow(-1, i)*pow(x, 2 * i)) / factorial(2 * i);
		}
		return sum2;
	}

	double CalculateExponent()
	{
		double sum3 = 1.0;
		for (int i = 1; i <= n; i++)
		{
			sum3 += pow(x, i) / factorial(i);
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
		int num = *k;
		if (num == 1)
			return 1.0;
		else
			return pow(x, num) / factorial(num);
	}

	double CalculateCurrentElementOfSin(int *k)
	{
		int num = *k;
		if (num == 1)
			return x;
		else
			return (pow(-1, (2*num - 1))*pow(x, (2 * num - 1))) / factorial(2 * num - 1);
	}

	double CalculateCurrentElementOfCos(int *k)
	{
		int num = *k;
		if (num == 1)
			return 1.0;
		else
			return (pow(-1, num)*pow(x, 2 * num)) / factorial(2 * num);
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

int factorial(int k)
{
	if (k == 0) return 1;
	else return k * factorial(k - 1);
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
				cout << "\n" << T.CalculateCos() - ReferenceValueOfCos(T) << endl;
			if (choice == 2)
				cout << "\n" << T.CalculateSin() - ReferenceValueOfSin(T) << endl;
			if (choice == 3)
				cout << "\n" << T.CalculateExponent() - ReferenceValueOfExponent(T) << endl;
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


