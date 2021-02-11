#include <array>
#include <iostream>
#include <unordered_map>

#ifndef BRUCH_H
#define BRUCH_H

class Bruch {

  public:
    // Konstruktor
    Bruch(long int nenner, long int zaehler);
    Bruch(long int zaehler);
    Bruch();

    // Getter
    long int getDenominator() const;
    long int getNumerator() const;

    // Bruch keurzer
    void kuerzeBruch(Bruch &bruch);

    // Operatoren zwischen zwei Objekten vom Typ Bruch
    friend Bruch operator+ (const Bruch &lhs, const Bruch &rhs);
    friend Bruch operator* (const Bruch &lhs, const Bruch &rhs);
    friend Bruch operator- (const Bruch &lhs, const Bruch &rhs);
    friend Bruch operator/ (const Bruch &lhs, const Bruch &rhs);
    friend std::ostream& operator<< (std::ostream& output, const Bruch& bruch);
    friend std::istream& operator>> (std::istream& input, Bruch& bruch);

  private:

  // Attribute
  long int _nenner;
  long int _zaehler;

  // private Methoden
  void _setBruch(long int n, long int z);
};

#endif
