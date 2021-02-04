#include <array>
#include <unordered_map>
#include <iostream>

#ifndef BRUCH_H
#define BRUCH_H

class Bruch {

  public:

    Bruch(long int nenner, long int zaehler);
    Bruch(long int z);
    Bruch();

    // Getter und Setter
    long int getDenominator() const;
    long int getNumerator() const;
    void setBruch(long int n, long int z);

    // Operatoren zwischen zwei Objekten vom Typ Bruch
    friend Bruch operator+ (const Bruch &lhs, const Bruch &rhs);
    friend Bruch operator* (const Bruch &lhs, const Bruch &rhs);
    friend Bruch operator- (const Bruch &lhs, const Bruch &rhs);
    friend Bruch operator/ (const Bruch &lhs, const Bruch &rhs);
    friend std::ostream& operator<< (std::ostream& output, const Bruch& bruch);

  private:

  // Attribute
  long int _nenner;
  long int _zaehler;
};

#endif
