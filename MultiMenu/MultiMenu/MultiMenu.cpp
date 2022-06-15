#include <iostream> 

#include <Windows.h>	// Fro 'speep()', for coloring cmd and graphic and etc...
#include <conio.h>	// I dont know for what it was created but I use only '_getch()' from it )

#include <string>
#include <vector>

using namespace std;

HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

void Gotoxy(short x, short y)
{
	SetConsoleCursorPosition(hStdOut, { x,y });
}

// Disappear the cursor
void ConsoleCursorVisible(bool show)
{
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(hStdOut, &structCursorInfo);
	structCursorInfo.bVisible = show;
	SetConsoleCursorInfo(hStdOut, &structCursorInfo);
}

//========== MAIN =============

int main()
{
	// Starting arguments
	SetConsoleTitle(L"LOL");
	ConsoleCursorVisible(false);
	//setlocale(LC_ALL, "ru");

	// Const values
	const char ESC = 27;
	const char UP = 72;
	const char DOWN = 80;
	const char ENTER = 13;

	//const int menuSIZE = 4;
	string menu[] = { "New game   ", "Load   ", "Settings    ", "Exit    "};
	int activeMenu = 0;

	int x = 50, y = 13;
	Gotoxy(x, y);
	cout << "Welcome !";

	char ch;

	// Do this while it true
	int beingDo = true;
	while (beingDo)
	{
		// Start position
		system("cls");
		x = 50; y = 13;
		Gotoxy(x, y);

		// Print menu
		for (int i = 0; i < size(menu); i++)
		{
			// Color active string
			if (i == activeMenu) SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
			else SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);

			Gotoxy(x, y++);
			cout << menu[i] << endl;
		}

		// Listening buttons
		ch = _getch();
		if (ch == -32) ch = _getch();		// If button is one of four shoters take more

		switch (ch)
		{
		case ESC:
			beingDo = false;
			break;

		case UP:
			if (activeMenu > 0)
				activeMenu--;
			break;

		case DOWN:
			if (activeMenu < size(menu)-1)
				activeMenu++;
			break;

		case ENTER:
			system("cls");
			if (activeMenu == 3)
			{
				beingDo = false;
			}
			else
			{
				Gotoxy(50, 13);
				SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
				cout << "User choose " << menu[activeMenu] << endl;
				_getch();
			}

			break;

		default:
			cout << "Code " << (int)ch << "   ";		// Space needed order to clear old numbers
			break;
		}



	}


	return 0;
}
