#include <iostream>
#include <stdio.h>
using namespace std;
class Pedometer
{
private:
	int *StepCounts; // dynamic array of step counts
	int numberOfCounts = 0; // number of step counts
	struct DateOfCount
	{
		int day, month, year;
	} *date; // struct which will describe the step count ( date of count )
	struct ParticularTimeOfCount
	{
		int hourOfStart, minOfStart;
		int hourOfEnd, minOfEnd;
	} *time; // struct which will describe the step count ( time of count )
public:
	Pedometer(int _numberOfCounts = 0)
	{
		numberOfCounts = _numberOfCounts;
		StepCounts = new int[numberOfCounts];
		date = new DateOfCount[numberOfCounts];
		time = new ParticularTimeOfCount[numberOfCounts];
	}
	~Pedometer()
	{
		cout << "Destructor was called" << endl;
	}
	void SetDateOfTheStartOfCounts()
	{

	}
	int GetDateOfTheStartOfCounts()
	{

	}
	void SetCount()
	{

	}
	int GetCount()
	{

	}
	int GetTheAverageNumberOfStepsInTheSelectedMonthOrInTheEntireObservationHistory()
	{

	}
	int GetTheMaximumNumberOfStepsOnTheSelectedDayInTheSelectedMonthOrInTheEntireObservationHistoryAndTheDateWhenItWasReached()
	{

	}
	void SaveHistoryToFile()
	{

	}
	void ConsiderHistoryFromFile()
	{

	}
};
int main()
{
	Pedometer GO;
	int h = 1;
	int j = 0;
	while (h == 1)
	{
		cout << "1) Set date of the start of counts\n " << endl;
		cout << "2) Get date of the start of counts\n " << endl;
		cout << "3) Set Count\n " << endl;
		cout << "4) Get Count\n " << endl;
		cout << "5) Get the average number of steps in the selected month or in the entire observation history\n " << endl;
		cout << "6) Get the average number of steps on the selected day of the week in the entire observation history\n " << endl;
		cout << "7) Get the maximum number of steps on the selected day in the selected month or in the entire observation history and the date when it was reached\n " << endl;
		cout << "8) Save history of the step counts to a file\n " << endl;
		cout << "9) Consider history of the step counts from a file\n " << endl;
		cout << "10) Exit\n " << endl;
		cout << "Your choice: ";
		cin >> j;
		system("cls");
		switch (j)
		{
		case 1: // Set date of the start of counts
		{

			system("pause");
			system("cls");
			break;
		}
		case 2: //  Get date of the start of counts
		{

			system("pause");
			system("cls");
			break;
		}
		case 3: // Set Count
		{

			system("pause");
			system("cls");
			break;
		}
		case 4: // Get Count
		{

			system("pause");
			system("cls");
			break;
		}
		case 5: // Get the average number of steps in the selected month or in the entire observation history
		{

			system("pause");
			system("cls");
			break;
		}
		case 6: // Get the average number of steps on the selected day of the week in the entire observation history
		{

			system("pause");
			system("cls");
			break;
		}
		case 7: // Get the maximum number of steps on the selected day in the selected month or in the entire observation history and the date when it was reached
		{

			system("pause");
			system("cls");
			break;
		}
		case 8: // Save history of the step counts to a file
		{

			system("pause");
			system("cls");
			break;
		}
		case 9: // Consider history of the step counts from a file
		{

			system("pause");
			system("cls");
			break;
		}
		case 10: // Exit
		{
			h = 0;
			break;
		}
		}
	}
}