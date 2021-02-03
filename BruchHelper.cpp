#include <iostream>
#include "BruchHelper.hpp"

bool hasSameDenominator(const long int &lhs_denominator, const long int &rhs_denominator){
  std::cout << lhs_denominator << " " << rhs_denominator << std::endl;  
  return true;
}

bool isNumeratorZero(const long int &numerator){
  return (numerator == 0 ? true : false);
}

bool isDenominatorZero(const long int &denominator){
  return (denominator == 0 ? true : false);
}
