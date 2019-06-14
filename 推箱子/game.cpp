
#include "Windows.h"
#include "game.h"
#include "ctime"
#include "conio.h"
using namespace std;

int game::WaitKey(double sec)
{
	clock_t tickStart = clock();
	clock_t tickEnd = tickStart + (clock_t)(sec * CLOCKS_PER_SEC);
	while (!kbhit())
	{
		// time out
		if (clock() >= tickEnd)
			return 0;
		Sleep(sec / 100.0); // wait
	}
	return getch();
}


void game::SetPos(int x, int y)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cursorPos = { x, y };
	SetConsoleCursorPosition(hConsole, cursorPos);
}
