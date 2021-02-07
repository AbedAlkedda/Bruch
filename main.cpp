#include <iostream>
#include "Bruch.hpp"
#include "BruchHelper.hpp"
#include <vector>

using std::cout;
using std::cin;
using std::endl;

using namespace FractionOperator;

int main() {
  std::vector <Bruch>    brueche;
  std::vector <long int> bruch_builder;

  Bruch bruch;
  char c;
  bool is_fraction_part;
  cout << " Eingabe: ";
  while (std::cin){
    c = static_cast<char>(cin.get());

    // Das nächste Zeichen im Eingabearray ist eine Nummer
    if ((c >= '0') && (c <= '9')) {
      long int char_value_as_nummeric = c - '0';
      is_fraction_part = true;
      cin.putback(c);
      cin >> bruch;
      bruch_builder.push_back(char_value_as_nummeric);

      if(bruch_builder.size() >= 2){
        Bruch zaehler = bruch_builder[0],
              nenner  = bruch_builder[1];
        bruch = zaehler / nenner;
        brueche.push_back(bruch);
        bruch_builder.clear();
        is_fraction_part = false;
      }
    }

    /*
      Das nächste Zeichen im Eingabearray ist ein Operator und der Switch
      ist nur für den Operator zwischen zwei Objekten der Klasse Bruch
    */
    else
    {
      unsigned long brueche_count = brueche.size();
      Bruch lhs_bruch,
            rhs_bruch;

      switch (c){
        case '+':
          lhs_bruch = brueche[brueche_count - 2];
          rhs_bruch = brueche[brueche_count - 1];
          bruch     = lhs_bruch + rhs_bruch;

          fractionsCollectorRebuild(brueche, bruch);
          cout << "bruch: " << bruch;
          break;

        case '-':
          lhs_bruch = brueche[brueche_count - 2];
          rhs_bruch = brueche[brueche_count - 1];
          bruch     = lhs_bruch - rhs_bruch;

          fractionsCollectorRebuild(brueche, bruch);
          cout << "bruch: " << bruch;
          break;

        case '*':
          lhs_bruch = brueche[brueche_count - 2];
          rhs_bruch = brueche[brueche_count - 1];
          bruch     = lhs_bruch * rhs_bruch;

          fractionsCollectorRebuild(brueche, bruch);
          cout << "bruch: " << bruch;
          break;

        case '/':
          if(brueche_count >= 2 && !is_fraction_part){
            lhs_bruch = brueche[brueche_count - 2];
            rhs_bruch = brueche[brueche_count - 1];
            bruch     = lhs_bruch / rhs_bruch;
            is_fraction_part = false;
            fractionsCollectorRebuild(brueche, bruch);
            cout << "bruch: " << bruch;
          }
          break;

        default:
          cout << "Invaild Input!" << bruch;
          break;
      }
    }

    if(c == 'k'){
      bruch.kuerzeBruch(bruch);
      cout << bruch;
    }

    // Das nächste Zeichen ist Enter-Taste
    if(c == '\r' || c == '\n'){ break; }
  }

  return 0;
}
