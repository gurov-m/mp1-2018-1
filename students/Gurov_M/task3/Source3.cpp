#include <iostream>
#include <math.h>
using namespace std;
class TaylorSeries
{
private:
	double x;
	int n;
	int functionNumber;
public:
	TaylorSeries(double _argument = 0, int _number_of_elements = 0, int _functionNumber = 0)
	{
		x = _argument;
		n = _number_of_elements;
		functionNumber = _functionNumber;
	}
	~TaylorSeries()
	{
		cout << "Destructor was called" << endl;
	}
	TaylorSeries& operator=(const TaylorSeries &obj)
	{
		x = obj.x;
		n = obj.n;
		functionNumber = obj.functionNumber;
		return *this;
	}
	TaylorSeries(const TaylorSeries &obj2)
	{
		x = obj2.x;
		n = obj2.n;
		functionNumber = obj2.functionNumber;
	}
	int GetNumberOfElements()
	{
		return n;
	}
	void SetArgument(double _argument)
	{
		x = _argument;
	}
	void SetFunctionNumber(int _functionNumber)
	{
		functionNumber = _functionNumber;
	}
	void SetNumberOfElements(int _number)
	{
		n = _number;
	}
	int GetFunctionNumber()
	{
		return functionNumber;
	}
	friend void PrintSeries(const TaylorSeries &q1);
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
		{
			i = pow(-1, num)*pow(x, 2 * num);
			for (int j = 1; j <= (2 * num); j++)
				u *= j;
			return (i / u);
		}
	}
	double CalculateSeries()
	{
		double sum = 0;
		double g = 0;
		switch (functionNumber)
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
		}
		}
	}
	double GetAccuracyOfSeries()
	{
		double sum = 0;
		double g = 0;
		switch (functionNumber)
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
		}
		}
	}
};
void PrintSeries(const TaylorSeries &q1)
{
	switch (q1.functionNumber)
	{
	case 1:
	{
		cout << "1";
		for (int i = 2; i <= q1.n; i++)
		{
			if (i & 1)
			{
				cout << "+";
			}
			else
			{
				cout << "-";
			}
			cout << "x^(" << (2 * i - 2) << ")/" << (2 * i - 2) << "!";
		}
		break;
	}
	case 2:
	{
		cout << "x";
		for (int i = 2; i <= q1.n; i++)
		{
			if (i & 1)
			{
				cout << "+";
			}
			else
			{
				cout << "-";
			}
			cout << "x^(" << (2 * i - 1) << ")/" << (2 * i - 1) << "!";
		}
		break;
	}
	case 3:
	{
		cout << "1";
		for (int i = 1; i < q1.n; i++)
			cout << "+x^(" << i << ")/" << i << "!";
		break;
	}
	}
}
int main()
{
	int functionNumber = 0;
	double _x = 0;
	int _n = 0;
	int k = 0;
	int h = 1;
	int j = 0;
	TaylorSeries T;
	while (h == 1)
	{
		cout << "1) Set function\n " << endl;
		cout << "2) Get function\n " << endl;
		cout << "3) Set number of elements\n " << endl;
		cout << "4) Get number of elements\n " << endl;
		cout << "5) Get formula of series\n " << endl;
		cout << "6) Calculate the value of series\n " << endl;
		cout << "7) Calculate the value of current element\n " << endl;
		cout << "8) Calculate accuracy of the series\n " << endl;
		cout << "9) Exit\n " << endl;
		cout << "Your choice: ";
		cin >> j;
		system("cls");
		switch (j)
		{
		case 1:
		{
			cout << "Choose function \n" << endl;
			cout << "Enter 1 = cosx  \n" << endl;
			cout << "Enter 2 = sinx  \n" << endl;
			cout << "Enter 3 = exponent\n" << endl;
			cout << "Your choice: ";
			cin >> functionNumber;
			T.SetFunctionNumber(functionNumber);
			system("pause");
			system("cls");
			break;
		}
		case 2:
		{
			switch (T.GetFunctionNumber())
			{
			case 1:
			{
				cout << "\n" << "cosx" << endl;
				break;
			}
			case 2:
			{
				cout << "\n" << "sinx" << endl;
				break;
			}
			case 3:
			{
				cout << "\n" << "exponent" << endl;
				break;
			}
			}
			system("pause");
			system("cls");
			break;
		}
		case 3:
		{
			cout << "\n" << "Enter number of elements: ";
			cin >> _n;
			T.SetNumberOfElements(_n);
			system("pause");
			system("cls");
			break;
		}
		case 4:
		{
			cout << "\n" << T.GetNumberOfElements() << endl;
			system("pause");
			system("cls");
			break;
		}
		case 5:
		{
			cout << "\n" << "Enter number of elements: ";
			cin >> _n;
			T.SetNumberOfElements(_n);
			cout << endl;
			PrintSeries(T);
			cout << endl;
			system("pause");
			system("cls");
			break;
		}
		case 6:
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
		case 7:
		{
			cout << "\n" << "Enter argument x: ";
			cin >> _x;
			T.SetArgument(_x);
			cout << "\n" << "Enter number of element: ";
			cin >> k;
			switch (T.GetFunctionNumber())
			{
			case 1:
			{
				cout << "\n" << T.CalculateCurrentElementOfCos(k) << endl;
				break;
			}
			case 2:
			{
				cout << "\n" << T.CalculateCurrentElementOfSin(k) << endl;
				break;
			}
			case 3:
			{
				cout << "\n" << T.CalculateCurrentElementOfExponent(k) << endl;
				break;
			}
			}
			system("pause");
			system("cls");
			break;
		}
		case 8:
		{
			cout << "\n" << "Enter number of elements: ";
			cin >> _n;
			T.SetNumberOfElements(_n);
			cout << "\n" << "Enter argument x: ";
			cin >> _x;
			T.SetArgument(_x);
			cout << "\n" << T.GetAccuracyOfSeries() << endl;
			system("pause");
			system("cls");
			break;
		}
		case 9:
		{
			h = 0;
			break;
		}
		}
	}
}


