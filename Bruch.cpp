#include <iostream>
#include "Bruch.hpp"
#include "BruchHelper.hpp"

using namespace FractionMethods;

// Konstruktor und Destruktor
Bruch::Bruch(long int nenner_lhs, long int zaehler_rhs){
  _nenner  = nenner_lhs;
  _zaehler = zaehler_rhs;
 }

Bruch::Bruch(long int z){
  _nenner  = 1;
  _zaehler = z;
 }

Bruch::Bruch(){
  _nenner  = 1;
  _zaehler = 1;
 }

// Getter und Setter
long int Bruch::getNumerator() const {
  return _zaehler;
}

long int Bruch::getDenominator() const {
  return _nenner;
}

void Bruch::setBruch(long int nenner, long int zaehler){
  _nenner = nenner;
  _zaehler = zaehler;
}

// Operatoren zwischen zwei Objekten vom Typ Bruch
Bruch operator+ (const Bruch &lhs, const Bruch &rhs){
	long int lhs_zaehler,
           lhs_nenner,
           rhs_zaehler,
           rhs_nenner;

  std::unordered_map<std::string, long int> args = FractionMethods::fractionsArgs(lhs, rhs);

  std::unordered_map<std::string, bool> bruch_validation = FractionMethods::getBruchValidation(args["lhs_nenner"], args["rhs_nenner"]);

  Bruch result;
  if (bruch_validation["is_denominators_zero"]){
    FractionMethods::showError();

    result.setBruch(0, 0);
  } else if (bruch_validation["has_same_denominator"]){
    FractionMethods::addFractions(args, bruch_validation["has_same_denominator"]);
    rhs_zaehler = args["rhs_zaehler"];
    rhs_nenner  = args["rhs_nenner"];

    result.setBruch(rhs_zaehler, rhs_nenner);
  } else {
    FractionMethods::addFractions(args, bruch_validation["has_same_denominator"]);
    lhs_zaehler = args["lhs_zaehler"];
    lhs_nenner  = args["lhs_nenner"];
    rhs_zaehler = args["rhs_zaehler"];

    result.setBruch(lhs_nenner, lhs_zaehler + rhs_zaehler);
	}

  return result;
}

Bruch operator- (const Bruch &lhs, const Bruch &rhs){
  long int lhs_zaehler,
           lhs_nenner,
           rhs_zaehler,
           rhs_nenner;

  std::unordered_map<std::string, long int> args = FractionMethods::fractionsArgs(lhs, rhs);

  std::unordered_map<std::string, bool> bruch_validation = FractionMethods::getBruchValidation(args["lhs_nenner"], args["rhs_nenner"]);
	
  Bruch result;
  if (bruch_validation["is_denominators_zero"]){
    FractionMethods::showError();

    result.setBruch(0, 0);
  } else if (bruch_validation["has_same_denominator"]){
    FractionMethods::divideFractions(args, bruch_validation["has_same_denominator"]);
    rhs_zaehler = args["rhs_zaehler"];
    rhs_nenner  = args["rhs_nenner"];

    result.setBruch(rhs_zaehler, rhs_nenner);
  } else {
    FractionMethods::divideFractions(args, bruch_validation["has_same_denominator"]);
    lhs_zaehler = args["lhs_zaehler"];
    lhs_nenner  = args["lhs_nenner"];
    rhs_zaehler = args["rhs_zaehler"];

    result.setBruch(lhs_nenner, lhs_zaehler - rhs_zaehler);
  }

  return result;
}

Bruch operator* (const Bruch &lhs, const Bruch &rhs){
  Bruch result;
  result.setBruch(lhs.getDenominator()  * rhs.getDenominator(),
                  lhs.getNumerator() * rhs.getNumerator());
  return result;
}

Bruch operator/ (const Bruch &lhs, const Bruch &rhs){
  Bruch result;
  result.setBruch(lhs.getNumerator() * rhs.getDenominator(),
	                lhs.getDenominator()  * rhs.getNumerator());
  return result;
}

std::ostream& operator<< (std::ostream &output, const Bruch &bruch){
  output << bruch.getNumerator() << '/' << bruch.getDenominator();
  return output;
}
