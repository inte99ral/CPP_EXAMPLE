#include <conio.h>
#include <iostream>
#include <stdlib.h> // * NEEDED
#include <Windows.h>

using namespace std;

void setCursorPos(int Y, int X) {
  COORD Pos;
  Pos.Y = Y;
  Pos.X = X;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int main() {
	system("cls"); // * WINDOW SHELL CLEAR
	system("color B4");

	while(1) {

	}

	return 0;
}