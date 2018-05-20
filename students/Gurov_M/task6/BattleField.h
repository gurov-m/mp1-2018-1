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
#include "Battle.h"
using namespace std;
class BattleField : Battle
{
private:
public:
	void PCNEW();
	void DrawPlayer();
	void DrawComp();
	void Move();
	void PCMove();
	void PlayerMove();
	void SetPCShips(int pal, int colum);
	void SetFloat(int decks, int number);
	void ManualFloatSetting(int decks, int number);
	void AutomaticFloatSetting(int decks, int number);
};