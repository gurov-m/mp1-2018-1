#include <iostream> 
#include <stdio.h> 
#include <conio.h>
#include <fstream> 
#include <string>
#define numberOfCounts  100 // number of step counts 
using namespace std;
struct DateOftheCountsStart
{
	int startDay;
	int startMonth;
	int startYear;
	DateOftheCountsStart &operator=(const DateOftheCountsStart &tmp2)
	{
		this->startDay = tmp2.startDay;
		this->startMonth = tmp2.startMonth;
		this->startYear = tmp2.startYear;
		return *this;
	}
};
struct AllInfoAboutCount
{
	int day;
	int month;
	int year;
	int hourOfStart;
	int	minOfStart;
	int hourOfEnd;
	int minOfEnd;
	AllInfoAboutCount &operator=(const AllInfoAboutCount &tmp1)
	{
		this->day = tmp1.day;
		this->month = tmp1.month;
		this->year = tmp1.year;
		this->hourOfStart = tmp1.hourOfStart;
		this->minOfStart = tmp1.minOfStart;
		this->hourOfEnd = tmp1.hourOfEnd;
		this->minOfEnd = tmp1.minOfEnd;
		return *this;
	}
	bool operator ==(const AllInfoAboutCount &tmp1) const
	{
		return (this->day == tmp1.day && this->month == tmp1.month && this->year == tmp1.year && this->hourOfStart == tmp1.hourOfStart && this->minOfStart == tmp1.minOfStart && this->hourOfEnd == tmp1.hourOfEnd && this->minOfEnd == tmp1.minOfEnd);
	}
	friend ostream &operator<<(ostream& os, const AllInfoAboutCount &_info);
};
ofstream pedometer_in;
ifstream pedometer_out;
ostream &operator<<(ostream& os, const AllInfoAboutCount &_info)
{
	os << _info.day << '.' << _info.month << '.' << _info.year << '.' << _info.minOfStart << '.' << _info.hourOfStart << '.' << _info.minOfEnd << '.' << _info.hourOfEnd;
	return os;
}
class Pedometer
{
private:
	int StepCounts[numberOfCounts];
	DateOftheCountsStart startDate = {};
	AllInfoAboutCount info[numberOfCounts] = {};
public:
	void SetDateOfTheStartOfCounts(int _startDay, int _startMonth, int _startYear)
	{
		startDate.startDay = _startDay;
		startDate.startMonth = _startMonth;
		startDate.startYear = _startYear;
	}
	DateOftheCountsStart GetDateOfTheStartOfCounts()
	{
		return startDate;
	}
	void SetCount(const int i, int newCount, int _day, int _month, int _year, int stmin, int sthour, int edmin, int edhour)
	{
		StepCounts[i] = newCount;
		info[i].day = _day;
		info[i].month = _month;
		info[i].year = _year;
		info[i].minOfStart = stmin;
		info[i].hourOfStart = sthour;
		info[i].minOfEnd = edmin;
		info[i].hourOfEnd = edhour;
	}
	int GetCount(int ind, int i)
	{
		switch (i)
		{
			case 1:
			{
				return StepCounts[ind];
			}
			case 2:
			{
				return info[ind].day;
			}
			case 3:
			{
				return info[ind].month;
			}
			case 4:
			{
				return info[ind].year;
			}
			case 5:
			{
				return info[ind].minOfStart;
			}
			case 6:
			{
				return info[ind].hourOfStart;
			}
			case 7:
			{
				return info[ind].minOfEnd;
			}
			case 8:
			{
				return info[ind].hourOfEnd;
			}
		}
	}
	double GetTheAverageNumberOfStepsInTheSelectedMonthOrInTheEntireObservationHistory(int _month)
	{
		int steps = 0;
		int k = 0;
		int i = 0;
		int b = 0;
		if (_month == 0)
		{
			for (i = 0; i <= numberOfCounts; i++)
			{
				if (StepCounts[i] != 0)
				{
					b++;
					steps += StepCounts[i];
				}
			}
			return (steps / b);
		}
		else
		{
			for (i = 0; i <= numberOfCounts; i++)
			{
				if (_month == info[i].month)
				{
					k++;
					steps += StepCounts[i];
				}
			}
			return (steps / double(k));
		}
	}
	double GetTheAverageNumberOfStepsOnTheSelectedDayOfTheWeekInTheEntireObservationHistory(int _day)
	{
		int steps = 0;
		int k = 0;
		int days = 0;
		int daysOfLeapYears = 0;
		int help = 0;
		for (int i = 0; i <= numberOfCounts; i++)
		{
			days += (365 * abs(info[i].year - 2000));
			help = info[i].month - 1;
			switch (help)
			{
				case 1:
				{
					days += 28;
					break;
				}
				case 2:
				{
					days += 59;
					break;
				}
				case 3:
				{
					days += 89;
					break;
				}
				case 4:
				{
					days += 120;
					break;
				}
				case 5:
				{
					days += 150;
					break;
				}
				case 6:
				{
					days += 181;
					break;
				}
				case 7:
				{
					days += 212;
					break;
				}
				case 8:
				{
					days += 242;
					break;
				}
				case 9:
				{
					days += 273;
					break;
				}
				case 10:
				{
					days += 303;
					break;
				}
				case 11:
				{
					days += 334;
					break;
				}
			}
			days += (info[i].day - 1);
			for (int i = 1; i <= abs(info[i].year - 2000); i++)
			{
				if ((i % 4) == 0)
				{
					daysOfLeapYears++;
				}
			}
			days += daysOfLeapYears;
			if ((days % 7) == _day)
			{
				k++;
				steps += StepCounts[i];
			}
		}
		return (steps / double(k));
	}
	int GetTheMaximumNumberOfStepsOnTheSelectedDayInTheSelectedMonthOrInTheEntireObservationHistoryAndTheDateWhenItWasReached(int _month, int _i)
	{
		int max = 0;
		int nmax = 0;
		if (_month != 0)
		{
			for (int i = 0; i <= numberOfCounts; i++)
			{
				if (info[i].month == _month)
				{
					if (StepCounts[i] > max)
					{
						max = StepCounts[i];
						nmax = i;
					}
				}
			}
		}
		else
		{
			for (int i = 0; i <= numberOfCounts; i++)
			{
				if (StepCounts[i] > max)
				{
					max = StepCounts[i];
					nmax = i;
				}
			}
		}
		switch (_i)
		{
			case 1:
			{
				return max;
			}
			case 2:
			{
				return info[nmax].day;
			}
			case 3:
			{
				return info[nmax].month;
			}
			case 4:
			{
				return info[nmax].year;
			}
		}
	}
	void SaveHistoryToFile(int k)
	{
		pedometer_in << "Step counts: " << k << endl;
		for (int i = 0; i < k; i++)
		{
			pedometer_in << StepCounts[i] << endl << info[i] << endl;
		}
	}
	void ConsiderHistoryFromFile(int size , int k)
	{
		char y[300];
		for (int i = k; i < (k+size); i++)
		{
			pedometer_out.getline(y, 100, '\n');
			StepCounts[i] = atoi(y);
			pedometer_out.getline(y, 100, '.');
			info[i].day = atoi(y);
			pedometer_out.getline(y, 100, '.');
			info[i].month = atoi(y);
			pedometer_out.getline(y, 100, '.');
			info[i].year = atoi(y);
			pedometer_out.getline(y, 100, '.');
			info[i].minOfStart = atoi(y);
			pedometer_out.getline(y, 100, '.');
			info[i].hourOfStart = atoi(y);
			pedometer_out.getline(y, 100, '.');
			info[i].minOfEnd = atoi(y);
			pedometer_out.getline(y, 100, '\n');
			info[i].hourOfEnd = atoi(y);
		}
	}
};
int main()
{
	int dayOfWeek = 0;
	int _month1 = 0;
	int _month2 = 0;
	int ind = 0;
	int counts = 0;
	int i = 0;
	int k = 0;
	int _stDay = 0;
	int newCount = 0,
		_day = 0,
		_month = 0,
		_year = 0,
		stmin = 0,
		sthour = 0,
		edmin = 0,
		edhour = 0;
	int _stMonth = 0;
	int _stYear = 0;
	DateOftheCountsStart startDate;
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
				cout << "Enter the day: ";
				cin >> _stDay;
				cout << "Enter the month: ";
				cin >> _stMonth;
				cout << "Enter the year: ";
				cin >> _stYear;
				GO.SetDateOfTheStartOfCounts(_stDay, _stMonth, _stYear);
				system("pause");
				system("cls");
				break;
			}
			case 2: // Get date of the start of counts 
			{
				startDate = GO.GetDateOfTheStartOfCounts();
				cout << "day: " << startDate.startDay << endl;
				cout << "month: " << startDate.startMonth << endl;
				cout << "year: " << startDate.startYear << endl;
				system("pause");
				system("cls");
				break;
			}
			case 3: // Set Count 
			{
				cout << "Enter the number of steps: ";
				cin >> newCount;
				cout << "Enter the day: ";
				cin >> _day;
				cout << "Enter the month: ";
				cin >> _month;
				cout << "Enter the year: ";
				cin >> _year;
				cout << "Enter the min of start: ";
				cin >> stmin;
				cout << "Enter the hour of start: ";
				cin >> sthour;
				cout << "Enter the min of end: ";
				cin >> edmin;
				cout << "Enter the hour of end: ";
				cin >> edhour;
				GO.SetCount(k, newCount, _day, _month, _year, stmin, sthour, edmin, edhour);
				k++;
				system("pause");
				system("cls");
				break;
			}
			case 4: // Get Count 
			{
				cout << "Enter the index: ";
				cin >> ind;
				for (i = 1; i <= 8; i++)
				{
					switch (i)
					{
						case 1:
						{
							cout << "Steps: ";
							break;
						}
						case 2:
						{
							cout << "Day: ";
							break;
						}
						case 3:
						{
							cout << "Month: ";
							break;
						}
						case 4:
						{
							cout << "Year: ";
							break;
						}
						case 5:
						{
							cout << "Min of start: ";
							break;
						}
						case 6:
						{
							cout << "Hour of start: ";
							break;
						}
						case 7:
						{
							cout << "Min of end: ";
							break;
						}
						case 8:
						{
							cout << "Hour of end: ";
							break;
						}
					}
					cout << GO.GetCount(ind, i) << endl;
				}
				system("pause");
				system("cls");
				break;
			}
			case 5: // Get the average number of steps in the selected month or in the entire observation history 
			{
				cout << "Enter the month: ";
				cin >> _month1;
				cout << "average number of steps: " << GO.GetTheAverageNumberOfStepsInTheSelectedMonthOrInTheEntireObservationHistory(_month1) << endl;
				system("pause");
				system("cls");
				break;
			}
			case 6: // Get the average number of steps on the selected day of the week in the entire observation history 
			{
				cout << "Choose day of the week" << endl; // reference date is ( 1 of January 2000 (Sunday) )
				cout << "1) Monday" << "\n";
				cout << "2) Tuesday" << "\n";
				cout << "3) Wednesday" << "\n";
				cout << "4) Thursday" << "\n";
				cout << "5) Friday" << "\n";
				cout << "6) Saturday" << "\n";
				cout << "7) Sunday" << "\n";
				cout << "Enter your choice: ";
				cin >> dayOfWeek;
				cout << "\n" << "Average steps on that day in the entire observation history: " << GO.GetTheAverageNumberOfStepsOnTheSelectedDayOfTheWeekInTheEntireObservationHistory(dayOfWeek) << endl;
				system("pause");
				system("cls");
				break;
			}
			case 7: // Get the maximum number of steps on the selected day in the selected month or in the entire observation history and the date when it was reached
			{
				cout << "0) Show result of the entire observation history" << "\n";
				cout << "Choose month " << endl;
				cout << "1) January" << "\n";
				cout << "2) February" << "\n";
				cout << "3) March" << "\n";
				cout << "4) April" << "\n";
				cout << "5) May" << "\n";
				cout << "6) June" << "\n";
				cout << "7) July" << "\n";
				cout << "8) August" << "\n";
				cout << "9) September" << "\n";
				cout << "10) October" << "\n";
				cout << "11) November" << "\n";
				cout << "12) December" << "\n";
				cout << "Enter your choice: ";
				cin >> _month2;
				for (int i = 1; i <= 4; i++)
				{
					switch (i)
					{
						case 1:
						{
							cout << "Steps: ";
							break;
						}
						case 2:
						{
							cout << "Day: ";
							break;
						}
						case 3:
						{
							cout << "Month: ";
							break;
						}
						case 4:
						{
							cout << "Year: ";
							break;
						}
					}
					cout << GO.GetTheMaximumNumberOfStepsOnTheSelectedDayInTheSelectedMonthOrInTheEntireObservationHistoryAndTheDateWhenItWasReached(_month2, i) << endl;
				}
				system("pause");
				system("cls");
				break;
			}
			case 8: // Save history of the step counts to a file 
			{
				pedometer_in.open("C:/Users/Maksim/Desktop/Pedometer.txt");
				GO.SaveHistoryToFile(k);
				pedometer_in.close();
				system("pause");
				system("cls");
				break;
			}
			case 9: // Consider history of the step counts from a file 
			{
				char x[100];
				pedometer_out.open("C:/Users/Maksim/Desktop/Pedometer.txt");
				pedometer_out.getline(x, 100, ' ');
				pedometer_out.getline(x, 100, ' ');
				pedometer_out.getline(x, 100, '\n');
				counts = atoi(x);
				GO.ConsiderHistoryFromFile(counts,k);
				pedometer_out.close();
				k += counts;
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