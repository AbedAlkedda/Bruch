#include <iostream>
#include "Bruch.hpp"
#include <vector>
#include <typeinfo>

using std::cout;
using std::cin;
using std::endl;

int main() {
  std::vector <Bruch>    brueche;
  std::vector <long int> bruch_builder;

  Bruch bruch;
  char c;

  cout << " Eingabe: ";
  while (std::cin){
    c = static_cast<char>(cin.get());

    // Das nächste Zeichen im Eingabearray ist eine Nummer
    if ((c >= '0') && (c <= '9')) {
      long int char_value_as_nummeric = c - '0';
      cin.putback(c);

      cin >> bruch;
      bruch_builder.push_back(char_value_as_nummeric);

      if(bruch_builder.size() >= 2){
        Bruch zaehler = bruch_builder[0],
              nenner  = bruch_builder[1];
        bruch = zaehler / nenner;
        cout << "Yo, your fraction is: " << bruch << endl;
        brueche.push_back(bruch);
        bruch_builder.clear();
      }

      cout << bruch;
    }

    /*
      Das nächste Zeichen im Eingabearray ist ein Operator und der Switch
      ist nur für den Operator zwischen zwei Objekten der Klasse Bruch
    */
    else
    {
      switch (c){
        case '+':
          break;

        case '-':
          break;

        case '*':
          break;

        case '/':
          break;

        default:
          break;
      }
    }

    // Das nächste Zeichen ist Enter-Taste
    if(c == '\r' || c == '\n'){
      break;
    }
  }

  return 0;
}
