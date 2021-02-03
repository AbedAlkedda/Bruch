#include <iostream>
#include <unordered_map>
#include <array>
#include "Bruch.hpp"

void showError();
void multiply_Fractions(std::unordered_map<std::string, long int> &args);
bool hasSameDenominator(const long int &lhs_nenner, const long int &rhs_nenner);
bool isDenominatorsZero(const long int &lhs_nenner, const long int &rhs_nenner);
std::unordered_map<std::string, long int> BruchArgs(const Bruch &lhs, const Bruch &rhs);
std::unordered_map<std::string, long int> BruchArgs(const Bruch &lhs, const std::array<long int, 2> &rhs);
void add_Fractions(std::unordered_map<std::string, long int> &args, bool has_same_denominator);
void divide_Fractions(std::unordered_map<std::string, long int> &args, bool has_same_denominator);
std::unordered_map<std::string, bool> getBruchValidation(const long int &lhs_nenner, const long int &rhs_nenner);
