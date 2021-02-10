#include <array>
#include <vector>
#include <iostream>
#include <unordered_map>
#include "Bruch.hpp"

namespace FractionMethods {
  // Zeigt eine Fehlermeldung für den Fall, dass das Ergibnes x/0 ist oder falls der Nutzer x/0 eingibt
  void showError();

  // größter gemeinsamer Teiler berecnhnen
  long int _ggT(long int nenner, long int zaehler);

  // kleinstes gemeinsames Vielfaches berecnhnen
  long int _kgV(long int nenner, long int zaehler);

  // vereinigt Nenner
  void unionFractions(std::unordered_map<std::string, long int> &args);

  // überprüft, ob die Nenner gleich sind
  bool hasSameDenominator(const long int &lhs_nenner, const long int &rhs_nenner);

  // überprüft, ob die Nenner Null sind
  bool isDenominatorsZero(const long int &lhs_nenner, const long int &rhs_nenner);

  // fasst die Argumente (Nenner und Zähler) von der Brüchern zusammen.
  // Damit kein Kode sich wiederholt (DRY-Prinzip 'Dont Repeat Yourself')
  std::unordered_map<std::string, long int> fractionsArgs(const Bruch &lhs, const Bruch &rhs);

  // Eine Hilf-Metode für Bruch operator +
  void addFractions(std::unordered_map<std::string, long int> &args, bool has_same_denominator);

  // Eine Hilf-Metode für Bruch operator -
  void subtractFractions(std::unordered_map<std::string, long int> &args, bool has_same_denominator);

  // Eine Hilf-Metode für Bruch operator + - * und /, die überprüft, ob ie Nenner gleich sind oder Null sind
  std::unordered_map<std::string, bool> getFractionValidation(const long int &lhs_nenner, const long int &rhs_nenner);
}

namespace FractionOperator {
  // Zeigt ein Beispiel für den Operator zwichen einem Bruch und einem Objekt vom
  // Typ long int
  void showUsageExample();

  // zeigt das Eingabefled für die Operation zwischen zwei Brüchern
  void callOperatorFractions();

  // zeigt das Eingabefled für die Operation zwischen einem Bruch und einem Objekt vom
  // Typ long int
  void callOperatorFractionLongInt();

  // löscht die letzten Brüche aus dem vektor und fügt das neue Ergnis hinzu
  void fractionsCollectorRebuild(std::vector<Bruch> &brueche, const Bruch &bruch);
}
