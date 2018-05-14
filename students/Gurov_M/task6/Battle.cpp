#include "Battle.h"
enum ConsoleColor { Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray, LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White };
HANDLE hConsole2 = GetStdHandle(STD_OUTPUT_HANDLE);
void SetColor2(ConsoleColor text, ConsoleColor background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
int Battle::IfWin()
{
	countPlayer = 0; 
	countPC = 0;
	for (int i = 1; i< Rows - 1; i++)
	{
		for (int j = 1; j< Cols - 1; j++)
		{
			if (playerField[i][j] == 3)
				countPC++;
		}
	}

	for (int i = 1; i<Rows - 1; i++)
	{
		for (int j = 1; j<Cols - 1; j++)
		{
			if (compField[i][j] == 3)
				countPlayer++;
		}
	}
	if (countPC == 20)
	{
		return 0;
	}
	else if (countPlayer == 20)
	{
		return 0;
	}
	else
		return 1;
}
void Battle::SetAddress(int *deckAddress, int decks, int position)//���������� ������ ���. � ������ ���
{
	if (position == 1)//���� ������� �� ���������
	{
		int *deckAddress1 = &*(deckAddress - 1);
		int *deckAddress2 = &*(deckAddress + 1);
		for (int i = 0; i < decks + 2; i++)//����� �������
		{
			playerShipAddress[playerInd] = &*deckAddress;
			playerInd++;
			*(deckAddress -= 12);
			playerShipAddress[playerInd] = &*deckAddress1;
			playerInd++;
			*(deckAddress1 -= 12);
			playerShipAddress[playerInd] = &*deckAddress2;
			playerInd++;
			*(deckAddress2 -= 12);
		}
	}
	else if (position == 2)//�� �����������
	{
		int *deckAddress1 = &*(deckAddress + 12);
		int *deckAddress2 = &*(deckAddress - 12);
		for (int i = 0; i< decks + 2; i++)//����� �������
		{
			playerShipAddress[playerInd] = &*deckAddress;
			playerInd++;
			*(deckAddress -= 1);
			playerShipAddress[playerInd] = &*deckAddress1;
			playerInd++;
			*(deckAddress1 -= 1);
			playerShipAddress[playerInd] = &*deckAddress2;
			playerInd++;
			*(deckAddress2 -= 1);
		}
	}
}
int Battle::SearchAddress(int *deckAddress, int decks, int random)//���� ���� �� ���������� ������� , ���� = 0 , ��� = 1
{
	//������ �������� ������������
	for (int a = 1; a <= decks; a++)//�������� ������ ������ 
	{
		if (random == 1)
		{
			for (int i = 0; i < 144; i++)
			{
				if (deckAddress == playerShipAddress[i])
				{
					errors = 1;// ������ ��� ������� �����
					return 0;
				}
			}
			*(deckAddress += 12);
		}
		else if (random == 2)
		{
			for (int i = 0; i < 144; i++)
			{
				if (deckAddress == playerShipAddress[i])
				{
					errors = 1;// ������ ��� ������� �����
					return 0;
				}
			}
			*(deckAddress += 1);
		}
	}
	SetAddress(deckAddress, decks, random);//��� ���������� ���������� ������
	return 1;
}
int Battle::Translation(char symbol)//��������� ����. ���������. �������
{
	switch (symbol)
	{
		case 'a':
		{
			return 1;
		}
		case 'b':
		{
			return 2;
		}
		case 'c':
		{
			return 3;
		}
		case 'd':
		{
			return 4;
		}
		case 'e':
		{
			return 5;
		}
		case 'f':
		{
			return 6;
		}
		case 'g':
		{
			return 7;
		}
		case 'h':
		{
			return 8;
		}
		case 'i':
		{
			return 9;
		}
		case 'j':
		{
			return 10;
		}
		default:
		{
			return 0;
		}
	}
}
int Battle::SearchPCAddress(int *deckAdress, int decks, int random)//���� �� ��� ���� ����� - ���� ��� 1 �������� ������ ����� 0 ����. ��.
{
	for (int a = 1; a <= decks; a++)//�������� ������ ������ 
	{
		if (random == 1)
		{
			for (int i = 0; i < 144; i++)
			{
				if (deckAdress == pcShipAddress[i])
					return 0;
			}
			*(deckAdress += 12);
		}
		else if (random == 2)
		{
			for (int i = 0; i < 144; i++)
			{
				if (deckAdress == pcShipAddress[i])
					return 0;
			}
			*(deckAdress += 1);
		}
	}
	SetPCAddress(deckAdress, decks, random);
	return 1;
}
void Battle::SetPCAddress(int *deckAddress, int decks, int random)//������ ��������
{
	if (random == 1)//���� �� ���������
	{
		int *deckAddress1 = &*(deckAddress - 1);
		int *deckAddress2 = &*(deckAddress + 1);
		for (int i = 0; i < decks + 2; i++)// ������ ������. � ������ ����
		{
			pcShipAddress[pcInd] = &*deckAddress;
			pcInd++;
			*(deckAddress -= 12);
			pcShipAddress[pcInd] = &*deckAddress1;
			pcInd++;
			*(deckAddress1 -= 12);
			pcShipAddress[pcInd] = &*deckAddress2;
			pcInd++;
			*(deckAddress2 -= 12);
		}
	}
	else if (random == 2)//��������.
	{
		int *deckAddress1 = &*(deckAddress + 12);
		int *deckAddress2 = &*(deckAddress - 12);
		for (int i = 0; i < decks + 2; i++)
		{
			pcShipAddress[pcInd] = &*deckAddress;
			pcInd++;
			*(deckAddress -= 1);
			pcShipAddress[pcInd] = &*deckAddress1;
			pcInd++;
			*(deckAddress1 -= 1);
			pcShipAddress[pcInd] = &*deckAddress2;
			pcInd++;
			*(deckAddress2 -= 1);
		}
	}
}
void Battle::EncircleDeadPCShip(int *firstdeck, int position, int decks)//������� ������ �������
{
	if (position == 1)
	{
		int *deck3 = &*(firstdeck - 12);
		if (*deck3 != 2)
		{
			moveAddressPC[indexMovePC] = &*(deck3);
			indexMovePC++;
		}
		*deck3 = 2;
		int *deck1 = &*(deck3 - 1);
		int *deck2 = &*(deck3 + 1);
		for (int i = 0; i < decks + 2; i++)
		{
			if (*deck1 != 3) 
			{
				if (*deck1 != 2) 
				{
					moveAddressPC[indexMovePC] = &*(deck1);
					indexMovePC++;
				}
				*deck1 = 2;
			}
			*(deck1 += 12);
			if (*deck2 != 3)
			{
				if (*deck2 != 2) 
				{
					moveAddressPC[indexMovePC] = &*(deck2);
					indexMovePC++;
				}
				*deck2 = 2;
			}
			*(deck2 += 12);
			if (i == decks + 1)
			{
				*(deck2 -= 13);
				if (*deck2 != 2)
				{
					moveAddressPC[indexMovePC] = &*(deck2);
					indexMovePC++;
				}
				*deck2 = 2;
			}
		}
	}
	else if (position == 2)
	{
		int *deck3 = &*(firstdeck - 1);
		if (*deck3 != 2) 
		{
			moveAddressPC[indexMovePC] = &*(deck3);
			indexMovePC++;
		}
		*deck3 = 2;
		int *deck1 = &*(deck3 - 12);
		int *deck2 = &*(deck3 + 12);
		for (int i = 0; i < decks + 2; i++)
		{
			if (*deck1 != 3) 
			{
				if (*deck1 != 2)
				{
					moveAddressPC[indexMovePC] = &*(deck1);
					indexMovePC++;
				}
				*deck1 = 2;
			}
			*(deck1 += 1);
			if (*deck2 != 3) 
			{
				if (*deck2 != 2) 
				{
					moveAddressPC[indexMovePC] = &*(deck2);
					indexMovePC++;
				}
				*deck2 = 2;
			}
			*(deck2 += 1);
			if (i == decks + 1)
			{
				*(deck1 += 11);
				if (*deck1 != 2) 
				{
					moveAddressPC[indexMovePC] = &*(deck1);
					indexMovePC++;
				}
				*deck1 = 2;
			}
		}
	}
}
void Battle::EncircleDeadPlayerShip(int *firstdeck, int position, int decks)//����� ������ �������
{
	if (position == 1)//���������
	{
		int *deck3 = &*(firstdeck - 12);
		*deck3 = 2;
		int *deck1 = &*(deck3 - 1);
		int *deck2 = &*(deck3 + 1);
		for (int i = 0; i < decks + 2; i++)
		{
			if (*deck1 != 3)
				*deck1 = 2;
			*(deck1 += 12);
			if (*deck2 != 3)
				*deck2 = 2;
			*(deck2 += 12);
			if (i == decks + 1)
			{
				*(deck2 -= 13);
				*deck2 = 2;
			}
		}
	}
	else if (position == 2)//�����������
	{
		int *deck3 = &*(firstdeck - 1);
		*deck3 = 2;
		int *deck1 = &*(deck3 - 12);
		int *deck2 = &*(deck3 + 12);
		for (int i = 0; i < decks + 2; i++)
		{
			if (*deck1 != 3)
				*deck1 = 2;
			*(deck1 += 1);
			if (*deck2 != 3)
				*deck2 = 2;
			*(deck2 += 1);
			if (i == decks + 1)
			{
				*(deck1 += 11);
				*deck1 = 2;
			}
		}
	}
}
int Battle::IfPCMoveRepeat(int *moves)//��������� ����� �� ����������
{
	for (int i = 0; i < 144; i++)
	{
		if (moves == moveAddressPC[i])
		{
			return 0;
		}
	}
	return 1;
}
void Battle::IfPlayerShipDead(int *firstdeck, int position, int decks)//�������� ���� �� ���. ���� �� �� ������� �-� ������� obvodUbitKor
{
	int count = 0;
	int *firstdeckAddress = &*(firstdeck);//����� ������ ������

	if (position == 1)
	{
		for (int i = 0, j = 12; i < decks; i++)
		{
			if (*(firstdeckAddress) == 3)
			{
				*(firstdeckAddress += j);
				count++;
			}
			if (count == decks)
				EncircleDeadPlayerShip(firstdeck, position, decks);
		}
	}

	else if (position == 2)
	{
		for (int i = 0, j = 1; i < decks; i++)
		{
			if (*(firstdeckAddress) == 3)
			{
				*(firstdeckAddress += j);
				count++;
			}
			if (count == decks)
				EncircleDeadPlayerShip(firstdeck, position, decks);
		}
	}
}
void Battle::IfPCShipDead(int *firstdeck, int position, int decks)//���� ���� �� ����. �-� ������ � �������� ��������� ����� 
{
	int *firstHittedDeck;
	int count = 0;
	int *firstdeckAddress = *&(firstdeck);
	if (position == 1)
	{
		for (int i = 0, j = 12; i < decks; i++)
		{
			if (*(firstdeckAddress) == 3)
			{
				count++;
				hit = 1;
				if (hitsCount == 1)
					firstHittedDeck = &*(firstdeckAddress);  // ����������� ����� ������ ������� ���������
			}
			if (count == decks) {//������ ����
				EncircleDeadPCShip(firstdeck, position, decks);//    �����
				hit = 0;//����� �������
				hitsCount = 1;
			}
			*(firstdeckAddress += j);
		}
	}
	else if (position == 2)
	{
		for (int i = 0, j = 1; i < decks; i++)
		{
			if (*(firstdeckAddress) == 3)
			{
				count++;
				hit = 1;
				if (hitsCount == 1)
					firstHittedDeck = &*(firstdeckAddress);  //�������   obvodPal ��     obvod               
			}
			if (count == decks) {
				EncircleDeadPCShip(firstdeck, position, decks);
				hit = 0;
				hitsCount = 1;
			}
			*(firstdeckAddress += j);
		}
	}
}
// ����� ���� ������� ������������ DrawPlayer � DrawPC
void Battle::IfHittedPlayerShip(int*hit)//����� ������� � ������� ������
{
	if ((*(hit + 1) != 1) && (*(hit - 1) != 1) && (*(hit + 12) != 1) && (*(hit - 12) != 1) &&//��� ������������ ����� � ������ ���������
		(*(hit + 1) != 3) && (*(hit - 1) != 3) && (*(hit + 12) != 3) && (*(hit - 12) != 3))
	{
		*(hit + 11) = 2;
		*(hit - 11) = 2;
		*(hit + 13) = 2;
		*(hit - 13) = 2;

		*(hit + 1) = 2;
		*(hit - 1) = 2;
		*(hit + 12) = 2;
		*(hit - 12) = 2;
	}
	for (int i = 0, j = 12; i<4; i++)//�������� � ����� ������� ������
	{
		if (&*hit == &*(FourPlay.firstDeckAdress + i) || &*hit == &*(FourPlay.firstDeckAdress + j))//���� ���� ����� �����
			IfPlayerShipDead(FourPlay.firstDeckAdress, FourPlay.position, FourPlay.decks);//��������� ����� ��� ������
		j += 12;
	}
	for (int i = 0, j = 12; i<3; i++)
	{
		if (&*hit == &*(Three1Play.firstDeckAdress + i) || &*hit == &*(Three1Play.firstDeckAdress + j))
			IfPlayerShipDead(Three1Play.firstDeckAdress, Three1Play.position, Three1Play.decks);
		j += 12;
	}
	for (int i = 0, j = 12; i<3; i++)
	{
		if (&*hit == &*(Three2Play.firstDeckAdress + i) || &*hit == &*(Three2Play.firstDeckAdress + j))
			IfPlayerShipDead(Three2Play.firstDeckAdress, Three2Play.position, Three2Play.decks);
		j += 12;
	}
	for (int i = 0, j = 12; i<2; i++)
	{
		if (&*hit == &*(Two1Play.firstDeckAdress + i) || &*hit == &*(Two1Play.firstDeckAdress + j))
			IfPlayerShipDead(Two1Play.firstDeckAdress, Two1Play.position, Two1Play.decks);
		j += 12;
	}
	for (int i = 0, j = 12; i<2; i++)
	{
		if (&*hit == &*(Two2Play.firstDeckAdress + i) || &*hit == &*(Two2Play.firstDeckAdress + j))
			IfPlayerShipDead(Two2Play.firstDeckAdress, Two2Play.position, Two2Play.decks);
		j += 12;
	}
	for (int i = 0, j = 12; i<2; i++)
	{
		if (&*hit == &*(Two3Play.firstDeckAdress + i) || &*hit == &*(Two3Play.firstDeckAdress + j))
			IfPlayerShipDead(Two3Play.firstDeckAdress, Two3Play.position, Two3Play.decks);
		j += 12;
	}
}
// ����� ���� ������� ������������ DrawPlayer � DrawPC
void Battle::IfHittedPCShip(int*hit)//����� ������� � ������� ������
{
	if ((*(hit + 1) != 1) && (*(hit - 1) != 1) && (*(hit + 12) != 1) && (*(hit - 12) != 1) &&
		(*(hit + 1) != 3) && (*(hit - 1) != 3) && (*(hit + 12) != 3) && (*(hit - 12) != 3))
	{
		if (*(hit + 11) != 2) {
			moveAddressPC[indexMovePC] = &*(hit + 11);
			indexMovePC++;
		}
		if (*(hit - 11) != 2) {
			moveAddressPC[indexMovePC] = &*(hit - 11);
			indexMovePC++;
		}
		if (*(hit + 13) != 2) {
			moveAddressPC[indexMovePC] = &*(hit + 13);
			indexMovePC++;
		}
		if (*(hit - 13) != 2) {
			moveAddressPC[indexMovePC] = &*(hit - 13);
			indexMovePC++;
		}
		if (*(hit + 1) != 2) {
			moveAddressPC[indexMovePC] = &*(hit + 1);
			indexMovePC++;
		}
		if (*(hit - 1) != 2) {
			moveAddressPC[indexMovePC] = &*(hit - 1);
			indexMovePC++;
		}
		if (*(hit + 12) != 2) {
			moveAddressPC[indexMovePC] = &*(hit + 12);
			indexMovePC++;
		}
		if (*(hit - 12) != 2) {
			moveAddressPC[indexMovePC] = &*(hit - 12);
			indexMovePC++;
		}
		*(hit + 11) = 2;
		*(hit - 11) = 2;
		*(hit + 13) = 2;
		*(hit - 13) = 2;

		*(hit + 1) = 2;
		*(hit - 1) = 2;
		*(hit + 12) = 2;
		*(hit - 12) = 2;
	}
	for (int i = 0, j = 12; i<4; i++)
	{
		if (&*hit == &*(FourPC.firstDeckAdress + i) || &*hit == &*(FourPC.firstDeckAdress + j))
			IfPCShipDead(FourPC.firstDeckAdress, FourPC.position, FourPC.decks);
		j += 12;
	}
	for (int i = 0, j = 12; i<3; i++)
	{
		if (&*hit == &*(Three1PC.firstDeckAdress + i) || &*hit == &*(Three1PC.firstDeckAdress + j))
			IfPCShipDead(Three1PC.firstDeckAdress, Three1PC.position, Three1PC.decks);
		j += 12;
	}
	for (int i = 0, j = 12; i<3; i++)
	{
		if (&*hit == &*(Three2PC.firstDeckAdress + i) || &*hit == &*(Three2PC.firstDeckAdress + j))
			IfPCShipDead(Three2PC.firstDeckAdress, Three2PC.position, Three2PC.decks);
		j += 12;
	}
	for (int i = 0, j = 12; i<2; i++)
	{
		if (&*hit == &*(Two1PC.firstDeckAdress + i) || &*hit == &*(Two1PC.firstDeckAdress + j))
			IfPCShipDead(Two1PC.firstDeckAdress, Two1PC.position, Two1PC.decks);
		j += 12;
	}
	for (int i = 0, j = 12; i<2; i++)
	{
		if (&*hit == &*(Two2PC.firstDeckAdress + i) || &*hit == &*(Two2PC.firstDeckAdress + j))
			IfPCShipDead(Two2PC.firstDeckAdress, Two2PC.position, Two2PC.decks);
		j += 12;
	}
	for (int i = 0, j = 12; i<2; i++)
	{
		if (&*hit == &*(Two3PC.firstDeckAdress + i) || &*hit == &*(Two3PC.firstDeckAdress + j))
			IfPCShipDead(Two3PC.firstDeckAdress, Two3PC.position, Two3PC.decks);
		j += 12;
	}
}