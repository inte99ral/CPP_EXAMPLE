#include <iostream>

using namespace std;

class student {
 private:
  char* name;
  int age;
  char* hobby;

 public:
  void ShowInfo();
  void SetInfo(char* _name, int _age, char* _hobby);
  void Study();
  void Sleep();
};

int arr[] = {1, 2, 3};