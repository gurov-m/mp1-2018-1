﻿#include "BattleField.h"
#include "Battle.h"
enum ConsoleColor { Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray, LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White };
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
void SetColor(ConsoleColor text, ConsoleColor background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
void BattleField::DrawPlayer()
{
	if (flag)
		system("cls");
	flag = 1;
	SetColor(LightGreen, Black);
	cout << "\t\t Поле Игрока\n\n";
	SetColor(LightGreen, Black);
	cout << "     a   b   c   d   e   f   g   h   i   j\n";
	SetColor(White, Black);
	cout << "   + - + - + - + - + - + - + - + - + - + - +\n";
	for (int i = 1; i<Rows - 1; i++)
	{
		cout << "   ";
		for (int j = 1; j<Cols - 1; j++)
		{
			if (!(playerField[i][j])) {
				cout << "| " << "  ";
				SetColor(White, Black);
			}
			else if (playerField[i][j] == 1)//если 1 рисует корабль 
			{
				cout << "|";
				SetColor(Green, Green);
				cout << '0' << "  ";
				SetColor(White, Black);
			}
			else if (playerField[i][j] == 2)//если 2 мимо желтый крест
			{
				cout << "| ";
				SetColor(Yellow, Black);
				cout << 'x' << " ";
				SetColor(White, Black);
			}
			else if (playerField[i][j] == 3)//если 3 ранен или убит крас крест
			{
				cout << "|";
				SetColor(LightRed, Black);
				cout << " " << 'X' << " ";
				SetColor(White, Black);
			}
			if (j == 10)
				cout << "| " << "  ";
		}
		SetColor(LightGreen, Black);
		cout << i;
		cout << std::endl;
		SetColor(White, Black);
		cout << "   + - + - + - + - + - + - + - + - + - + - +\n";
	}	
}
void BattleField::DrawComp()
{
	SetColor(LightGreen, Black);
	cout << "\n\t\t Поле Компьютера\n\n";
	SetColor(LightGreen, Black);
	cout << "     a   b   c   d   e   f   g   h   i   j\n";
	SetColor(White, Black);
	cout << "   + - + - + - + - + - + - + - + - + - + - +\n";
	for (int i = 1; i< Rows - 1; i++)
	{
		cout << "   ";
		for (int j = 1; j< Cols - 1; j++)
		{
			if (IfWin())
			{
				if (!(compField[i][j]))
				{
					cout << "| " << "  ";
					SetColor(White, Black);
				}
				else if (compField[i][j] == 2)
				{
					cout << "| ";
					SetColor(Yellow, Black);
					cout << 'x' << " ";
					SetColor(White, Black);
				}
				else if (compField[i][j] == 3)
				{
					cout << "|";
					SetColor(LightRed, Black);
					cout << " " << 'X' << " ";
					SetColor(White, Black);
				}
				else
				{
					cout << "|";
					SetColor(White, Black);
					cout << ' ' << "  ";
					SetColor(White, Black);
				}
				if (j == 10)
					cout << "|";
			}
			else if (!IfWin())
			{
				if (!(compField[i][j])) {
					cout << "| " << "  ";
					SetColor(White, Black);
				}
				else if (compField[i][j] == 1)//если 1 нарисовать корабль
				{
					cout << "|";
					SetColor(Green, Green);
					cout << '0' << "  ";
					SetColor(White, Black);
				}
				else if (compField[i][j] == 2)
				{
					cout << "| ";
					SetColor(Yellow, Black);
					cout << 'x' << " ";
					SetColor(White, Black);
				}
				else if (compField[i][j] == 3)
				{
					cout << "|";
					SetColor(LightRed, Black);
					cout << " " << 'X' << " ";
					SetColor(White, Black);
				}
				else
				{
					cout << "|";
					SetColor(White, Black);
					cout << ' ' << "  ";
					SetColor(White, Black);
				}
				if (j == 10)
					cout << "|";
			}
		}
		SetColor(LightGreen, Black);
		cout << "   " << i;
		SetColor(White, Black);
		cout << endl;
		cout << "   + - + - + - + - + - + - + - + - + - + - +\n";
	}
}
void BattleField::SetFloat(int decks , int number)
{	
	char getChoice[10] = {};
	int choice = 0;
	in: SetColor(LightGreen, Black);
	cout << "Выберете расстановку кораблей:" << endl;
	SetColor(LightGreen, Black);
	cout << "1) Автоматическая расстановка" << endl;
	SetColor(LightGreen, Black);
	cout << "2) Расстановка вручную" << endl;
	cin >> choice;
	if (choice<1 || choice>2)
	{
		SetColor(White, LightRed);
		cout << "\n Неверный выбор \n";
		goto in;
	}
	switch (choice)
	{
		case 1:
		{
			AutomaticFloatSetting(decks, number);
			DrawPlayer();
			SetPCShips(decks, number);
			DrawComp();
			break;
		}
		case 2:
		{
			ManualFloatSetting(decks, number);
			DrawPlayer();
			SetPCShips(decks, number);
			DrawComp();
			break;
		}
	}
}
void BattleField::AutomaticFloatSetting(int decks, int number)//автоматическая расcтановка кораблей пользователя
{
	if (!decks)//палуб 0 - выход
		return;
	int firstDeck = 1;//для записи в структуру
	for (int j = 1; j <= number; j++)//j количество кораблей одного типа
	{
		int *deckAdress;//указывает на адрес палубы 
		int row, col;//строка - столбец массива
		int random = 1 + rand() % 2;//по горизонтали или по вертикали
		int k = 1, i = decks;//k счетчик i текущяя палуба
		if (random == 1)//вертикаль
		{
			do {
				do {
					row = rand() % 10 + 1;
				} while (row + decks > 11);//чтобы не вышел за пределы массива
				col = rand() % 10 + 1;
				deckAdress = &playerField[row][col];
			} while (!SearchAddress(deckAdress, decks, random));//проверка записан ли такой адресс           
		}
		else if (random == 2)//горизонталь
		{
			do {
				do {
					col = rand() % 10 + 1;
				} while (col + decks > 11);
				row = rand() % 10 + 1;
				deckAdress = &playerField[row][col];
			} while (!SearchAddress(deckAdress, decks, random));    
		}
		switch (random)
		{
		case 1:     //вертикаль         
			while (k <= i)//k счетчик i текущяя палуба
			{
				playerField[row][col] = 1;
				if (decks == 4 && firstDeck == 1)
				{
					FourPlay.firstDeckAdress = &playerField[row][col];     //запись в структуру адреса только самой первой палубы
					FourPlay.position = 1;//положение корабля
					FourPlay.decks = 4;//кол. палуб
					firstDeck++;//чтобы больше не зап. адреса остальн. палуб
				}
				else if (decks == 3 && firstDeck == 1)
				{
					Three1Play.firstDeckAdress = &playerField[row][col];
					Three1Play.position = 1;
					Three1Play.decks = 3;
					firstDeck++;
				}
				else if (decks == 3 && firstDeck == 2 && j == 2)
				{
					Three2Play.firstDeckAdress = &playerField[row][col];
					Three2Play.position = 1;
					Three2Play.decks = 3;
					firstDeck++;
				}
				else if (decks == 2 && firstDeck == 1)
				{
					Two1Play.firstDeckAdress = &playerField[row][col];
					Two1Play.position = 1;
					Two1Play.decks = 2;
					firstDeck++;
				}
				else if (decks == 2 && firstDeck == 2 && j == 2)
				{
					Two2Play.firstDeckAdress = &playerField[row][col];
					Two2Play.position = 1;
					Two2Play.decks = 2;
					firstDeck++;
				}
				else if (decks == 2 && firstDeck == 3 && j == 3)
				{
					Two3Play.firstDeckAdress = &playerField[row][col];
					Two3Play.position = 1;
					Two3Play.decks = 2;
					firstDeck++;
				}
				row++;
				i--;
			}
			break;
		case 2:         //горизонталь               
			while (k <= i)
			{
				playerField[row][col] = 1;
				if (decks == 4 && firstDeck == 1)
				{
					FourPlay.firstDeckAdress = &playerField[row][col];     //запись в структуру адреса только самой первой палубы
					FourPlay.position = 2;//положение корабля
					FourPlay.decks = 4;//кол. палуб
					firstDeck++;//чтобы больше не зап. адреса остальн. палуб
				}
				else if (decks == 3 && firstDeck == 1)
				{
					Three1Play.firstDeckAdress = &playerField[row][col];
					Three1Play.position = 2;
					Three1Play.decks = 3;
					firstDeck++;
				}
				else if (decks == 3 && firstDeck == 2 && j == 2)
				{
					Three2Play.firstDeckAdress = &playerField[row][col];
					Three2Play.position = 2;
					Three2Play.decks = 3;
					firstDeck++;
				}
				else if (decks == 2 && firstDeck == 1)
				{
					Two1Play.firstDeckAdress = &playerField[row][col];
					Two1Play.position = 2;
					Two1Play.decks = 2;
					firstDeck++;
				}
				else if (decks == 2 && firstDeck == 2 && j == 2)
				{
					Two2Play.firstDeckAdress = &playerField[row][col];
					Two2Play.position = 2;
					Two2Play.decks = 2;
					firstDeck++;
				}
				else if (decks == 2 && firstDeck == 3 && j == 3)
				{
					Two3Play.firstDeckAdress = &playerField[row][col];
					Two3Play.position = 2;
					Two3Play.decks = 2;
					firstDeck++;
				}
				col++;
				i--;
			}
			break;
		}
	}
	AutomaticFloatSetting(decks - 1, number + 1);//уменшение палуб - увеличение кол. кор.
}
void BattleField::ManualFloatSetting(int decks, int number)//растановка в ручную
{
	DrawPlayer();
	int *deckAdress;//указывает на адрес палубы 
	int row, col;//строка - столбец массива
	int choice1 = 0;//по горизонтали или по вертикали        
	char column;
	if (!decks)
		return;
	int firstDeck = 1;
	for (int j = 1; j <= number; j++)//j количество кораблей одного типа
	{
		do {
			cout << decks << " - палубный корабль\n";
			cout << "Введите координаты корабля по горизонтали например(а)\n";
			cin >> column;
			cout << "Введите координаты корабля по вертикали например(5)\n";
			cin >> row;
			col = Translation(column);
			if ((col < 1) || (col > 10) || (row < 1) || (row > 10))
			{
				SetColor(Blue, LightRed);
				cout << " Неверные координаты \n";
				SetColor(White, Black);
			}
		} while ((!col) || (row < 1) || (row > 10));
		int k = 1, i = decks;//k счетчик i текущяя палуба      
		if (decks > 1)
		{
			do {
				cout << "Как Вы хотите установить свой " << decks << " палубный корабль \nВертикально(1)  Горизонтально(2) = ";
				cin >> choice1;
				if (choice1 < 1 || choice1 > 2)
				{
					SetColor(White, LightRed);
					cout << " Неверные координаты \n";
					SetColor(White, Black);
				}
			} while (choice1 < 1 || choice1 > 2);
		}
		if (decks == 1)//для однопалубного
			choice1 = 1;
		if (choice1 == 1)//вертикаль
		{
			do {
				if (errors)//проверка адресов
				{
					SetColor(White, LightRed);
					cout << " Неверные координаты \n";
					SetColor(White, Black);
					do {
						cout << decks << " - палубный корабль\n";
						cout << "Введите координаты корабля по горизонтали например(а)\n";
						cin >> column;
						cout << "Введите координаты корабля по вертикали например(5)\n";
						cin >> row;
						col = Translation(column);
						if ((!col) || (row < 1) || (row > 10))
						{
							SetColor(White, LightRed);
							cout << " Неверные координаты \n";
							SetColor(White, Black);
						}
					} while ((!col) || (row < 1) || (row > 10));
					errors = 0;
				}
				if (row + decks>11)//проверка на выход за пределы массива
					do {
						SetColor(White, LightRed);
						cout << " Неверные координаты \n";
						SetColor(White, Black);
						do {
							cout << decks << " - палубный корабль\n";
							cout << "Введите координаты корабля по горизонтали например(а)\n";
							cin >> column;
							cout << "Введите координаты корабля по вертикали например(5)\n";
							cin >> row;
							col = Translation(column);
							if ((!col) || (row < 1) || (row > 10))
							{
								SetColor(White, LightRed);
								cout << " Неверные координаты \n";
								SetColor(White, Black);
							}
						} while ((!col) || (row < 1) || (row > 10));
					} while (row + decks > 11); //проверка на выход за пределы массива          
					deckAdress = &playerField[row][col];  //первая палуба             
			} while (!SearchAddress(deckAdress, decks, choice1)); //проверка на совпадение адресов        
		}
		else if (choice1 == 2)//горизонталь
		{
			do {
				if (errors)//проверка адресов
				{
					SetColor(White, LightRed);
					cout << " Неверные координаты \n";
					SetColor(White, Black);
					do {
						cout << decks << " - палубный корабль\n";
						cout << "Введите координаты корабля по горизонтали например(а)\n";
						cin >> column;
						cout << "Введите координаты корабля по вертикали например(5)\n";
						cin >> row;
						col = Translation(column);
						if ((!col) || (row<1) || (row>10))
						{
							SetColor(White, LightRed);
							cout << " Неверные координаты \n";
							SetColor(White, Black);
						}
					} while ((!col) || (row < 1) || (row > 10));
					errors = 0;
				}
				if (col + decks > 11)//проверка на выход за пределы массива
					do {
						SetColor(White, LightRed);
						cout << " Неверные координаты \n";
						SetColor(White, Black);
						do {
							cout << decks << " - палубный корабль\n";
							cout << "Введите координаты корабля по горизонтали например(а)\n";
							cin >> column;
							cout << "Введите координаты корабля по вертикали например(5)\n";
							cin >> row;
							col = Translation(column);
							if ((!col) || (row < 1) || (row > 10))
							{
								SetColor(White, LightRed);
								cout << " Неверные координаты \n";
								SetColor(White, Black);
							}
						} while ((!col) || (row < 1) || (row > 10));
					} while (col + decks > 11);
					deckAdress = &playerField[row][col];
			} while (!SearchAddress(deckAdress, decks, choice1));
		}
		switch (choice1)
		{
		case 1:     //вертикаль         
			while (k <= i)//k счетчик i текущяя палуба
			{
				playerField[row][col] = 1;
				if (decks == 4 && firstDeck == 1)
				{
					FourPlay.firstDeckAdress = &playerField[row][col];     //запись в структуру адреса только самой первой палубы
					FourPlay.position = 1;//положение корабля
					FourPlay.decks = 4;//кол. палуб
					firstDeck++;//чтобы больше не зап. адреса остальн. палуб
				}
				else if (decks == 3 && firstDeck == 1)
				{
					Three1Play.firstDeckAdress = &playerField[row][col];
					Three1Play.position = 1;
					Three1Play.decks = 3;
					firstDeck++;
				}
				else if (decks == 3 && firstDeck == 2 && j == 2)
				{
					Three2Play.firstDeckAdress = &playerField[row][col];
					Three2Play.position = 1;
					Three2Play.decks = 3;
					firstDeck++;
				}
				else if (decks == 2 && firstDeck == 1)
				{
					Two1Play.firstDeckAdress = &playerField[row][col];
					Two1Play.position = 1;
					Two1Play.decks = 2;
					firstDeck++;
				}
				else if (decks == 2 && firstDeck == 2 && j == 2)
				{
					Two2Play.firstDeckAdress = &playerField[row][col];
					Two2Play.position = 1;
					Two2Play.decks = 2;
					firstDeck++;
				}
				else if (decks == 2 && firstDeck == 3 && j == 3)
				{
					Two3Play.firstDeckAdress = &playerField[row][col];
					Two3Play.position = 1;
					Two3Play.decks = 2;
					firstDeck++;
				}
				row++;
				i--;
			}
			break;
		case 2:         //горизонталь               
			while (k <= i)
			{
				playerField[row][col] = 1;
				if (decks == 4 && firstDeck == 1)
				{
					FourPlay.firstDeckAdress = &playerField[row][col];     //запись в структуру адреса только самой первой палубы
					FourPlay.position = 2;//положение корабля
					FourPlay.decks = 4;//кол. палуб
					firstDeck++;//чтобы больше не зап. адреса остальн. палуб
				}
				else if (decks == 3 && firstDeck == 1)
				{
					Three1Play.firstDeckAdress = &playerField[row][col];
					Three1Play.position = 2;
					Three1Play.decks = 3;
					firstDeck++;
				}
				else if (decks == 3 && firstDeck == 2 && j == 2)
				{
					Three2Play.firstDeckAdress = &playerField[row][col];
					Three2Play.position = 2;
					Three2Play.decks = 3;
					firstDeck++;
				}
				else if (decks == 2 && firstDeck == 1)
				{
					Two1Play.firstDeckAdress = &playerField[row][col];
					Two1Play.position = 2;
					Two1Play.decks = 2;
					firstDeck++;
				}
				else if (decks == 2 && firstDeck == 2 && j == 2)
				{
					Two2Play.firstDeckAdress = &playerField[row][col];
					Two2Play.position = 2;
					Two2Play.decks = 2;
					firstDeck++;
				}
				else if (decks == 2 && firstDeck == 3 && j == 3)
				{
					Two3Play.firstDeckAdress = &playerField[row][col];
					Two3Play.position = 2;
					Two3Play.decks = 2;
					firstDeck++;
				}
				col++;
				i--;
			}
			break;
		}
		DrawPlayer();
	}
	ManualFloatSetting(decks - 1, number + 1);//уменшение палуб - увеличение кол. кор.
}
void BattleField::SetPCShips(int decks, int number)
{
	if (!decks)
		return;
	int firstDeck = 1;
	for (int j = 1; j <= number; j++)//j количество кораблей одного типа
	{
		int *deckAdress;//указывает на адрес палубы 
		int row, col;//строка - столбец массива
		int random = 1 + rand() % 2;//по горизонтали или по вертикали
		int k = 1, i = decks;//k счетчик i текущяя палуба
		if (random == 1)//вертикаль
		{
			do {
				do {
					row = rand() % 10 + 1;
				} while (row + decks>11);//чтобы не выйти за пределы массива
				col = rand() % 10 + 1;
				deckAdress = &compField[row][col];//адресс для проверки на совпадение
			} while (!SearchPCAddress(deckAdress, decks, random));//-----------------//вызвать ф-ю         
		}
		else if (random == 2)//горизонталь
		{
			do {
				do {
					col = rand() % 10 + 1;
				} while (col + decks>11);//чтобы не выйти за пределы массива
				row = rand() % 10 + 1;
				deckAdress = &compField[row][col];//адресс для проверки на совпадение
			} while (!SearchPCAddress(deckAdress, decks, random));//-----------------//вызвать ф-ю     
		}
		switch (random)
		{
		case 1:     //вертикаль         
			while (k <= i)//k счетчик i текущяя палуба
			{
				compField[row][col] = 1;//устоновка палубы 1
				if (decks == 4 && firstDeck == 1)
				{
					FourPC.firstDeckAdress = &compField[row][col];  //запись в структуру только первой палубы
					FourPC.position = 1;//положение корабл.
					FourPC.decks = 4;//колич. палуб
					firstDeck++;//чтобы не входить в блок дважды
				}
				else if (decks == 3 && firstDeck == 1)
				{
					Three1PC.firstDeckAdress = &compField[row][col];
					Three1PC.position = 1;
					Three1PC.decks = 3;
					firstDeck++;
				}
				else if (decks == 3 && firstDeck == 2 && j == 2)
				{
					Three2PC.firstDeckAdress = &compField[row][col];
					Three2PC.position = 1;
					Three2PC.decks = 3;
					firstDeck++;
				}
				else if (decks == 2 && firstDeck == 1)
				{
					Two1PC.firstDeckAdress = &compField[row][col];
					Two1PC.position = 1;
					Two1PC.decks = 2;
					firstDeck++;
				}
				else if (decks == 2 && firstDeck == 2 && j == 2)
				{
					Two2PC.firstDeckAdress = &compField[row][col];
					Two2PC.position = 1;
					Two2PC.decks = 2;
					firstDeck++;
				}
				else if (decks == 2 && firstDeck == 3 && j == 3)
				{
					Two3PC.firstDeckAdress = &compField[row][col];
					Two3PC.position = 1;
					Two3PC.decks = 2;
					firstDeck++;
				}
				row++;
				i--;
			}
			break;
		case 2:         //горизонталь               
			while (k <= i)
			{
				compField[row][col] = 1;
				if (decks == 4 && firstDeck == 1)
				{
					FourPC.firstDeckAdress = &compField[row][col];
					FourPC.position = 2;
					FourPC.decks = 4;
					firstDeck++;
				}
				else if (decks == 3 && firstDeck == 1)
				{
					Three1PC.firstDeckAdress = &compField[row][col];
					Three1PC.position = 2;
					Three1PC.decks = 3;
					firstDeck++;
				}
				else if (decks == 3 && firstDeck == 2 && j == 2)
				{
					Three2PC.firstDeckAdress = &compField[row][col];
					Three2PC.position = 2;
					Three2PC.decks = 3;
					firstDeck++;
				}
				else if (decks == 2 && firstDeck == 1)
				{
					Two1PC.firstDeckAdress = &compField[row][col];
					Two1PC.position = 2;
					Two1PC.decks = 2;
					firstDeck++;
				}
				else if (decks == 2 && firstDeck == 2 && j == 2)
				{
					Two2PC.firstDeckAdress = &compField[row][col];
					Two2PC.position = 2;
					Two2PC.decks = 2;
					firstDeck++;
				}
				else if (decks == 2 && firstDeck == 3 && j == 3)
				{
					Two3PC.firstDeckAdress = &compField[row][col];
					Two3PC.position = 2;
					Two3PC.decks = 2;
					firstDeck++;
				}
				col++;
				i--;
			}
			break;
		}
	}
	SetPCShips(decks - 1, number + 1);//уменш. палуб - увел. кол. корабл.
}
void BattleField::Move()
{	
	if (firstMove == 0)
	{
		do
		{
			at1: SetColor(LightGreen, Black);
			cout << "Кто ходит первым ? \n";
			SetColor(LightGreen, Black);
			cout << "Компьютер(1)  Пользователь(2) =  \n";
			SetColor(White, Black);
			cin >> firstMove;
			if (firstMove < 1 || firstMove > 2)
			{
				SetColor(White, LightRed);
				cout << "\n Неверный выбор \n";
				SetColor(White, Black);
				goto at1;
			}
		} while (firstMove < 1 || firstMove > 2);
	}
	if (firstMove == 2)
		PlayerMove();
	else if (firstMove == 1)
		PCMove();
	system("pause");
	return;
}
void BattleField::PlayerMove()//хода польз.
{
	if (!IfWin())//проверка на победителя
	{
		SetColor(White, Black);
		cout << "\n\t\t";
		SetColor(White, LightRed);
		cout << " GAME OVER \n";
		SetColor(LightGreen, Black);
		cout << "\nПобедил Пользователь со счетом = " << countPlayer << " Компьютер = " << countPC << endl;
		SetColor(White, Black);
		return;
	}
	int row, col;
	char сolumn;
	do { 
		at2: SetColor(LightGreen, Black);
		cout << "\nПроизведите выстрел введя координаты (a2)__ ";
		cout << "Введите координаты по горизонтали например(а)\n";
		cin >> сolumn;
		cout << "Введите координаты по вертикали например(5)\n";
		cin >> row;
		col = Translation(сolumn);
		if ((!col) || (row < 1) || (row > 10))
		{
			SetColor(White, LightRed);
			cout << "\n Неверные координаты \n\n";
			SetColor(White, Black);
			goto at2;
		}
	} while ((!col) || (row < 1) || (row > 10));
	if (compField[row][col] == 1)//если попали
	{
		hit = 1;
		int *hit = &compField[row][col];//адрес ранен. кор. чтобы обвести если убит
		compField[row][col] = 3;//присв. 3
		IfHittedPCShip(hit);
		DrawPlayer();
		DrawComp();
		PlayerMove();
		if (!IfWin())
		{
			return;
		}
	}
	else if (compField[row][col] != 3 && compField[row][col] != 1)//если мимо
	{		
		compField[row][col] = 2;      //присв. 2
		hit = 0;
		DrawPlayer();
		DrawComp();
		PCMove();
	}	
	if (!IfWin())
	{
		return;
	}
}
void BattleField::PCMove()// ход РС
{
	
	in:if (!IfWin())//проверка на победителя
	{
		SetColor(White, Black);
		cout << "\n\t\t";
		SetColor(White, LightRed);
		cout << " ИГРА ОКОНЧЕНА \n";
		SetColor(LightGreen, Black);
		cout << "\nПобедил Компьютер со счетом Компьютер = " << countPC << " Пользователь = " << countPlayer << endl;
		SetColor(White, Black);
		return;
	}
	if (!hit)//если не ранил
	{			
		int rows = 1 + rand() % 10;
		int cols = 1 + rand() % 10;
		moves = &playerField[rows][cols];
		do
		{
			rows = 1 + rand() % 10;
			cols = 1 + rand() % 10;
			moves = &playerField[rows][cols];			
		} while (!IfPCMoveRepeat(moves));
		moveAddressPC[indexMovePC] = &playerField[rows][cols];
		indexMovePC++;
		if (playerField[rows][cols] == 1)//если попал
		{
			hit = 1;
			playerField[rows][cols] = 3;//присвоить 3
			int *hits = &playerField[rows][cols];
			firstHittedDeck = &playerField[rows][cols];
			hitsCount++;
			IfHittedPlayerShip(hits);  //проверка на ранение  
			DrawPlayer();
			DrawComp();
			PCMove();
			if (!IfWin())
			{
				return;
			}
		}
		else
		{
			playerField[rows][cols] = 2; //иначе присв. 2
			hit = 0;
		}
		DrawPlayer();
		DrawComp();
		SetColor(LightRed, Black);
		cout << "\nКомпьютер походил !" << endl << endl;
		SetColor(White, Black);
		PlayerMove();
		if (!IfWin())
		{
			return;
		}
	}
	if (hit)//если ранен
	{
		int *hits = &*(firstHittedDeck);
		do {
		in2:
			if (hitsCount == 1)
				hits = &*(firstHittedDeck + 1);//вправо на 1
				
			if (hitsCount == 2)
				hits = &*(firstHittedDeck - 1);//влево на 1
			
			if (hitsCount == 3)
				if (*(firstHittedDeck + 1) != 2)
					hits = &*(firstHittedDeck + 2);//если вправо на 1 !=2 вправо на 2
				else
					hitsCount++;
			if (hitsCount == 4)
				if (*(firstHittedDeck - 1) != 2)
					hits = &*(firstHittedDeck - 2);//если влево на 1 !=2 влево на 2
				else
					hitsCount++;
			if (hitsCount == 5)
				if (*(firstHittedDeck + 1) != 2)
					hits = &*(firstHittedDeck + 3);//если вправо на 1 !=2 вправо на 3
				else
					hitsCount++;
			if (hitsCount == 6)
				if (*(firstHittedDeck - 1) != 2)
					hits = &*(firstHittedDeck - 3);//если влево на 1 !=2 влево на 3
				else
					hitsCount++;
			if (hitsCount == 7)
				hits = &*(firstHittedDeck + 12);//значит корабль стоит вертикально - в низ на 1
			if (hitsCount == 8)
				hits = &*(firstHittedDeck - 12);//вверх на 1
			if (hitsCount == 9)
				if (*(firstHittedDeck - 12) != 2)
					hits = &*(firstHittedDeck - 24);//если вверх на 1 !=2 то вверх на 2
				else
					hitsCount++;
			if (hitsCount == 10)
				if (*(firstHittedDeck + 12) != 2)
					hits = &*(firstHittedDeck + 24);//если вниз на 1 !=2 то вниз на 2
				else
					hitsCount++;
			if (hitsCount == 11)
				if (*(firstHittedDeck - 12) != 2)
					hits = &*(firstHittedDeck - 36);//если вверх на 1 !=2 то вверх на 3
				else
					hitsCount++;
			if (hitsCount == 12)
				if (*(firstHittedDeck + 12) != 2)
					hits = &*(firstHittedDeck + 36);//если вниз на 1 !=2 то вниз на 3
				else
					hitsCount++;
			moves = &*hits; 
			hitsCount++;
			if (hitsCount > 12)
				goto in3;
		} while (!IfPCMoveRepeat(moves));//проверит ходил ли уже так
		moveAddressPC[indexMovePC] = &*(hits);//запись хода
		indexMovePC++;		
		if (*hits == 1)//если попал
		{
			*hits = 3;
			IfHittedPlayerShip(hits);  //проверка 
			DrawPlayer();
			DrawComp();	
			PCMove();			
			if (!IfWin())
			{
				return;
			}			
		}
		else
		{			
			*hits = 2;
			hit = 0;
			goto in2;
		}
		in3:
		DrawPlayer();
		DrawComp();
		SetColor(LightRed, Black);
		cout << "\nКомпьютер походил !" << endl << endl;
		SetColor(White, Black);hit = 1;
		PlayerMove();
		if (!IfWin())
		{
			return;
		}		
	}
}
