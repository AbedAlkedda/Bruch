#include <iostream>
#include "Bruch.hpp"

using std::cout;
using std::cin;
using std::endl;

int main() {
  Bruch b(1, 10); // nenner dann zaehler als Eingabe, 10/1 als Erstellung
  Bruch c(4, 2);  // 2/4
  long int a = 0;
  cout << b << endl;

  Bruch test = b + c;

  cout << test << endl;
  return 0;
}
