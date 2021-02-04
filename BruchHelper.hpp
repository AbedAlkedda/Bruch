#include <iostream>
#include <unordered_map>
#include <array>
#include "Bruch.hpp"
namespace FractionMethods {
  void showError();
  void multiplyFractions(std::unordered_map<std::string, long int> &args);
  bool hasSameDenominator(const long int &lhs_nenner, const long int &rhs_nenner);
  bool isDenominatorsZero(const long int &lhs_nenner, const long int &rhs_nenner);
  std::unordered_map<std::string, long int> fractionsArgs(const Bruch &lhs, const Bruch &rhs);
  void addFractions(std::unordered_map<std::string, long int> &args, bool has_same_denominator);
  void divideFractions(std::unordered_map<std::string, long int> &args, bool has_same_denominator);
  std::unordered_map<std::string, bool> getBruchValidation(const long int &lhs_nenner, const long int &rhs_nenner);
}
