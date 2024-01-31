#include "GameManager.hpp"

#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)
#define KEY_UP(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 0 : 1)

const char *SYSTEM_SETTING = "mode con: cols=100 lines=100 | title Cpp-Platformer v0.1";

int characterY = 0;
int characterX = 0;

int getKeyDown()
{
  if (_kbhit() == 0)
    return 0; // 입력감지

  if (KEY_DOWN(VK_LEFT))
  {
    if (characterX > 0)
      characterX--;
  }
  if (KEY_DOWN(VK_RIGHT))
  {
    if (characterX < 10)
      characterX++;
  }
  if (KEY_DOWN(VK_UP))
  {
    if (characterY > 0)
      characterY--;
  }
  if (KEY_DOWN(VK_DOWN))
  {
    if (characterY < 10)
      characterY++;
  }

  return _getch();
}

void setCursor()
{
  CONSOLE_CURSOR_INFO cursorInfo = {
      0,
  };
  cursorInfo.dwSize = 1;       // 커서 굵기 (1 ~ 100)
  cursorInfo.bVisible = false; // 커서 Visible TRUE(보임) FALSE(숨김)
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void setCursorPos(int Y, int X)
{
  COORD Pos;
  Pos.Y = Y;
  Pos.X = X;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void displayCharacter()
{
  // setCursorPos(characterY, characterX);
  // std::cout << "[Y : " << characterY << "] [X : " << characterX << "]" << std::endl;
}

void setDisplay()
{
  system("cls");
  setCursorPos(characterY, characterX);
  printf("┌    X:%02d ┐", characterX);
  setCursorPos(characterY + 2, characterX);
  printf("     +    Y:%02d", characterY);
  setCursorPos(characterY + 4, characterX);
  printf("└         ┘");
}

void awake()
{
  system(SYSTEM_SETTING); // 콘솔창 크기 및 제목 설정
  // setCursor();
  setDisplay();
}

int update()
{
  int input = getKeyDown();
  if (input == 0)
    return 1;
  if (input == VK_ESCAPE)
    return 0;
  // if(input == VK_SPACE) setDisplay();
  setDisplay();
  // else std::cout << input << std::endl;

  return 1;
}