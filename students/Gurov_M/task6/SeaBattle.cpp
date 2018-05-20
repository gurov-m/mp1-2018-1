#define _CRT_SECURE_NO_WARNINGS
#include <iostream> // cin, cout
#include <clocale>  // поддержка русского языка
#include <conio.h>  // _getch()
#include <stdlib.h> // поддержка функции очистки экрана system("cls")
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
	cout << "\nСпасибо за игру :)";
	system("pause");
}

