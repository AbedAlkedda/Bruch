#include <iostream>
#include "Bruch.hpp"
#include "BruchHelper.hpp"
#include <typeinfo>
#include <istream>

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

void Bruch::_setBruch(long int nenner, long int zaehler){
  _nenner = nenner;
  _zaehler = zaehler;
}

// Operatoren
Bruch operator+ (const Bruch &lhs, const Bruch &rhs){
  std::unordered_map<std::string, long int> args         = FractionMethods::fractionsArgs(lhs, rhs);
  std::unordered_map<std::string, bool> bruch_validation = FractionMethods::getBruchValidation(args["lhs_nenner"], args["rhs_nenner"]);

  long int rhs_zaehler,
           rhs_nenner;

  bool is_denominators_zero = bruch_validation["is_denominators_zero"],
       has_same_denominator = bruch_validation["has_same_denominator"];

  Bruch result;
  if (is_denominators_zero){
    FractionMethods::showError();

    result._setBruch(0, 0);
  } else if (has_same_denominator){
    FractionMethods::addFractions(args, has_same_denominator);
    rhs_zaehler = args["rhs_zaehler"];
    rhs_nenner  = args["rhs_nenner"];

    result._setBruch(rhs_zaehler, rhs_nenner);
  } else {
    FractionMethods::addFractions(args, bruch_validation["has_same_denominator"]);
    long int lhs_zaehler = args["lhs_zaehler"],
             lhs_nenner  = args["lhs_nenner"];

    rhs_zaehler  = args["rhs_zaehler"];
    lhs_zaehler += rhs_zaehler;

    result._setBruch(lhs_nenner, lhs_zaehler);
	}

  return result;
}

Bruch operator- (const Bruch &lhs, const Bruch &rhs){
  std::unordered_map<std::string, long int> args         = FractionMethods::fractionsArgs(lhs, rhs);
  std::unordered_map<std::string, bool> bruch_validation = FractionMethods::getBruchValidation(args["lhs_nenner"], args["rhs_nenner"]);

  long int rhs_zaehler,
           rhs_nenner;

  bool is_denominators_zero = bruch_validation["is_denominators_zero"],
       has_same_denominator = bruch_validation["has_same_denominator"];

  Bruch result;

  if (is_denominators_zero){
    FractionMethods::showError();

    result._setBruch(0, 0);
  } else if (has_same_denominator){
    FractionMethods::divideFractions(args, has_same_denominator);
    rhs_zaehler = args["rhs_zaehler"];
    rhs_nenner  = args["rhs_nenner"];

    result._setBruch(rhs_zaehler, rhs_nenner);
  } else {
    FractionMethods::divideFractions(args, has_same_denominator);
    long int lhs_zaehler = args["lhs_zaehler"],
             lhs_nenner  = args["lhs_nenner"];

    rhs_zaehler  = args["rhs_zaehler"];
    lhs_zaehler -= rhs_zaehler;

    result._setBruch(lhs_nenner, lhs_zaehler);
  }

  return result;
}

Bruch operator* (const Bruch &lhs, const Bruch &rhs){
  std::unordered_map<std::string, long int> args = FractionMethods::fractionsArgs(lhs, rhs);

  long int lhs_nenner = args["lhs_nenner"],
           rhs_nenner = args["rhs_nenner"];

  Bruch result;

  if(lhs_nenner == 0 || rhs_nenner == 0){
    showError();
    result._setBruch(0, 0);
  } else {
    long int lhs_zaehler = args["lhs_zaehler"],
             rhs_zaehler = args["rhs_zaehler"];
    
    lhs_nenner  *= rhs_nenner;
    lhs_zaehler *= rhs_zaehler;
    
    result._setBruch(lhs_nenner, lhs_zaehler);
  }
  return result;
}

Bruch operator/ (const Bruch &lhs, const Bruch &rhs){
  std::unordered_map<std::string, long int> args = FractionMethods::fractionsArgs(lhs, rhs);

  long int lhs_nenner = args["lhs_nenner"],
           rhs_nenner = args["rhs_nenner"];

  Bruch result;

  if(lhs_nenner == 0 || rhs_nenner == 0){
    showError();
    result._setBruch(0, 0);
  } else {
    long int lhs_zaehler = args["lhs_zaehler"],
             rhs_zaehler = args["rhs_zaehler"];
    
    lhs_nenner  *= rhs_zaehler;
    lhs_zaehler *= rhs_nenner;

    result._setBruch(lhs_nenner, lhs_zaehler);
  }
  return result;
}

std::ostream& operator<< (std::ostream &output, const Bruch &bruch){
  output << bruch.getNumerator() << '/' << bruch.getDenominator() << std::endl;
  return output;
}

std::istream& operator>> (std::istream &input, Bruch &bruch){
  input >> bruch._zaehler;
  return input;
}

Bruch Bruch::kuerzeBruch(Bruch &bruch){
  long int nenner  = bruch.getDenominator(),
           zaehler = bruch.getNumerator();

  long int ggt = _ggT(nenner, zaehler);

  nenner  /= ggt;
  zaehler /= ggt;

  bruch._setBruch(nenner, zaehler);
  return bruch;
}

long int Bruch::_ggT(long int nenner, long int zaehler) {
  if (nenner == 0 || zaehler == 0){
    return 0;
  } else if (nenner == zaehler){
    return nenner;
  } else if (nenner > zaehler){
    return _ggT(nenner - zaehler, zaehler);
  } else {
    return _ggT(nenner, zaehler - nenner);
  }
}
