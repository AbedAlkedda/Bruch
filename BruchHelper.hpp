#include <array>
#include <vector>
#include <iostream>
#include <unordered_map>
#include "Bruch.hpp"

/*
  Alle Methoden hier sind keine Membermethoden der Klasse Bruch.
  Die Idee ist eine Sammlung von Methoden, die dabei helfen, Brüche zu überprüfen und zu berechnen
*/
namespace FractionMethods {
  // Zeigt eine Fehlermeldung für den Fall, dass das Ergebnis x/0 ist oder falls der Nutzer x/0 eingibt
  void showError();

  // @Params: Nenner und Zähler eines Bruches und @return Wert ist der größten gemeinsamen Teiler
  long int _ggT(long int nenner, long int zaehler);

  // @Params: Nenner und Zähler eines Bruches und @return Wert ist das kleinste gemeinsame Vielfache
  long int _kgV(long int nenner, long int zaehler);

  // vereinigt Nenner
  // @Params: ein Hash-Map. dessen key vom Datentyp string und dessen Value ist der Nenner und Zähler
  // von zwei Brüchen
  void unionFractions(std::unordered_map<std::string, long int> &args);

  // überprüft, ob die Nenner gleich sind
  // @Params zwei long int und @return das Vergleichergebnis
  bool hasSameDenominator(const long int &lhs_nenner, const long int &rhs_nenner);

  // überprüft, ob die Nenner Null sind
  // @Params zwei long int und @return das Vergleichergebnis
  bool isDenominatorsZero(const long int &lhs_nenner, const long int &rhs_nenner);

  // fasst die Argumente (Nenner und Zähler) von den Brüchen zusammen.
  // Damit kein Code sich wiederholt (DRY-Prinzip 'Dont Repeat Yourself')
  // @Params sind zwei Brüche und @return Wert ist ein Hash-Map, dessen Key vom Typ string ist und
  // dessen Value die Nenner und Zähler von zwei Brüchen und zwar vom Typ long int
  std::unordered_map<std::string, long int> fractionsArgs(const Bruch &lhs, const Bruch &rhs);

  // Eine Hilfs-Methode für Bruch operator +
  // @Params: Hash-Map, dessen Key vom Typ string und dessen Value ist die Nenner und Zähler von zwei Brüchen
  // und zwar vom Typ long int. Als Params nimmt diese Methode den Wert von der Methode hasSameDenominator
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

  // Zeigt ein Beispiel für den Operator zwischen zwei Brüchen
  void showUsageExampleFractions();

  // zeigt das Eingabefeld für die Operation zwischen zwei Brüchen
  void callOperatorFractions();

  // zeigt das Eingabefeld für die Operation zwischen einem Bruch und einem Objekt vom
  // Typ long int
  void callOperatorFractionLongInt();

  // löscht die letzten Brüche aus dem Vektor und fügt das neue Ergebnis hinzu
  // @Params ein vector und ein Bruch
  void fractionsCollectorRebuild(std::vector<Bruch> &brueche, const Bruch &bruch);

  // überprüft, ob das nächste Zeichen ein Operator ist
  // @Params Das Zeichen von Typ Char und @return bool true, falls das Zeichen Operator ist sonst false
  bool isOperator(const char &c);

  // überprüft die Eingabe,die vom streambuf eingelesen ist.
  // @Params Das Zeichen von Typ Char und @return bool true, falls das Zeichen Zahl ist sonst false
  bool hasValidInput(const char &c);

  //@return ist die Nutzereingabe, damit wird gefragt, ob der Nutzer nochmal rechnen will
  std::string userInput();
  
  // Loescht, was in Streambuf gibt fuer neue Eingabe
  void clearStreambuf();

  // zeigt ein Beispiel
  void printExerciseExample();
}
