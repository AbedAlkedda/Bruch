#include <array>
#include <vector>
#include <iostream>
#include <unordered_map>
#include "Bruch.hpp"

namespace FractionMethods {
  // Zeigt eine Fehlermeldung für den Fall, dass das Ergebnis x/0 ist oder falls der Nutzer x/0 eingibt
  void showError();

  // größten gemeinsamen Teiler berechnen
  long int _ggT(long int nenner, long int zaehler);

  // kleinstes gemeinsames Vielfaches berechnen
  long int _kgV(long int nenner, long int zaehler);

  // vereinigt Nenner
  void unionFractions(std::unordered_map<std::string, long int> &args);

  // überprüft, ob die Nenner gleich sind
  bool hasSameDenominator(const long int &lhs_nenner, const long int &rhs_nenner);

  // überprüft, ob die Nenner Null sind
  bool isDenominatorsZero(const long int &lhs_nenner, const long int &rhs_nenner);

  // fasst die Argumente (Nenner und Zähler) von der Brüchen zusammen.
  // Damit kein Code sich wiederholt (DRY-Prinzip 'Dont Repeat Yourself')
  std::unordered_map<std::string, long int> fractionsArgs(const Bruch &lhs, const Bruch &rhs);

  // Eine Hilfs-Methode für Bruch operator +
  void addFractions(std::unordered_map<std::string, long int> &args, bool has_same_denominator);

  // Eine Hilfs-Methode für Bruch operator -
  void subtractFractions(std::unordered_map<std::string, long int> &args, bool has_same_denominator);

  // Eine Hilfs-Methode für Bruch operator + - * und /, die überprüft, ob die Nenner gleich sind oder Null sind
  std::unordered_map<std::string, bool> getFractionValidation(const long int &lhs_nenner, const long int &rhs_nenner);
}

namespace FractionOperator {
  // Zeigt ein Beispiel für den Operator zwischen einem Bruch und einem Objekt vom
  // Typ long int
  void showUsageExample();

  // Zeigt ein Beispiel für den Operator zwischen zwei Brüche
  void showUsageExampleFractions();

  // zeigt das Eingabefeld für die Operation zwischen zwei Brüchen
  void callOperatorFractions();

  // zeigt das Eingabefeld für die Operation zwischen einem Bruch und einem Objekt vom
  // Typ long int
  void callOperatorFractionLongInt();

  // löscht die letzten Brüche aus dem Vektor und fügt das neue Ergebnis hinzu
  void fractionsCollectorRebuild(std::vector<Bruch> &brueche, const Bruch &bruch);

  // überprüft, ob das nächste Zeichen ein Operator ist
  bool isOperator(const char &c);

  // überprüft die Eingabe
  bool hasValidInput(const char &c);

  // wiederholt das Programm
  void tryAgain(std::string &user_input);
}
