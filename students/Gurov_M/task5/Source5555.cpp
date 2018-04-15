#include <iostream> 
#include <stdio.h> 
#include <cstdlib>
#include <conio.h>
#include <fstream> 
#include <vector>
#include <string>
using namespace std;
struct Index
{
	int indexLower[100];
	int indexStandart[100];
	int indexUpper[100];
};
struct FullName
{
	char name[100];
	char surname[100];
	char patronymic[100];
	FullName& operator = (const FullName &n)
	{
		for (int i = 0; i <= 100; i++)
		{
			this->name[i] = n.name[i];
			this->surname[i] = n.surname[i];
			this->patronymic[i] = n.patronymic[i];
		}
		return *this;
	}
	void SetName()
	{
		cout << "\nEnter surname: ";
		cin >> surname;
		cout << "\nEnter name: ";
		cin >> name;
		cout << "\nEnter patronymic: ";
		cin >> patronymic;
	}
	friend ostream& operator<<(ostream& os, FullName& obj);
};
ostream& operator<<(ostream& os, FullName& obj)
{
	os << "Surname: " << obj.surname << endl;
	os << "Name: " << obj.name << endl;
	os << "Patronymic: " << obj.patronymic << endl;
	return os;
}
struct Ticket
{
	int date[3];
	string departureStation;
	string arrivalStation;
	int trainNumber = 0;
	int seatNumber = 0;
	int wagonNumber = 0;
	FullName names[10] = {};
	friend ostream& operator<<(ostream& os, Ticket& obj);
};
ostream& operator<<(ostream& os, Ticket& obj)
{
	os << "Date: ";
	for (int i = 0; i < 3; i++)
	{
		os << obj.date[i] << ".";
	}
	os << endl;
	os << "Train number: " << obj.trainNumber << endl;
	os << "Wagon number: " << obj.wagonNumber << endl;
	os << "Seat number: " << obj.seatNumber << endl;
	for (int i = 0; i < 3; i++)
	{
		os << obj.names[i];
	}
	os << endl;
	os << "Departure station: " << obj.departureStation << endl;
	os << "Arrival station: " << obj.arrivalStation << endl;
	return os;
}
struct ExpessTrainCompartmentWagon
{
	int upperBerth[17];
	int upperBerthPrice = 2500;
	int lowerBerth[17];
	int lowerBerthPrice = 3000;
};
struct ExpessTrainSecondClassWagon
{
	int upperBerth[27];
	int upperBerthPrice = 1500;
	int lowerBerth[27];
	int lowerBerthPrice = 2000;
};
struct BrandedTrainCompartmentWagon
{
	int upperBerth[18];
	int upperBerthPrice = 3000;
	int lowerBerth[18];
	int lowerBerthPrice = 3500;
};
struct BrandedTrainSecondClassWagon
{
	int upperBerth[27];
	int upperBerthPrice = 2000;
	int lowerBerth[27];
	int lowerBerthPrice = 2500;
};
struct BrandedTrainSleepingWagon
{
	int lowerBerth[18];
	int lowerBerthPrice = 5000;
};
struct LastochkaWagon
{
	int places[100];
	int priceForTickets = 500; // 500 rubles for each place
};
struct LastochkaTrain
{
	LastochkaWagon standart[8];
};
struct BrandedTrain
{
	BrandedTrainSleepingWagon sleepingWagon[2];
	BrandedTrainCompartmentWagon compartment[6];
	BrandedTrainSecondClassWagon secondClass[4];
};
struct ExpessTrain
{
	ExpessTrainSecondClassWagon secondClass[8];
	ExpessTrainCompartmentWagon compartment[4];
};
struct NewOrder
{
	int date[3];
	int direction;
	int trainNumber;
	int wagonNumber;
	int wagonType;
	int berth[2];
	int lastochkaTickets;
	int brandedSWTickets;
	FullName names[10] = {};
	friend ostream& operator<<(ostream& os, NewOrder& obj);
	NewOrder& operator = (const NewOrder &order)
	{
		for (int i = 0; i < 2; i++)
		{
			this->berth[i] = order.berth[i];
		}
		for (int i = 0; i < 3; i++)
		{
			this->date[i] = order.date[i];
		}
		this->trainNumber = order.trainNumber;
		this->brandedSWTickets = order.brandedSWTickets;
		this->lastochkaTickets = order.lastochkaTickets;
		this->direction = order.direction;
		this->wagonNumber = order.wagonNumber;
		this->wagonType = order.wagonType;
		return *this;
	}
};
ostream& operator<<(ostream& os, NewOrder& obj)
{
	os << "Date: " << obj.date[0] << "." << obj.date[1] << "." << obj.date[2] << "." << endl;
	switch (obj.direction)
	{
	case 1:
	{
		os << "Direction:  Nizhny Novgorod - Moscow" << endl;
		break;
	}
	case 2:
	{
		os << "Direction:  Moscow - Nizhny Novgorod" << endl;
		break;
	}
	}
	os << "Number of train: " << obj.trainNumber << endl;
	switch (obj.wagonType)
	{
	case 0:
	{
		os << "Wagon of Lastochka train" << endl;
		break;
	}
	case 1:
	{
		os << "Sleeping" << endl;
		break;
	}
	case 2:
	{
		os << "Compartment" << endl;
		break;
	}
	case 3:
	{
		os << "Second class" << endl;
		break;
	}
	}
	os << "Number of wagon: " << obj.wagonNumber << endl;
	os << "Tickets on Lastochka: " << obj.lastochkaTickets << endl;
	os << "Tickets on branded Sleeping wagon: " << obj.brandedSWTickets << endl;
	os << "Tickets on berths: \n";
	for (int i = 0; i < 2; i++)
	{
		os << obj.berth[i] << endl;
	}
	os << "Full names of passengers: " << endl;
	for (int i = 0; i < (obj.lastochkaTickets + obj.brandedSWTickets + obj.berth[0] + obj.berth[1]); i++)
	{
		os << "Passenger number " << (i + 1) << endl;
		os << obj.names[i];
	}
	return os;
}
class RailwayTicketOffice;
class GorkyRailway
{
private:
	vector<Ticket> tickets[100];
	LastochkaTrain lastochka[6];
	int lastochkaNumber[6];
	BrandedTrain branded[2];
	int brandedNumber[2];
	ExpessTrain expess[2];
	int expessTrainNumber[2];
	vector<Index> numberOfSeats;
public:
	GorkyRailway()
	{
		for (int i = 0; i < 3; i++)
		{
			lastochkaNumber[i] = (i + 10);
		}
		for (int i = 3; i < 6; i++)
		{
			lastochkaNumber[i] = (i + 17);
		}
		brandedNumber[0] = 13;
		brandedNumber[1] = 23;
		expessTrainNumber[0] = 14;
		expessTrainNumber[1] = 24;
	}
	friend RailwayTicketOffice;
};
class RailwayTicketOffice
{
private:
	Ticket newTicket = {};
	NewOrder order;
	GorkyRailway RT;
	vector<NewOrder> orders;
public:
	friend GorkyRailway;
	void CreateTickets(int k)
	{
		if ((orders[k - 1].trainNumber > 9 && orders[k - 1].trainNumber < 13) || (orders[k - 1].trainNumber > 19 && orders[k - 1].trainNumber < 23))
		{
			for (int j = 0; j < orders[k - 1].lastochkaTickets; j++)
			{
				for (int i = 0; i < 3; i++)
				{
					newTicket.date[i] = orders[k - 1].date[i];
				}
				newTicket.trainNumber = orders[k - 1].trainNumber;
				newTicket.wagonNumber = orders[k - 1].wagonNumber;
				newTicket.names[j] = orders[k - 1].names[j];
				switch (orders[k - 1].direction)
				{
					case 1:
					{
						newTicket.departureStation = "Nizhny Novgorod";
						newTicket.arrivalStation = "Moscow";
					}
					case 2:
					{
						newTicket.departureStation = "Moscow";
						newTicket.arrivalStation = "Nizhny Novgorod";
					}
				}
				newTicket.seatNumber = RT.numberOfSeats[k - 1].indexStandart[j];
				RT.tickets[j].push_back(newTicket);
				newTicket = {};
			}
		}
		if ((orders[k - 1].trainNumber == 13) || (orders[k - 1].trainNumber == 23))
		{
			switch (orders[k - 1].wagonType)
			{
				case 1: // SW 
				{
					for (int j = 0; j < orders[k - 1].brandedSWTickets; j++)
					{
						for (int i = 0; i < 3; i++)
						{
							newTicket.date[i] = orders[k - 1].date[i];
						}
						newTicket.trainNumber = orders[k - 1].trainNumber;
						newTicket.wagonNumber = orders[k - 1].wagonNumber;
						newTicket.names[j] = orders[k - 1].names[j];
						switch (orders[k - 1].direction)
						{
							case 1:
							{
								newTicket.departureStation = "Nizhny Novgorod";
								newTicket.arrivalStation = "Moscow";
							}
							case 2:
							{
								newTicket.departureStation = "Moscow";
								newTicket.arrivalStation = "Nizhny Novgorod";
							}
						}
						newTicket.seatNumber = RT.numberOfSeats[k - 1].indexStandart[j];
						RT.tickets[j].push_back(newTicket);
						newTicket = {};
					}
					break;
				}
				case 2: // Compartment
				{
					for (int j = 0; j < orders[k - 1].berth[0]; j++)
					{
						for (int i = 0; i < 3; i++)
						{
							newTicket.date[i] = orders[k - 1].date[i];
						}
						newTicket.trainNumber = orders[k - 1].trainNumber;
						newTicket.wagonNumber = orders[k - 1].wagonNumber;
						newTicket.names[j] = orders[k - 1].names[j];
						switch (orders[k - 1].direction)
						{
							case 1:
							{
								newTicket.departureStation = "Nizhny Novgorod";
								newTicket.arrivalStation = "Moscow";
							}
							case 2:
							{
								newTicket.departureStation = "Moscow";
								newTicket.arrivalStation = "Nizhny Novgorod";
							}
						}
						newTicket.seatNumber = RT.numberOfSeats[k - 1].indexStandart[j];
						RT.tickets[j].push_back(newTicket);
						newTicket = {};
					}
					for (int p = orders[k - 1].berth[0]; p < orders[k - 1].berth[0] + orders[k - 1].berth[1]; p++)
					{
						for (int i = 0; i < 3; i++)
						{
							newTicket.date[i] = orders[k - 1].date[i];
						}
						newTicket.trainNumber = orders[k - 1].trainNumber;
						newTicket.wagonNumber = orders[k - 1].wagonNumber;
						newTicket.names[p] = orders[k - 1].names[p];
						switch (orders[k - 1].direction)
						{
							case 1:
							{
								newTicket.departureStation = "Nizhny Novgorod";
								newTicket.arrivalStation = "Moscow";
							}
							case 2:
							{
								newTicket.departureStation = "Moscow";
								newTicket.arrivalStation = "Nizhny Novgorod";
							}
						}
						newTicket.seatNumber = RT.numberOfSeats[k - 1].indexStandart[p];
						RT.tickets[p].push_back(newTicket);
						newTicket = {};
					}
					break;
				}
				case 3: // Second class
				{
					for (int j = 0; j < orders[k - 1].berth[0]; j++)
					{
						for (int i = 0; i < 3; i++)
						{
							newTicket.date[i] = orders[k - 1].date[i];
						}
						newTicket.trainNumber = orders[k - 1].trainNumber;
						newTicket.wagonNumber = orders[k - 1].wagonNumber;
						newTicket.names[j] = orders[k - 1].names[j];
						switch (orders[k - 1].direction)
						{
							case 1:
							{
								newTicket.departureStation = "Nizhny Novgorod";
								newTicket.arrivalStation = "Moscow";
							}
							case 2:
							{
								newTicket.departureStation = "Moscow";
								newTicket.arrivalStation = "Nizhny Novgorod";
							}
						}
						newTicket.seatNumber = RT.numberOfSeats[k - 1].indexStandart[j];
						RT.tickets[j].push_back(newTicket);
						newTicket = {};
					}
					for (int p = orders[k - 1].berth[0]; p < orders[k - 1].berth[0] + orders[k - 1].berth[1]; p++)
					{
						for (int i = 0; i < 3; i++)
						{
							newTicket.date[i] = orders[k - 1].date[i];
						}
						newTicket.trainNumber = orders[k - 1].trainNumber;
						newTicket.wagonNumber = orders[k - 1].wagonNumber;
						newTicket.names[p] = orders[k - 1].names[p];
						switch (orders[k - 1].direction)
						{
							case 1:
							{
								newTicket.departureStation = "Nizhny Novgorod";
								newTicket.arrivalStation = "Moscow";
							}
							case 2:
							{
								newTicket.departureStation = "Moscow";
								newTicket.arrivalStation = "Nizhny Novgorod";
							}
						}
						newTicket.seatNumber = RT.numberOfSeats[k - 1].indexStandart[p];
						RT.tickets[p].push_back(newTicket);
						newTicket = {};
					}
					break;
				}
			}
		}
		if ((orders[k - 1].trainNumber == 14) || (orders[k - 1].trainNumber == 24))
		{
			switch (orders[k - 1].wagonType)
			{
				case 2: // Compartment
				{
					for (int j = 0; j < orders[k - 1].berth[0]; j++)
					{
						for (int i = 0; i < 3; i++)
						{
							newTicket.date[i] = orders[k - 1].date[i];
						}
						newTicket.trainNumber = orders[k - 1].trainNumber;
						newTicket.wagonNumber = orders[k - 1].wagonNumber;
						newTicket.names[j] = orders[k - 1].names[j];
						switch (orders[k - 1].direction)
						{
							case 1:
							{
								newTicket.departureStation = "Nizhny Novgorod";
								newTicket.arrivalStation = "Moscow";
							}
							case 2:
							{
								newTicket.departureStation = "Moscow";
								newTicket.arrivalStation = "Nizhny Novgorod";
							}
						}
						newTicket.seatNumber = RT.numberOfSeats[k - 1].indexStandart[j];
						RT.tickets[j].push_back(newTicket);
						newTicket = {};
					}
					for (int p = orders[k - 1].berth[0]; p < orders[k - 1].berth[0] + orders[k - 1].berth[1]; p++)
					{
						for (int i = 0; i < 3; i++)
						{
							newTicket.date[i] = orders[k - 1].date[i];
						}
						newTicket.trainNumber = orders[k - 1].trainNumber;
						newTicket.wagonNumber = orders[k - 1].wagonNumber;
						newTicket.names[p] = orders[k - 1].names[p];
						switch (orders[k - 1].direction)
						{
							case 1:
							{
								newTicket.departureStation = "Nizhny Novgorod";
								newTicket.arrivalStation = "Moscow";
							}
							case 2:
							{
								newTicket.departureStation = "Moscow";
								newTicket.arrivalStation = "Nizhny Novgorod";
							}
						}
						newTicket.seatNumber = RT.numberOfSeats[k - 1].indexStandart[p];
						RT.tickets[p].push_back(newTicket);
						newTicket = {};
					}
					break;
				}
				case 3: // Second class
				{
					for (int j = 0; j < orders[k - 1].berth[0]; j++)
					{
						for (int i = 0; i < 3; i++)
						{
							newTicket.date[i] = orders[k - 1].date[i];
						}
						newTicket.trainNumber = orders[k - 1].trainNumber;
						newTicket.wagonNumber = orders[k - 1].wagonNumber;
						newTicket.names[j] = orders[k - 1].names[j];
						switch (orders[k - 1].direction)
						{
							case 1:
							{
								newTicket.departureStation = "Nizhny Novgorod";
								newTicket.arrivalStation = "Moscow";
							}
							case 2:
							{
								newTicket.departureStation = "Moscow";
								newTicket.arrivalStation = "Nizhny Novgorod";
							}
						}
						newTicket.seatNumber = RT.numberOfSeats[k - 1].indexStandart[j];
						RT.tickets[j].push_back(newTicket);
						newTicket = {};
					}
					for (int p = orders[k - 1].berth[0]; p < orders[k - 1].berth[0] + orders[k - 1].berth[1]; p++)
					{
						for (int i = 0; i < 3; i++)
						{
							newTicket.date[i] = orders[k - 1].date[i];
						}
						newTicket.trainNumber = orders[k - 1].trainNumber;
						newTicket.wagonNumber = orders[k - 1].wagonNumber;
						newTicket.names[p] = orders[k - 1].names[p];
						switch (orders[k - 1].direction)
						{
							case 1:
							{
								newTicket.departureStation = "Nizhny Novgorod";
								newTicket.arrivalStation = "Moscow";
							}
							case 2:
							{
								newTicket.departureStation = "Moscow";
								newTicket.arrivalStation = "Nizhny Novgorod";
							}
						}
						newTicket.seatNumber = RT.numberOfSeats[k - 1].indexStandart[p];
						RT.tickets[p].push_back(newTicket);
						newTicket = {};
					}
					break;
				}
			}
		}
	}
	void DeleteOrder(int k)
	{
		if ((orders[k - 1].trainNumber > 9 && orders[k - 1].trainNumber < 13) || (orders[k - 1].trainNumber > 19 && orders[k - 1].trainNumber < 23))
		{
			int help1 = orders[k - 1].lastochkaTickets;
			for (int i = 0; i < 6; i++)
			{
				if (RT.lastochkaNumber[i] == orders[k - 1].trainNumber)
				{
					for (int g = 0; g < 8; g++)
					{
						if ((g + 1) == orders[k - 1].wagonNumber)
						{
							for (int j = 0; j < 100; j++)
							{
								for (int h = 0; h < help1; h++)
								{
									if (RT.numberOfSeats[k - 1].indexStandart[h] == j + 1)
									{
										RT.lastochka[i].standart[g].places[j] = 0;
									}
								}
							}
						}
					}
				}
			}
		}
		if ((orders[k - 1].trainNumber == 13) || (orders[k - 1].trainNumber == 23))
		{
			int k = 0;
			int help2 = orders[k - 1].brandedSWTickets;
			for (int i = 0; i < 2; i++)
			{
				if (RT.brandedNumber[i] == orders[k - 1].trainNumber)
				{
					switch (orders[k - 1].wagonType)
					{
						case 1: // SW 
						{
							for (int g = 0; g < 2; g++)
							{
								if ((g + 1) == orders[k - 1].wagonNumber)
								{
									for (int j = 0; j < 18; j++)
									{
										for (int h = 0; h < help2; h++)
										{
											if (RT.numberOfSeats[k - 1].indexStandart[h] == j + 1)
											{
												RT.branded[i].sleepingWagon[g].lowerBerth[j] = 0;
											}
										}
									}
								}
							}
							break;
						}
						case 2: // Compartment
						{
							int help3 = orders[k - 1].berth[0];
							int help4 = orders[k - 1].berth[1];
							for (int g = 0; g < 6; g++)
							{
								if ((g + 1) == orders[k - 1].wagonNumber)
								{
									for (int j = 0; j < 18; j++)
									{
										for (int h = 0; h < help4; h++)
										{
											if (RT.numberOfSeats[k - 1].indexLower[h] == j + 1)
											{
												RT.branded[i].compartment[g].lowerBerth[j] = 0;
											}
										}
										for (int h = 0; h < help3; h++)
										{
											if (RT.numberOfSeats[k - 1].indexUpper[h] == j + 1)
											{
												RT.branded[i].compartment[g].upperBerth[j] = 0;
											}
										}
									}
								}
							}
							break;
						}
						case 3: // Second class
						{
							int help3 = orders[k - 1].berth[0];
							int help4 = orders[k - 1].berth[1];
							for (int g = 0; g < 4; g++)
							{
								if ((g + 1) == orders[k - 1].wagonNumber)
								{
									for (int j = 0; j < 27; j++)
									{
										for (int h = 0; h < help4; h++)
										{
											if (RT.numberOfSeats[k - 1].indexLower[h] == j + 1)
											{
												RT.branded[i].secondClass[g].lowerBerth[j] = 0;
											}
										}
										for (int h = 0; h < help3; h++)
										{
											if (RT.numberOfSeats[k - 1].indexUpper[h] == j + 1)
											{
												RT.branded[i].secondClass[g].upperBerth[j] = 0;
											}
										}
									}
								}
							}
							break;
						}
					}
				}
			}
		}
		if ((orders[k - 1].trainNumber == 14) || (orders[k - 1].trainNumber == 24))
		{
			for (int i = 0; i < 2; i++)
			{
				if (RT.expessTrainNumber[i] == orders[k - 1].trainNumber)
				{
					switch (orders[k - 1].wagonType)
					{
						case 2: // Compartment
						{
							int help3 = orders[k - 1].berth[0];
							int help4 = orders[k - 1].berth[1];
							for (int g = 0; g < 4; g++)
							{
								if ((g + 1) == order.wagonNumber)
								{
									for (int j = 0; j < 18; j++)
									{
										for (int h = 0; h < help4; h++)
										{
											if (RT.numberOfSeats[k - 1].indexLower[h] == j + 1)
											{
												RT.expess[i].compartment[g].lowerBerth[j] = 0;
											}
										}
										for (int h = 0; h < help3; h++)
										{
											if (RT.numberOfSeats[k - 1].indexUpper[h] == j + 1)
											{
												RT.expess[i].compartment[g].upperBerth[j] = 0;
											}
										}
									}
								}
							}
							break;
						}
						case 3: // Second class
						{
							int k1 = 0;
							int k2 = 0;
							int help3 = orders[k - 1].berth[0];
							int help4 = orders[k - 1].berth[1];
							for (int g = 0; g < 8; g++)
							{
								if ((g + 1) == orders[k - 1].wagonNumber)
								{
									for (int j = 0; j < 27; j++)
									{
										for (int h = 0; h < help4; h++)
										{
											if (RT.numberOfSeats[k - 1].indexLower[h] == j + 1)
											{
												RT.expess[i].secondClass[g].lowerBerth[j] = 0;
											}
										}
										for (int h = 0; h < help3; h++)
										{
											if (RT.numberOfSeats[k - 1].indexUpper[h] == j + 1)
											{
												RT.expess[i].secondClass[g].upperBerth[j] = 0;
											}
										}
									}
								}
							}
							break;
						}
					}
				}
			}
		}
		orders.erase(orders.begin() + (k - 1));
		RT.numberOfSeats.erase(RT.numberOfSeats.begin() + (k - 1));
	}
	void ReserveOrder()
	{
		Index in;
		if ((order.trainNumber > 9 && order.trainNumber < 13) || (order.trainNumber > 19 && order.trainNumber < 23))
		{
			int k = 0;
			int help1 = order.lastochkaTickets;
			for (int i = 0; i < 6; i++)
			{
				if (RT.lastochkaNumber[i] == order.trainNumber)
				{
					for (int g = 0; g < 8; g++)
					{
						if ((g + 1) == order.wagonNumber)
						{
							for (int j = 0; j < 100; j++)
							{
								if (RT.lastochka[i].standart[g].places[j] != 1)
								{
									if (help1 == 0)
									{
										continue;
									}
									RT.lastochka[i].standart[g].places[j] = 1;
									in.indexStandart[k] = j + 1;
									k++;
									help1 -= 1;
								}
							}
						}
					}
				}
			}
		}
		if ((order.trainNumber == 13) || (order.trainNumber == 23))
		{
			int k = 0;
			int help2 = order.brandedSWTickets;
			for (int i = 0; i < 2; i++)
			{
				if (RT.brandedNumber[i] == order.trainNumber)
				{
					switch (order.wagonType)
					{
						case 1: // SW 
						{
							for (int g = 0; g < 2; g++)
							{
								if ((g + 1) == order.wagonNumber)
								{
									for (int j = 0; j < 18; j++)
									{
										if (help2 == 0)
										{
											continue;
										}
										if (RT.branded[i].sleepingWagon[g].lowerBerth[j] != 1)
										{
											RT.branded[i].sleepingWagon[g].lowerBerth[j] = 1;
											in.indexStandart[k] = j + 1;
											k++;
											help2 -= 1;
										}
									}
								}
							}
							break;
						}
						case 2: // Compartment
						{
							int k1 = 0;
							int k2 = 0;
							int help3 = order.berth[0];
							int help4 = order.berth[1];
							for (int g = 0; g < 6; g++)
							{
								if ((g + 1) == order.wagonNumber)
								{
									for (int j = 0; j < 18; j++)
									{
										if (help4 == 0)
										{
											continue;
										}
										if (RT.branded[i].compartment[g].lowerBerth[j] != 1)
										{
											RT.branded[i].compartment[g].lowerBerth[j] = 1;
											in.indexLower[k1] = ((j * 2) + 1);
											help4 -= 1;
											k1++;
										}
										if (help3 == 0)
										{
											continue;
										}
										if (RT.branded[i].compartment[g].upperBerth[j] != 1)
										{
											RT.branded[i].compartment[g].upperBerth[j] = 1;
											in.indexUpper[k2] = (j * 2 + 2);
											help3 -= 1;
											k2++;
										}
									}
								}
							}
							break;
						}
						case 3: // Second class
						{
							int k1 = 0;
							int k2 = 0;
							int help3 = order.berth[0];
							int help4 = order.berth[1];
							for (int g = 0; g < 4; g++)
							{
								if ((g + 1) == order.wagonNumber)
								{
									for (int j = 0; j < 27; j++)
									{
										if (help4 == 0)
										{
											continue;
										}
										if (RT.branded[i].secondClass[g].lowerBerth[j] != 1)
										{
											RT.branded[i].secondClass[g].lowerBerth[j] = 1;
											in.indexLower[k1] = (j * 2 + 1);
											help4 -= 1;
											k1++;
										}
										if (help3 == 0)
										{
											continue;
										}
										if (RT.branded[i].secondClass[g].upperBerth[j] != 1)
										{
											RT.branded[i].secondClass[g].upperBerth[j] = 1;
											in.indexUpper[k2] = (j * 2 + 2);
											help3 -= 1;
											k2++;
										}
									}
								}
							}
							break;
						}
					}
				}
			}
		}
		if ((order.trainNumber == 14) || (order.trainNumber == 24))
		{
			for (int i = 0; i < 2; i++)
			{
				if (RT.expessTrainNumber[i] == order.trainNumber)
				{
					switch (order.wagonType)
					{
						case 2: // Compartment
						{
							int k1 = 0;
							int k2 = 0;
							int help3 = order.berth[0];
							int help4 = order.berth[1];
							for (int g = 0; g < 4; g++)
							{
								if ((g + 1) == order.wagonNumber)
								{
									for (int j = 0; j < 18; j++)
									{
										if (help4 == 0)
										{
											continue;
										}
										if (RT.expess[i].compartment[g].lowerBerth[j] != 1)
										{
											RT.expess[i].compartment[g].lowerBerth[j] = 1;
											in.indexLower[k1] = (j * 2 + 1);
											help4 -= 1;
											k1++;
										}
										if (help3 == 0)
										{
											continue;
										}
										if (RT.expess[i].compartment[g].upperBerth[j] != 1)
										{
											RT.expess[i].compartment[g].upperBerth[j] = 1;
											in.indexUpper[k2] = (j * 2 + 2);
											help3 -= 1;
											k2++;
										}
									}
								}
							}
							break;
						}
						case 3: // Second class
						{
							int k1 = 0;
							int k2 = 0;
							int help3 = order.berth[0];
							int help4 = order.berth[1];
							for (int g = 0; g < 8; g++)
							{
								if ((g + 1) == order.wagonNumber)
								{
									for (int j = 0; j < 27; j++)
									{
										if (help4 == 0)
										{
											continue;
										}
										if (RT.branded[i].secondClass[g].lowerBerth[j] != 1)
										{
											RT.branded[i].secondClass[g].lowerBerth[j] = 1;
											in.indexLower[k1] = (j * 2 + 1);
											help4 -= 1;
											k1++;
										}
										if (help3 == 0)
										{
											continue;
										}
										if (RT.branded[i].secondClass[g].upperBerth[j] != 1)
										{
											RT.branded[i].secondClass[g].upperBerth[j] = 1;
											in.indexUpper[k2] = (j * 2 + 2);
											help3 -= 1;
											k2++;
										}
									}
								}
							}
							break;
						}
					}
				}
			}
		}
		RT.numberOfSeats.push_back(in);
		orders.push_back(order);
	}
	int GetPrice()
	{
		int price = 0;
		if ((order.trainNumber > 9 && order.trainNumber < 13) || (order.trainNumber > 19 && order.trainNumber < 23))
		{
			price = (order.lastochkaTickets * RT.lastochka->standart->priceForTickets);
		}
		if ((order.trainNumber == 13) || (order.trainNumber == 23))
		{
			switch (order.wagonType)
			{
				case 1: // SW 
				{
					price = order.brandedSWTickets * 5000;
					break;
				}
				case 2: // Compartment
				{
					price = ((order.berth[0] * RT.branded->compartment->upperBerthPrice) + (order.berth[1] * RT.branded->compartment->lowerBerthPrice));
					break;
				}
				case 3: // Second class
				{
					price = ((order.berth[0] * RT.branded->secondClass->upperBerthPrice) + (order.berth[1] * RT.branded->secondClass->lowerBerthPrice));
					break;
				}
			}
		}
		if ((order.trainNumber == 14) || (order.trainNumber == 24))
		{
			for (int i = 0; i < 2; i++)
			{
				if (RT.expessTrainNumber[i] == order.trainNumber)
				{
					switch (order.wagonType)
					{
						case 2: // Compartment
						{
							price = ((order.berth[0] * RT.expess->compartment->upperBerthPrice) + (order.berth[1] * RT.expess->compartment->lowerBerthPrice));
							break;
						}
						case 3: // Second class
						{
							price = ((order.berth[0] * RT.expess->secondClass->upperBerthPrice) + (order.berth[1] * RT.expess->secondClass->lowerBerthPrice));
							break;
						}
					}
				}
			}
		}
		return price;
	}
	bool IsAvailable()
	{
		int count1 = 0;
		int count2 = 0;
		if ((order.trainNumber > 9 && order.trainNumber < 13) || (order.trainNumber > 19 && order.trainNumber < 23))
		{
			for (int i = 0; i < 6; i++)
			{
				if (RT.lastochkaNumber[i] == order.trainNumber)
				{
					for (int g = 0; g < 8; g++)
					{
						if ((g + 1) == order.wagonNumber)
						{
							for (int j = 0; j < 100; j++)
							{
								if (RT.lastochka[i].standart[g].places[j] != 1)
								{
									count1++;
								}
							}
						}
					}
				}
			}
			if (count1 >= order.lastochkaTickets)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		if ((order.trainNumber == 13) || (order.trainNumber == 23))
		{
			for (int i = 0; i < 2; i++)
			{
				if (RT.brandedNumber[i] == order.trainNumber)
				{
					switch (order.wagonType)
					{
						case 1: // SW
						{
							for (int g = 0; g < 2; g++)
							{
								if ((g + 1) == order.wagonNumber)
								{
									for (int j = 0; j < 18; j++)
									{
										if (RT.branded[i].sleepingWagon[g].lowerBerth[j] != 1)
										{
											count1++;
										}
									}
								}
							}
							if (count1 >= order.brandedSWTickets)
							{
								return true;
							}
							else
							{
								return false;
							}
						}
						case 2: // Compartment
						{
							for (int g = 0; g < 6; g++)
							{
								if ((g + 1) == order.wagonNumber)
								{
									for (int j = 0; j < 18; j++)
									{
										if (RT.branded[i].compartment[g].lowerBerth[j] != 1)
										{
											count1++;
										}
										if (RT.branded[i].compartment[g].upperBerth[j] != 1)
										{
											count2++;
										}
									}
								}
							}
							if ((count1 >= order.berth[1]) && (count2 >= order.berth[0]))
							{
								return true;
							}
							else
							{
								return false;
							}
						}
						case 3: // Second class
						{
							for (int g = 0; g < 4; g++)
							{
								if ((g + 1) == order.wagonNumber)
								{
									for (int j = 0; j < 27; j++)
									{
										if (RT.branded[i].secondClass[g].lowerBerth[j] != 1)
										{
											count1++;
										}
										if (RT.branded[i].secondClass[g].upperBerth[j] != 1)
										{
											count2++;
										}
									}
								}
							}
							if ((count1 >= order.berth[1]) && (count2 >= order.berth[0]))
							{
								return true;
							}
							else
							{
								return false;
							}
						}
					}
				}
			}

		}
		if ((order.trainNumber == 14) || (order.trainNumber == 24))
		{
			for (int i = 0; i < 2; i++)
			{
				if (RT.expessTrainNumber[i] == order.trainNumber)
				{
					switch (order.wagonType)
					{
						case 2: // Compartment
						{
							for (int g = 0; g < 4; g++)
							{
								if ((g + 1) == order.wagonNumber)
								{
									for (int j = 0; j < 18; j++)
									{
										if (RT.expess[i].compartment[g].lowerBerth[j] != 1)
										{
											count1++;
										}
										if (RT.expess[i].compartment[g].upperBerth[j] != 1)
										{
											count2++;
										}
									}
								}
							}
							if ((count1 >= order.berth[1]) && (count2 >= order.berth[0]))
							{
								return true;
							}
							else
							{
								return false;
							}
						}
						case 3: // Second class
						{
							for (int g = 0; g < 8; g++)
							{
								if ((g + 1) == order.wagonNumber)
								{
									for (int j = 0; j < 27; j++)
									{
										if (RT.branded[i].secondClass[g].lowerBerth[j] != 1)
										{
											count1++;
										}
										if (RT.branded[i].secondClass[g].upperBerth[j] != 1)
										{
											count2++;
										}
									}
								}
							}
							if ((count1 >= order.berth[1]) && (count2 >= order.berth[0]))
							{
								return true;
							}
							else
							{
								return false;
							}
						}
					}
				}
			}
		}
	}
	friend void GetOrder(NewOrder, RailwayTicketOffice&);
	friend void SetData(NewOrder, RailwayTicketOffice&);
};
void SetData(NewOrder, RailwayTicketOffice& obj)
{
	cout << "Tickets are sold within 30 days from the current date\n";
	cout << "Current date is (1 january 2000)" << endl;
	cout << "Enter date: " << endl;
	cout << "Day: ";
	cin >> obj.order.date[0];// input day
	system("cls");
	cout << "Choose month: " << endl;
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
	cout << "\n" << "Your choice: ";
	cin >> obj.order.date[1];// input month
	system("cls");
	cout << "Year: ";
	cin >> obj.order.date[2];// input year
	system("cls");
	if ((obj.order.date[1] != 1) || (obj.order.date[2] != 2000))
	{
		cout << "Time of ordering has already ended" << endl;
		system("pause");
	}
	else
	{
		cout << "Choose direction:\n " << endl;
		cout << "1) Nizhny Novgorod - Moscow\n " << endl;
		cout << "2) Moscow - Nizhny Novgorod\n " << endl;
		cout << "Your choice: ";
		cin >> obj.order.direction;// input direction
		system("cls");
		switch (obj.order.direction)
		{
			case 1:
			{
				cout << "Numbers of Lastochka trains: 10,11,12" << endl;
				cout << "Number of Branded train: 13" << endl;
				cout << "Number of Express train: 14" << endl;
				break;
			}
			case 2:
			{
				cout << "Numbers of Lastochka trains: 20,21,22" << endl;
				cout << "Number of Branded train: 23" << endl;
				cout << "Number of Express train: 24" << endl;
				break;
			}
		}
		cout << "\n" << "Enter number of train:" << endl;
		cout << "Your choice: ";
		cin >> obj.order.trainNumber;// input number of train
		system("cls");
		if ((obj.order.trainNumber > 9 && obj.order.trainNumber < 13) || (obj.order.trainNumber > 19 && obj.order.trainNumber < 23)) // Entering further data if the user has selected a train "Lastochka"
		{
			cout << "Choose number of wagon( 1,2,3,4,5,6,7,8): ";
			cin >> obj.order.wagonNumber;
			system("cls");
			cout << "Enter number of tickets: ";
			cin >> obj.order.lastochkaTickets;
			system("cls");
			cout << "Enter full names of passengers: " << endl;
			for (int i = 0; i < obj.order.lastochkaTickets; i++)
			{
				obj.order.names[i].SetName();
			}
		}
		if ((obj.order.trainNumber == 13) || (obj.order.trainNumber == 23))  // Entering further data if the user has selected a Branded train 
		{
			cout << "Choose the type of wagon: \n";
			cout << "1) Sleeping wagon\n";
			cout << "2) Compartment wagon\n";
			cout << "3) Second class wagon\n";
			cout << "Your choice: ";
			cin >> obj.order.wagonType;
			switch (obj.order.wagonType)
			{
				case 1:
				{
					cout << "Choose number of wagon( 1,2 ): ";
					cin >> obj.order.wagonNumber;
					cout << "Enter number of tickets: ";
					cin >> obj.order.brandedSWTickets;
					system("cls");
					cout << "Enter full names of passengers: " << endl;
					for (int i = 0; i < obj.order.brandedSWTickets; i++)
					{
						obj.order.names[i].SetName();
					}
					break;
				}
				case 2:
				{
					cout << "Choose number of wagon( 1,2,3,4,5,6 ): ";
					cin >> obj.order.wagonNumber;
					cout << "Enter number of tickets: \n";
					cout << "Enter number of upper berths: ";
					cin >> obj.order.berth[0];
					cout << "Enter number of lower berths: ";
					cin >> obj.order.berth[1];
					cout << "Enter full names of passengers: " << endl;
					for (int i = 0; i < (obj.order.berth[0] + obj.order.berth[1]); i++)
					{
						obj.order.names[i].SetName();
					}
					break;
				}
				case 3:
				{
					cout << "Choose number of wagon( 1,2,3,4 ): ";
					cin >> obj.order.wagonNumber;
					cout << "Enter number of tickets: \n";
					cout << "Enter number of upper berths: ";
					cin >> obj.order.berth[0];
					cout << "Enter number of lower berths: ";
					cin >> obj.order.berth[1];
					cout << "Enter full names of passengers: " << endl;
					for (int i = 0; i < (obj.order.berth[0] + obj.order.berth[1]); i++)
					{
						obj.order.names[i].SetName();
					}
					break;
				}
			}
		}
		if ((obj.order.trainNumber == 14) || (obj.order.trainNumber == 24)) // Entering further data if the user has selected a Express train
		{
			cout << "Choose the type of wagon: \n";
			cout << "2) Compartment wagon\n";
			cout << "3) Second class wagon\n";
			cout << "Your choice: ";
			cin >> obj.order.wagonType;
			switch (obj.order.wagonType)
			{
				case 2:
				{
					cout << "Choose number of wagon( 1,2,3,4 ): ";
					cin >> obj.order.wagonNumber;
					cout << "Enter number of tickets: \n";
					cout << "Enter number of upper berths: ";
					cin >> obj.order.berth[0];
					cout << "Enter number of lower berths: ";
					cin >> obj.order.berth[1];
					cout << "Enter full names of passengers: " << endl;
					for (int i = 0; i < (obj.order.berth[0] + obj.order.berth[1]); i++)
					{
						obj.order.names[i].SetName();
					}
					break;
				}
				case 3:
				{
					cout << "Choose number of wagon( 1,2,3,4,5,6,7,8 ): ";
					cin >> obj.order.wagonNumber;
					cout << "Enter number of tickets: \n";
					cout << "Enter number of upper berths: ";
					cin >> obj.order.berth[0];
					cout << "Enter number of lower berths: ";
					cin >> obj.order.berth[1];
					cout << "Enter full names of passengers: " << endl;
					for (int i = 0; i < (obj.order.berth[0] + obj.order.berth[1]); i++)
					{
						obj.order.names[i].SetName();
					}
					break;
				}
			}
		}
	}
}
void GetOrder(NewOrder, RailwayTicketOffice& obj1)
{
	cout << obj1.order;
}
int main()
{
	int orderNumber = 0;
	int orderNumber1 = 0;
	int h = 1;
	int k = 0;
	int j = 0;
	NewOrder order = {};
	RailwayTicketOffice office;
	while (h == 1)
	{
		cout << "1) Enter data for order\n " << endl;
		cout << "2) Check on availability\n " << endl;
		cout << "3) Reserve places\n " << endl;
		cout << "4) Get price of your order\n " << endl;
		cout << "5) Delete order\n " << endl;
		cout << "6) Create tickets\n " << endl;
		cout << "7) Exit\n " << endl;
		cout << "Your choice: ";
		cin >> j;
		system("cls");
		switch (j)
		{
			case 1: // Enter data for order
			{
				order = {};
				SetData(order, office);
				k++;
				system("cls");
				system("pause");
				system("cls");
				break;
			}
			case 2: // Check on availability
			{
				if (office.IsAvailable() == true)
				{
					cout << "Places which you have ordered are availaible \n" << "You can reserve seats \n";
				}
				else
				{
					cout << "Places which you have ordered are not availaible \n" << "You can not reserve seats \n" << endl;
				}
				system("pause");
				system("cls");
				break;
			}
			case 3: // Reservation of the order 
			{
				office.ReserveOrder();
				cout << "Number of your order: " << k << endl;
				system("pause");
				system("cls");
				break;
			}
			case 4: // Get price of your order
			{
				cout << "Price of your order: " << office.GetPrice() << endl;
				system("pause");
				system("cls");
				break;
			}
			case 5: // Delete order
			{
				cout << "Enter number of your order: ";
				cin >> orderNumber;
				office.DeleteOrder(orderNumber);
				cout << "Your order has been deleted \n";
				system("pause");
				system("cls");
				break;
			}
			case 6: // Create tickers
			{
				cout << "Enter number of your order: ";
				cin >> orderNumber1;
				office.CreateTickets(orderNumber1);
				system("pause");
				system("cls");
				break;
			}
			case 7: // Exit 
			{
				h = 0;
				break;
			}
		}
	}
}