#include <iostream>
#include "Bruch.hpp"
#include "BruchHelper.hpp"

using std::cout;
using std::cin;
using std::endl;

bool FractionMethods::hasSameDenominator(const long int &lhs_nenner, const long int &rhs_nenner){
  return (lhs_nenner == rhs_nenner ? true : false);
}

bool FractionMethods::isDenominatorsZero(const long int &lhs_nenner, const long int &rhs_nenner){
  bool res = false;
  if (lhs_nenner == 0 || rhs_nenner == 0) { res = true; }
  return res;
}

void FractionMethods::showError(){
  cout << "Dividieren durch 0 ist nicht erlaubt!" << endl;
}

void FractionMethods::addFractions(std::unordered_map<std::string, long int> &args, bool has_same_denominator){
  long int lhs_zaehler = args["lhs_zaehler"],
           rhs_zaehler = args["rhs_zaehler"],
           rhs_nenner  = args["rhs_nenner"];

  if (has_same_denominator){
    args["rhs_zaehler"] = lhs_zaehler + rhs_zaehler;
    args["rhs_nenner"]  = rhs_nenner;
  } else {
    unionFractions(args);
  }
}

void FractionMethods::subtractFractions(std::unordered_map<std::string, long int> &args, bool has_same_denominator){
  long int lhs_zaehler = args["lhs_zaehler"],
           rhs_zaehler = args["rhs_zaehler"],
           rhs_nenner  = args["rhs_nenner"];

  if (has_same_denominator){
    args["rhs_zaehler"] = lhs_zaehler - rhs_zaehler;
    args["rhs_nenner"]  = rhs_nenner;
  } else {
    unionFractions(args);
  }
}

void FractionMethods::unionFractions(std::unordered_map<std::string, long int> &args){
  long int lhs_zaehler = args["lhs_zaehler"],
           lhs_nenner  = args["lhs_nenner"],
           rhs_zaehler = args["rhs_zaehler"],
           rhs_nenner  = args["rhs_nenner"];

  long int kgv = _kgV(lhs_nenner, rhs_nenner);

  if (kgv == lhs_nenner){
    long int multi = kgv / rhs_nenner;
    args["rhs_zaehler"] = multi * rhs_zaehler;
    args["rhs_nenner"]  = kgv;
  } else if (kgv == rhs_nenner){
    long int multi = kgv / lhs_nenner;
    args["lhs_zaehler"] = multi * lhs_zaehler;
    args["lhs_nenner"]  = kgv;
  } else {
    args["lhs_zaehler"] = lhs_zaehler * rhs_nenner;
    args["lhs_nenner"]  = lhs_nenner  * rhs_nenner;
    args["rhs_zaehler"] = rhs_zaehler * lhs_nenner;
    args["rhs_nenner"]  = rhs_nenner  * lhs_nenner;
  }
}

std::unordered_map<std::string, long int> FractionMethods::fractionsArgs(const Bruch &lhs, const Bruch &rhs){
  long int lhs_zaehler = lhs.getNumerator(),
           lhs_nenner  = lhs.getDenominator(),
           rhs_zaehler = rhs.getNumerator(),
           rhs_nenner  = rhs.getDenominator();

  std::unordered_map<std::string, long int> args;
  args["lhs_zaehler"] = lhs_zaehler;
  args["lhs_nenner"]  = lhs_nenner;
  args["rhs_zaehler"] = rhs_zaehler;
  args["rhs_nenner"]  = rhs_nenner;

  return args;
}

std::unordered_map<std::string, bool> FractionMethods::getFractionValidation(const long int &lhs_nenner, const long int &rhs_nenner){
  std::unordered_map<std::string, bool> args;
  args["has_same_denominator"] = hasSameDenominator(lhs_nenner, rhs_nenner);
  args["is_denominators_zero"] = isDenominatorsZero(lhs_nenner, rhs_nenner);

  return args;
}

void FractionOperator::fractionsCollectorRebuild(std::vector<Bruch> &brueche, const Bruch &bruch){
  for (int i = 0; i < 2; i++){
    brueche.pop_back();
  }
  brueche.push_back(bruch);
}

