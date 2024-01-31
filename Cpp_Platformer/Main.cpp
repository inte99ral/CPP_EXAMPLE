#include "GameManager.hpp"

using namespace std;

int main()
{

  awake();

  while (1)
  {
    if (!update())
      return 1;
  }

  return 0;
}