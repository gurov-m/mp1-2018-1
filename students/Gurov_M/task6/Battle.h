#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<windows.h>
#include<conio.h>
#include<clocale>
#include<stdlib.h>
#include<ctime>
#include<iomanip>
#include<cmath>
#include<stdio.h>
using namespace std;
struct Ship
{
	int *firstDeckAdress;//адрес первой палубы
	int position;//положение кораб.
	int decks;//количество палуб
};
class Battle
{
protected:
	Ship FourPC, Three1PC, Three2PC, Two1PC, Two2PC, Two3PC, FourPlay, Three1Play, Three2Play, Two1Play, Two2Play, Two3Play;
	int playerInd = 0; // индекс адресов кор. пользователя
	int pcInd = 0; // индекс адресов кор. компьютера
	int indexMovePC = 0; // индекс ходов компьютера
	int decks = 4;
	int hit = 0;
	int hitsCount = 0;
	int number = 1;
	int flag = 0;
	int errors = 0;
	int firstMove = 0;
	int countPlayer = 0;
	int countPC = 0;
	const int Rows = 12, Cols = 12;
	int *playerShipAddress[144]; // адреса кораблей пользователя
	int *pcShipAddress[144]; // адреса кораблей компьютера
	int *moveAddressPC[144]; // адреса ходов компьютера
	int playerField[12][12] = { 0 };
	int compField[12][12] = { 0 };
public:
	int IfWin();
	int IfPCMoveRepeat(int *moves);
	void IfPlayerShipDead(int *firstdeck, int position, int decks);
	void IfPCShipDead(int *firstdeck, int position, int decks);
	void IfHittedPlayerShip(int*hit);
	void IfHittedPCShip(int*hit);
	void EncircleDeadPCShip(int *firstdeck, int position, int decks);
	void EncircleDeadPlayerShip(int *firstdeck, int position, int decks);
	void SetAddress(int *deckAdress, int decks, int position);
	int SearchAddress(int *deckAdress, int decks, int random);
	int Translation(char symbol);
	void SetPCAddress(int *deckAdress, int decks, int random);
	int SearchPCAddress(int *deckAdress, int decks, int random);
};


