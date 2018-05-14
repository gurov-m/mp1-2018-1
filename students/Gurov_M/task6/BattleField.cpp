#include "BattleField.h"
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
	cout << "\t\t ���� ������\n\n";
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
			else if (playerField[i][j] == 1)//���� 1 ������ ������� 
			{
				cout << "|";
				SetColor(Green, Green);
				cout << '0' << "  ";
				SetColor(White, Black);
			}
			else if (playerField[i][j] == 2)//���� 2 ���� ������ �����
			{
				cout << "| ";
				SetColor(Yellow, Black);
				cout << 'x' << " ";
				SetColor(White, Black);
			}
			else if (playerField[i][j] == 3)//���� 3 ����� ��� ���� ���� �����
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
	cout << "\n\t\t ���� ����������\n\n";
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
				else if (compField[i][j] == 1)//���� 1 ���������� �������
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
	cout << "�������� ����������� ��������:" << endl;
	SetColor(LightGreen, Black);
	cout << "1) �������������� �����������" << endl;
	SetColor(LightGreen, Black);
	cout << "2) ����������� �������" << endl;
	cin >> choice;
	if (choice<1 || choice>2)
	{
		SetColor(White, LightRed);
		cout << "\n �������� ����� \n";
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
void BattleField::AutomaticFloatSetting(int decks, int number)//�������������� ���c������� �������� ������������
{
	if (!decks)//����� 0 - �����
		return;
	int firstDeck = 1;//��� ������ � ���������
	for (int j = 1; j <= number; j++)//j ���������� �������� ������ ����
	{
		int *deckAdress;//��������� �� ����� ������ 
		int row, col;//������ - ������� �������
		int random = 1 + rand() % 2;//�� ����������� ��� �� ���������
		int k = 1, i = decks;//k ������� i ������� ������
		if (random == 1)//���������
		{
			do {
				do {
					row = rand() % 10 + 1;
				} while (row + decks > 11);//����� �� ����� �� ������� �������
				col = rand() % 10 + 1;
				deckAdress = &playerField[row][col];
			} while (!SearchAddress(deckAdress, decks, random));//�������� ������� �� ����� ������           
		}
		else if (random == 2)//�����������
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
		case 1:     //���������         
			while (k <= i)//k ������� i ������� ������
			{
				playerField[row][col] = 1;
				if (decks == 4 && firstDeck == 1)
				{
					FourPlay.firstDeckAdress = &playerField[row][col];     //������ � ��������� ������ ������ ����� ������ ������
					FourPlay.position = 1;//��������� �������
					FourPlay.decks = 4;//���. �����
					firstDeck++;//����� ������ �� ���. ������ �������. �����
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
		case 2:         //�����������               
			while (k <= i)
			{
				playerField[row][col] = 1;
				if (decks == 4 && firstDeck == 1)
				{
					FourPlay.firstDeckAdress = &playerField[row][col];     //������ � ��������� ������ ������ ����� ������ ������
					FourPlay.position = 2;//��������� �������
					FourPlay.decks = 4;//���. �����
					firstDeck++;//����� ������ �� ���. ������ �������. �����
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
	AutomaticFloatSetting(decks - 1, number + 1);//��������� ����� - ���������� ���. ���.
}
void BattleField::ManualFloatSetting(int decks, int number)//���������� � ������
{
	DrawPlayer();
	int *deckAdress;//��������� �� ����� ������ 
	int row, col;//������ - ������� �������
	int choice1 = 0;//�� ����������� ��� �� ���������        
	char column;
	if (!decks)
		return;
	int firstDeck = 1;
	for (int j = 1; j <= number; j++)//j ���������� �������� ������ ����
	{
		do {
			cout << decks << " - �������� �������\n";
			cout << "������� ���������� ������� �� ����������� ��������(�)\n";
			cin >> column;
			cout << "������� ���������� ������� �� ��������� ��������(5)\n";
			cin >> row;
			col = Translation(column);
			if ((col < 1) || (col > 10) || (row < 1) || (row > 10))
			{
				SetColor(Blue, LightRed);
				cout << " �������� ���������� \n";
				SetColor(White, Black);
			}
		} while ((!col) || (row < 1) || (row > 10));
		int k = 1, i = decks;//k ������� i ������� ������      
		if (decks > 1)
		{
			do {
				cout << "��� �� ������ ���������� ���� " << decks << " �������� ������� \n�����������(1)  �������������(2) = ";
				cin >> choice1;
				if (choice1 < 1 || choice1 > 2)
				{
					SetColor(White, LightRed);
					cout << " �������� ���������� \n";
					SetColor(White, Black);
				}
			} while (choice1 < 1 || choice1 > 2);
		}
		if (decks == 1)//��� �������������
			choice1 = 1;
		if (choice1 == 1)//���������
		{
			do {
				if (errors)//�������� �������
				{
					SetColor(White, LightRed);
					cout << " �������� ���������� \n";
					SetColor(White, Black);
					do {
						cout << decks << " - �������� �������\n";
						cout << "������� ���������� ������� �� ����������� ��������(�)\n";
						cin >> column;
						cout << "������� ���������� ������� �� ��������� ��������(5)\n";
						cin >> row;
						col = Translation(column);
						if ((!col) || (row < 1) || (row > 10))
						{
							SetColor(White, LightRed);
							cout << " �������� ���������� \n";
							SetColor(White, Black);
						}
					} while ((!col) || (row < 1) || (row > 10));
					errors = 0;
				}
				if (row + decks>11)//�������� �� ����� �� ������� �������
					do {
						SetColor(White, LightRed);
						cout << " �������� ���������� \n";
						SetColor(White, Black);
						do {
							cout << decks << " - �������� �������\n";
							cout << "������� ���������� ������� �� ����������� ��������(�)\n";
							cin >> column;
							cout << "������� ���������� ������� �� ��������� ��������(5)\n";
							cin >> row;
							col = Translation(column);
							if ((!col) || (row < 1) || (row > 10))
							{
								SetColor(White, LightRed);
								cout << " �������� ���������� \n";
								SetColor(White, Black);
							}
						} while ((!col) || (row < 1) || (row > 10));
					} while (row + decks > 11); //�������� �� ����� �� ������� �������          
					deckAdress = &playerField[row][col];  //������ ������             
			} while (!SearchAddress(deckAdress, decks, choice1)); //�������� �� ���������� �������        
		}
		else if (choice1 == 2)//�����������
		{
			do {
				if (errors)//�������� �������
				{
					SetColor(White, LightRed);
					cout << " �������� ���������� \n";
					SetColor(White, Black);
					do {
						cout << decks << " - �������� �������\n";
						cout << "������� ���������� ������� �� ����������� ��������(�)\n";
						cin >> column;
						cout << "������� ���������� ������� �� ��������� ��������(5)\n";
						cin >> row;
						col = Translation(column);
						if ((!col) || (row<1) || (row>10))
						{
							SetColor(White, LightRed);
							cout << " �������� ���������� \n";
							SetColor(White, Black);
						}
					} while ((!col) || (row < 1) || (row > 10));
					errors = 0;
				}
				if (col + decks > 11)//�������� �� ����� �� ������� �������
					do {
						SetColor(White, LightRed);
						cout << " �������� ���������� \n";
						SetColor(White, Black);
						do {
							cout << decks << " - �������� �������\n";
							cout << "������� ���������� ������� �� ����������� ��������(�)\n";
							cin >> column;
							cout << "������� ���������� ������� �� ��������� ��������(5)\n";
							cin >> row;
							col = Translation(column);
							if ((!col) || (row < 1) || (row > 10))
							{
								SetColor(White, LightRed);
								cout << " �������� ���������� \n";
								SetColor(White, Black);
							}
						} while ((!col) || (row < 1) || (row > 10));
					} while (col + decks > 11);
					deckAdress = &playerField[row][col];
			} while (!SearchAddress(deckAdress, decks, choice1));
		}
		switch (choice1)
		{
		case 1:     //���������         
			while (k <= i)//k ������� i ������� ������
			{
				playerField[row][col] = 1;
				if (decks == 4 && firstDeck == 1)
				{
					FourPlay.firstDeckAdress = &playerField[row][col];     //������ � ��������� ������ ������ ����� ������ ������
					FourPlay.position = 1;//��������� �������
					FourPlay.decks = 4;//���. �����
					firstDeck++;//����� ������ �� ���. ������ �������. �����
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
		case 2:         //�����������               
			while (k <= i)
			{
				playerField[row][col] = 1;
				if (decks == 4 && firstDeck == 1)
				{
					FourPlay.firstDeckAdress = &playerField[row][col];     //������ � ��������� ������ ������ ����� ������ ������
					FourPlay.position = 2;//��������� �������
					FourPlay.decks = 4;//���. �����
					firstDeck++;//����� ������ �� ���. ������ �������. �����
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
	ManualFloatSetting(decks - 1, number + 1);//��������� ����� - ���������� ���. ���.
}
void BattleField::SetPCShips(int decks, int number)
{
	if (!decks)
		return;
	int firstDeck = 1;
	for (int j = 1; j <= number; j++)//j ���������� �������� ������ ����
	{
		int *deckAdress;//��������� �� ����� ������ 
		int row, col;//������ - ������� �������
		int random = 1 + rand() % 2;//�� ����������� ��� �� ���������
		int k = 1, i = decks;//k ������� i ������� ������
		if (random == 1)//���������
		{
			do {
				do {
					row = rand() % 10 + 1;
				} while (row + decks>11);//����� �� ����� �� ������� �������
				col = rand() % 10 + 1;
				deckAdress = &compField[row][col];//������ ��� �������� �� ����������
			} while (!SearchPCAddress(deckAdress, decks, random));//-----------------//������� �-�         
		}
		else if (random == 2)//�����������
		{
			do {
				do {
					col = rand() % 10 + 1;
				} while (col + decks>11);//����� �� ����� �� ������� �������
				row = rand() % 10 + 1;
				deckAdress = &compField[row][col];//������ ��� �������� �� ����������
			} while (!SearchPCAddress(deckAdress, decks, random));//-----------------//������� �-�     
		}
		switch (random)
		{
		case 1:     //���������         
			while (k <= i)//k ������� i ������� ������
			{
				compField[row][col] = 1;//��������� ������ 1
				if (decks == 4 && firstDeck == 1)
				{
					FourPC.firstDeckAdress = &compField[row][col];  //������ � ��������� ������ ������ ������
					FourPC.position = 1;//��������� ������.
					FourPC.decks = 4;//�����. �����
					firstDeck++;//����� �� ������� � ���� ������
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
		case 2:         //�����������               
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
	SetPCShips(decks - 1, number + 1);//�����. ����� - ����. ���. ������.
}
void BattleField::Move()
{
	
		if (firstMove == 0)
		{
			do
			{
				SetColor(LightGreen, Black);
				cout << "��� ����� ������ ? \n";
				SetColor(LightGreen, Black);
				cout << "���������(1)  ������������(2) =  \n";
				SetColor(White, Black);
				cin >> firstMove;
				if (firstMove < 1 || firstMove > 2)
				{
					SetColor(White, LightRed);
					cout << "\n �������� ����� \n";
					SetColor(White, Black);
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
void BattleField::PlayerMove()//���� �����.
{
	if (!IfWin())//�������� �� ����������
	{
		SetColor(White, Black);
		cout << "\n\t\t";
		SetColor(White, LightRed);
		cout << " GAME OVER \n";
		SetColor(LightGreen, Black);
		cout << "\n������� ������������ �� ������ = " << countPlayer << " ��������� = " << countPC << endl;
		SetColor(White, Black);
		return;
	}
	int row, col;
	char �olumn;
	do { 
		SetColor(LightGreen, Black);
		cout << "\n����������� ������� ����� ���������� (a2)__ ";
		cout << "������� ���������� �� ����������� ��������(�)\n";
		cin >> �olumn;
		cout << "������� ���������� �� ��������� ��������(5)\n";
		cin >> row;
		col = Translation(�olumn);
		if ((!col) || (row < 1) || (row > 10))
		{
			SetColor(White, LightRed);
			cout << "\n �������� ���������� \n\n";
			SetColor(White, Black);
		}
	} while ((!col) || (row < 1) || (row > 10));
	if (compField[row][col] == 1)//���� ������
	{
		int *hit = &compField[row][col];//����� �����. ���. ����� ������� ���� ����
		compField[row][col] = 3;//�����. 3
		IfHittedPCShip(hit);
		DrawPlayer();
		DrawComp();
		PlayerMove();
		if (!IfWin())
		{
			return;
		}
	}
	else if (compField[row][col] != 3 && compField[row][col] != 1)//���� ����
	{
		compField[row][col] = 2;      //�����. 2
	}
	DrawPlayer();
	DrawComp();
	PCMove();
	if (!IfWin())
	{
		return;
	}
}
void BattleField::PCMove()// ��� ��
{
	if (!IfWin())//�������� �� ����������
	{
		SetColor(White, Black);
		cout << "\n\t\t";
		SetColor(White, LightRed);
		cout << " ���� �������� \n";
		SetColor(LightGreen, Black);
		cout << "\n������� ��������� �� ������ ��������� = " << countPC << " ������������ = " << countPlayer << endl;
		SetColor(White, Black);
		//system("pause");
		return;
	}
	int *moves;
	int rows = 1, cols = 1, step = 1;//��� ���� ����� �� ������� ����� ������
	int *firstHittedDeck = 0;//����� ������ ������� ������
	if (!hit)//���� �� �����
	{
		for (; step <= 2; )//step1 *_  step2 _*
		{
			for (; rows < 11; rows++, (step == 1) ? ((rows % 2 == 0) ? cols = 2 : cols = 1) : ((rows % 2 == 0) ? cols = 1 : cols = 2))//��� ������ *_ ��� _*
			{
				for (; cols < 11; )
				{
					moves = &playerField[rows][cols];
					if (!IfPCMoveRepeat(moves))//����� �� ������ � ��-�� �����
					{
						cols += 2;
						continue;
					}
					moveAddressPC[indexMovePC] = &playerField[rows][cols];
					indexMovePC++;
					if (playerField[rows][cols] == 1)//���� �����
					{
						playerField[rows][cols] = 3;//��������� 3
						int *hit = &playerField[rows][cols];
						IfHittedPlayerShip(hit);  //�������� �� �������  
						DrawPlayer();
						DrawComp();
						cols += 2;
						PCMove();
						if (!IfWin())
						{
							return;
						}
					}
					else
					{
						playerField[rows][cols] = 2; //����� �����. 2
						cols += 2;
					}
					DrawPlayer();
					DrawComp();
					SetColor(LightRed, Black);
					cout << "\n��������� ������� !" << endl << endl;
					SetColor(White, Black);
					PlayerMove();
					if (!IfWin())
					{
						//system("pause");
						return;
					}
				}
			}
			if (rows == 11 && cols == 1)
				rows = 1;
			cols = 2;
			step++;
		}
	}
	if (hit)//���� �����
	{
		int *hit = &*(firstHittedDeck);
		do {
			if (hitsCount == 1)
				hit = &*(firstHittedDeck + 1);//������ �� 1
			if (hitsCount == 2)
				hit = &*(firstHittedDeck - 1);//����� �� 1
			if (hitsCount == 3)
				if (*(firstHittedDeck + 1) != 2)
					hit = &*(firstHittedDeck + 2);//���� ������ �� 1 !=2 ������ �� 2
				else
					hitsCount++;
			if (hitsCount == 4)
				if (*(firstHittedDeck - 1) != 2)
					hit = &*(firstHittedDeck - 2);//���� ����� �� 1 !=2 ����� �� 2
				else
					hitsCount++;
			if (hitsCount == 5)
				if (*(firstHittedDeck + 1) != 2)
					hit = &*(firstHittedDeck + 3);//���� ������ �� 1 !=2 ������ �� 3
				else
					hitsCount++;
			if (hitsCount == 6)
				if (*(firstHittedDeck - 1) != 2)
					hit = &*(firstHittedDeck - 3);//���� ����� �� 1 !=2 ����� �� 3
				else
					hitsCount++;
			if (hitsCount == 7)
				hit = &*(firstHittedDeck + 12);//������ ������� ����� ����������� - � ��� �� 1
			if (hitsCount == 8)
				hit = &*(firstHittedDeck - 12);//����� �� 1
			if (hitsCount == 9)
				if (*(firstHittedDeck - 12) != 2)
					hit = &*(firstHittedDeck - 24);//���� ����� �� 1 !=2 �� ����� �� 2
				else
					hitsCount++;
			if (hitsCount == 10)
				if (*(firstHittedDeck + 12) != 2)
					hit = &*(firstHittedDeck + 24);//���� ���� �� 1 !=2 �� ���� �� 2
				else
					hitsCount++;
			if (hitsCount == 11)
				if (*(firstHittedDeck - 12) != 2)
					hit = &*(firstHittedDeck - 36);//���� ����� �� 1 !=2 �� ����� �� 3
				else
					hitsCount++;
			if (hitsCount == 12)
				if (*(firstHittedDeck + 12) != 2)
					hit = &*(firstHittedDeck + 36);//���� ���� �� 1 !=2 �� ���� �� 3
				else
					hitsCount++;
			moves = &*hit;
			hitsCount++;
		} while (!IfPCMoveRepeat(moves));//�������� ����� �� ��� ���
		moveAddressPC[indexMovePC] = &*(hit);//������ ����
		indexMovePC++;
		if (*hit == 1)//���� �����
		{
			*hit = 3;
			IfHittedPCShip(hit);  //�������� 
			DrawPlayer();
			DrawComp();
			PCMove();
			if (!IfWin())
			{
				//system("pause");
				return;
			}
		}
		else
		{
			*hit = 2;
		}
		DrawPlayer();
		DrawComp();
		SetColor(LightRed, Black);
		cout << "\n��������� ������� !" << endl << endl;
		SetColor(White, Black);
		PlayerMove();
		if (!IfWin())
		{
			//system("pause");
			return;
		}
	}
}
