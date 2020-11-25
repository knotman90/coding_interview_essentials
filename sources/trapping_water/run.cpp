#include <cassert>
#include <iostream>
using namespace std;

int main()
{
  cout << "Do you want to go for a run?(Y/N)" << endl;

  char a;
  cin >> a;

  int c = 100;
  if (a == 'Y' || a == 'y')
    while (c--)
      cout << "pfffffff, ok....... at 4.30" << endl;
  else
    while (c--)
      cout << "ok, good idea, but it is not my fault if you will be more berta"
           << endl;
  return 0;
}