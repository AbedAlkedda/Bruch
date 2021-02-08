#include <iostream>
#include <unordered_map>
#include <array>
#include "Bruch.hpp"
#include <vector>

namespace FractionMethods {
  void showError();
  void unionFractions(std::unordered_map<std::string, long int> &args);
  bool hasSameDenominator(const long int &lhs_nenner, const long int &rhs_nenner);
  bool isDenominatorsZero(const long int &lhs_nenner, const long int &rhs_nenner);
  std::unordered_map<std::string, long int> fractionsArgs(const Bruch &lhs, const Bruch &rhs);
  void addFractions(std::unordered_map<std::string, long int> &args, bool has_same_denominator);
  void divideFractions(std::unordered_map<std::string, long int> &args, bool has_same_denominator);
  std::unordered_map<std::string, bool> getFractionValidation(const long int &lhs_nenner, const long int &rhs_nenner);
  long int _ggT(long int nenner, long int zaehler);
  long int _kgV(long int nenner, long int zaehler);
}

namespace FractionOperator {
  void fractionsCollectorRebuild(std::vector<Bruch> &brueche, const Bruch &bruch);
}