void FractionOperator::callOperatorFractions(){
  std::vector <Bruch> brueche;
  std::vector <long int> bruch_builder;

  char c;
  Bruch bruch;
  bool is_fraction_part = true;

  cout << "Eingabe: ";
  while (cin){
    c = static_cast<char>(cin.get());

    if (c != ' '){
      cin.putback(c);
      c = static_cast<char>(cin.get());

      // Das nächste Zeichen im EingabeArray ist eine Nummer
      if ((c >= '0') && (c <= '9')) {
        long int char_value_as_numeric = c - '0';
        is_fraction_part = true;
        cin.putback(c);
        cin >> bruch;
        bruch_builder.push_back(char_value_as_numeric);

        if (bruch_builder.size() >= 2){
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
        Die if-Anweisung sorgt dafür, die ungeweunschte Zeichen zu ignorieren
      */
      if (isOperator(c) && brueche.size() >= 2){
        unsigned long brueche_count = brueche.size();
        Bruch lhs_bruch,
              rhs_bruch;

        switch (c){
          case '+':
            lhs_bruch = brueche[brueche_count - 2];
            rhs_bruch = brueche[brueche_count - 1];
            bruch     = lhs_bruch + rhs_bruch;

            cout << lhs_bruch << " + " << rhs_bruch << " = " << bruch << endl;

            fractionsCollectorRebuild(brueche, bruch);
            break;

          case '-':
            lhs_bruch = brueche[brueche_count - 2];
            rhs_bruch = brueche[brueche_count - 1];
            bruch     = lhs_bruch - rhs_bruch;

            fractionsCollectorRebuild(brueche, bruch);

            cout << lhs_bruch << " - " << rhs_bruch << " = " << bruch << endl;
            break;

          case '*':
            lhs_bruch = brueche[brueche_count - 2];
            rhs_bruch = brueche[brueche_count - 1];
            bruch     = lhs_bruch * rhs_bruch;

            cout << lhs_bruch << " * " << rhs_bruch << " = " << bruch << endl;

            fractionsCollectorRebuild(brueche, bruch);
            break;

          case '/':
            if (brueche_count >= 2 && !is_fraction_part){
              lhs_bruch = brueche[brueche_count - 2];
              rhs_bruch = brueche[brueche_count - 1];
              bruch     = lhs_bruch / rhs_bruch;

              is_fraction_part = false;

              cout << lhs_bruch << " / " << rhs_bruch << " = " << bruch << endl;

              fractionsCollectorRebuild(brueche, bruch);
            }
            break;
        }
      }

      if (c == 'k'){
        bruch.kuerzeBruch(bruch);
        cout << "gekürzt: " << bruch << endl;
      }

      // Das nächste Zeichen ist Enter-Taste
      if ((c == '\r' || c == '\n') || !hasValidInput(c)){ break; }
    }
  }
}

void FractionOperator::callOperatorFractionLongInt(){
  std::vector <Bruch>    bruch_holder;
  std::vector <long int> bruch_builder;

  char c;
  Bruch bruch;
  long int rhs_input = 0;
  bool is_fraction_part = true;

  cout << "Eingabe: ";
  while (cin){
    c = static_cast<char>(cin.get());
    if (c != ' '){
      cin.putback(c);
      c = static_cast<char>(cin.get());

      if ((c >= '0') && (c <= '9')){
        long int char_value_as_numeric = c - '0';
        if (bruch_holder.size() == 1){
          cin.putback(c);
          cin >> rhs_input;
        } else {
          is_fraction_part = true;
          cin.putback(c);
          cin >> bruch;
          bruch_builder.push_back(char_value_as_numeric);

          if (bruch_builder.size() >= 2){
            Bruch zaehler = bruch_builder[0],
                  nenner  = bruch_builder[1];
            bruch = zaehler / nenner;
            bruch_holder.push_back(bruch);
            is_fraction_part = false;
          }
        }
      }

      if (isOperator(c) && bruch_holder.size()){
        switch (c){
          case '+':
            bruch  = bruch_holder[0] + rhs_input;
            cout << bruch_holder[0] << " + " << rhs_input << " = " << bruch << endl;
            break;

          case '-':
            bruch  = bruch_holder[0] - rhs_input;
            cout << bruch_holder[0] << " - " << rhs_input << " = " << bruch << endl;
            break;

          case '*':
            bruch  = bruch_holder[0] * rhs_input;
            cout << bruch_holder[0] << " * " << rhs_input << " = " << bruch << endl;
            break;

          case '/':
            if (bruch_holder.size() == 1 && !is_fraction_part){
              bruch  = bruch_holder[0] / rhs_input;
              cout << bruch_holder[0] << " / " << rhs_input << " = " << bruch << endl;
            }
            break;
        }
      }

      if (c == 'k'){
        bruch.kuerzeBruch(bruch);
        cout << "gekürzt: " << bruch << endl;
      }

      // Das nächste Zeichen ist Enter-Taste
      if ((c == '\r' || c == '\n') || !hasValidInput(c)){ break; }
    }
  }
}

void FractionOperator::showUsageExample(){
  cout << "\nFür die Eingabe nutzen Sie bitte folgendes:\n\n"
       << "1/2\t  3\t +\n"
       << "^--^\t  ^\t ^\n"
       << "Bruch\t Zahl\t Operator\n" << endl;
}

void FractionOperator::showUsageExampleFractions(){
  cout << "\nBitte nur solche Eingabe nutzen: "
       << "Bruch Bruch Operator\n"
       << "Beispiel: 1/2 3/4 +\n\n"
       << "Nur einstelliger Bruch wird berechnet\n"
       << "Beispiel:     19/2 38/5 +\n"
       << "wird gelesen: 1/2 3/5 +\n"
       << endl;
}

bool FractionOperator::isOperator(const char &c){
  bool is_operator = false;
  if(c == '+' || c == '-' || c == '*' || c == '/') { is_operator = true; }
  return is_operator;
}

bool FractionOperator::hasValidInput(const char &c){
  bool has_vaild_input = false;

  if (isOperator(c) || isdigit(c) || isspace(c)){
    has_vaild_input = true;
  }

  if (c == 'k') { has_vaild_input = true; }

  if (!has_vaild_input){
    printf ("Das Zeichen '%c' ist nicht erlaubt\n", c);
    clearStreambuf();
  }
  return has_vaild_input;
}

void FractionOperator::printExerciseExample(){
  Bruch bruch_zaehler_nenner(1, 10);
  Bruch bruch_zaehler(23);

  cout << "Bruch( 1, 10 ) " << bruch_zaehler_nenner << endl;
  cout << "Bruch( 23 ) " << bruch_zaehler << endl;
}

void FractionOperator::clearStreambuf(){
  cin.clear();
  std::string ignore_line;
  getline(cin, ignore_line);
}

std::string FractionOperator::userInput(){
  std::string user_input;
  cout << "Nochmal? [ja/nein] ";
  cin >> user_input;

  return user_input;
}
