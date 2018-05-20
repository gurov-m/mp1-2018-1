#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <clocale>  
#include <conio.h>  
#include <stdlib.h> 
#include <time.h>
#include "BattleField.h"
using namespace std;
int main()
{
	int _decks = 4;
	int _number = 1;
	BattleField Fields;
	srand((unsigned)time(NULL));
	setlocale( LC_ALL, "rus" );
	Fields.DrawPlayer();
	Fields.DrawComp();
	Fields.SetFloat(_decks , _number);
	Fields.Move();
	cout << "\nСпасибо за игру :)"<< endl;
	system("pause");
}

