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
	void SaveChoiceInClass(int _choice)
	{
		choice = _choice;
	}
	void SetNumberOfElements(int _number)
	{
		n = _number;
	}
	friend  void   PrintSeries(const TaylorSeries &q1);
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
	double CalculateSeries()
	{
		double sum = 0;
		double g = 0;
		switch (choice)
		{
		case 1:
		{
			g = 1.0;
			sum = 0.0;
			for (int i = 1; i <= n; i++)
			{
				sum += g;
				g *= -1.0 * x * x / ((2 * i - 1) * (2 * i));
			}
			return sum;
			break;
		}
		case 2:
		{
			g = x;
			sum = 0.0;
			for (int i = 1; i <= n; i++)
			{
				sum += g;
				g *= -1.0 * x * x / ((2 * i) * (2 * i + 1));
			}
			return sum;
			break;
		}
		case 3:
		{

			g = 1.0;
			sum = 1.0;
			for (int i = 1; i <= n; i++)
			{
				g *= (x / i);
				sum += g;
			}
			return sum;
			break;
		}
		}
	}
	double GetDeviationValueOfSeries()
	{
		double sum = 0;
		double g = 0;
		switch (choice)
		{
		case 1:
		{
			g = 1.0;
			sum = 0.0;

			for (int i = 1; i <= n; i++)
			{
				sum += g;
				g *= -1.0 * x * x / ((2 * i - 1) * (2 * i));
			}
			return abs(sum - cos(x));
			break;
		}
		case 2:
		{
			g = x;
			sum = 0.0;
			for (int i = 1; i <= n; i++)
			{
				sum += g;
				g *= -1.0 * x * x / ((2 * i) * (2 * i + 1));
			}
			return abs(sum - sin(x));
			break;
		}
		case 3:
		{

			g = 1.0;
			sum = 1.0;
			for (int i = 1; i <= n; i++)
			{
				g *= (x / i);
				sum += g;
			}
			return abs(sum - exp(x));
			break;
		}
		}
	}
};
void   PrintSeries(const TaylorSeries &q1)
{

	switch (q1.choice)
	{
	case 1:
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
		break;
	}
	case 2:
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
		break;
	}
	case 3:
	{
		cout << "1";
		for (int i = 1; i < q1.n; i++)
		{
			cout << "+" << "x^" << i << "/" << i << "!";
		}
		cout << endl;
		break;
	}
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
			T.SaveChoiceInClass(choice);
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
			cout << "\n" << T.CalculateSeries() << endl;
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
			cout << "\n" << T.GetDeviationValueOfSeries() << endl;
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

