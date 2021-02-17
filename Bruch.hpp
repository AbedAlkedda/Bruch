#include <array>
#include <iostream>
#include <unordered_map>

#ifndef BRUCH_H
#define BRUCH_H
/*
  Man soll nur dann einen benutzerdefinierten Destruktor definieren, wenn die Klasse Handles für Systemressourcen speichert,
  die freigegeben werden müssen, oder für  Zeiger, die den Speicher besitzen,
  auf den sie verweisen. Da für das Projekt weder Systemressourcen noch Zeiger verwendet wurden, wurde kein Destruktor deklariert.
*/
class Bruch {

  public:
    // Konstruktor deklarieren
    // Für den Fall Bruch bruch(2,3) beispielweise
    Bruch(long int nenner, long int zaehler);

    // Für den Fall Bruch bruch(2) beispielweise
    // Wenn der Nutzer die Option ein Bruch mit einer Zahl auswählt,
    // hilft diese Deklaration ein Objekt vom DatenTyp Bruch zu erstellen
    // (die Zahl wrid ein Bruch)
    Bruch(long int zaehler);

    // Für den Fall Bruch bruch; beispielweise
    Bruch();


    // Getter
    long int getDenominator() const;
    long int getNumerator() const;

    // Bruch kuerzer
    // @Params ist ein Objekt vom Datentyp Bruch
    void kuerzeBruch(Bruch &bruch);

    // Operatoren zwischen zwei Objekten vom Typ Bruch
    // @Params sind zwei Objekte der Klasse Bruch und der @return Wert ist
    // das Ergebnis vom Operator und ist auch von der Klasse Bruch
    friend Bruch operator+ (const Bruch &lhs, const Bruch &rhs);
    friend Bruch operator* (const Bruch &lhs, const Bruch &rhs);
    friend Bruch operator- (const Bruch &lhs, const Bruch &rhs);
    friend Bruch operator/ (const Bruch &lhs, const Bruch &rhs);

    // @Params: LeftHandSide ist ein (reference variable) von der Klasse ostream(Ausgabe),
    //          RightHandSide ist ein (reference variable) von der Klasse Bruch
    // @return Wert ist der Nenner und Zähler von der Klasse Bruch und ist von der Klasse ostream
    friend std::ostream& operator<< (std::ostream& output, const Bruch& bruch);

    // @Params: LeftHandSide ist ein (reference variable) von der Klasse istream(Eingabe),
    //          RightHandSide ist ein (reference variable) von der Klasse Bruch
    // @return Wert von der Klasse ostream und damit wird der Bruch eingelesen
    friend std::istream& operator>> (std::istream& input, Bruch& bruch);

  private:

  // Attribute
  long int _nenner;
  long int _zaehler;

  // private Methoden
  // @Params Nenner und Zähler eines Bruchs
  void _setBruch(long int nenner, long int zaehler);
};

#endif
