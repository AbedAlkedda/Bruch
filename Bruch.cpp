#include <iostream>
#include "Bruch.h"

Bruch::Bruch(int nenner_lhs, int zaehler_rhs){
	nenner  = nenner_lhs;
	zaehler = zaehler_rhs;
 }

Bruch::Bruch(int z){
	nenner  = 1;
	zaehler = z;
 }

Bruch::Bruch(){
	nenner  = 1;
	zaehler = 1;
 }

int Bruch::getZaehler() const {
	return zaehler;
}

int Bruch::getNenner() const {
	return nenner;
}

void Bruch::setBruch(int n, int z){
	nenner  = n;
	zaehler = z;
}

Bruch operator+ (const Bruch& lhs, const Bruch& rhs){
	Bruch result;
	result.setBruch(lhs.getZaehler() + rhs.getZaehler(),
								  lhs.getNenner()  + rhs.getNenner());
	return result;
}

Bruch operator* (const Bruch& lhs, const Bruch& rhs){
	Bruch result;
	result.setBruch(lhs.getZaehler() * rhs.getZaehler(),
								  lhs.getNenner()  * rhs.getNenner());
	return result;
}

Bruch operator- (const Bruch& lhs, const Bruch& rhs){
	Bruch result;
	result.setBruch(lhs.getZaehler() - rhs.getZaehler(),
									lhs.getNenner()  - rhs.getNenner());
	return result;
}

Bruch operator/ (const Bruch& lhs, const Bruch& rhs){
	Bruch result;
	result.setBruch(lhs.getZaehler() * rhs.getNenner(),
									lhs.getZaehler() * rhs.getNenner());
	return result;
}

std::ostream& operator<< (std::ostream& output, const Bruch& bruch){
	output << bruch.getZaehler() << '/' << bruch.getNenner();
	return output;
}
