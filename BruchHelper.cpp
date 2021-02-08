#include <iostream>
#include "BruchHelper.hpp"
#include "Bruch.hpp"

bool FractionMethods::hasSameDenominator(const long int &lhs_nenner, const long int &rhs_nenner){
  return (lhs_nenner == rhs_nenner ? true : false);
}

bool FractionMethods::isDenominatorsZero(const long int &lhs_nenner, const long int &rhs_nenner){
  bool res = false;
  if (lhs_nenner == 0 || rhs_nenner == 0) { res = true; }
  return res;
}

void FractionMethods::showError(){
  std::cout << "Dividieren durch 0 ist nicht erlaubt!" << std::endl;
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

void FractionMethods::divideFractions(std::unordered_map<std::string, long int> &args, bool has_same_denominator){
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
