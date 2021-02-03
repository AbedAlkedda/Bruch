#include <iostream>
#include "Bruch.hpp"
#include "BruchHelper.hpp"


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

long int Bruch::getZaehler() const {
	return _zaehler;
}

long int Bruch::getNenner() const {
	return _nenner;
}

void Bruch::setBruch(long int nenner, long int zaehler){
	_nenner = nenner;
	_zaehler = zaehler;
}

Bruch operator+ (const Bruch& lhs, const Bruch& rhs){
	Bruch result;
	result.setBruch(lhs.getNenner()  + rhs.getNenner(),
								  lhs.getZaehler() + rhs.getZaehler());
	return result;
}

Bruch operator* (const Bruch& lhs, const Bruch& rhs){
	Bruch result;
	result.setBruch(lhs.getNenner()  * rhs.getNenner(),
								  lhs.getZaehler() * rhs.getZaehler());
	return result;
}

// Bruch operator- (const Bruch& lhs, const Bruch& rhs){
// 	Bruch result;
// 	result.setBruch(lhs.getNenner()  - rhs.getNenner(),
// 									lhs.getZaehler() - rhs.getZaehler());
// 	return result;
// }

Bruch operator/ (const Bruch& lhs, const Bruch& rhs){
	Bruch result;
	result.setBruch(lhs.getZaehler() * rhs.getNenner(),
									lhs.getNenner()  * rhs.getZaehler());
	return result;
}

std::ostream& operator<< (std::ostream& output, const Bruch& bruch){
	output << bruch.getZaehler() << '/' << bruch.getNenner();
	return output;
}

Bruch operator+ (const Bruch& lhs_bruch, const std::array<long int, 2>& rhs_bruch){
	long int lhs_nenner_bruch  = lhs_bruch.getNenner(),
			 		 lhs_zaehler_bruch = lhs_bruch.getZaehler(),
			 		 rhs_nenner_bruch  = rhs_bruch[0],
					 rhs_zaehler_bruch = rhs_bruch[1];
	
	hasSameDenominator(lhs_nenner_bruch, rhs_nenner_bruch);

	Bruch result;
	result.setBruch(lhs_zaehler_bruch + rhs_zaehler_bruch,
									lhs_nenner_bruch  + rhs_nenner_bruch);
	return result;
}

Bruch operator* (const Bruch& lhs_bruch, const std::array<long int, 2>& rhs_bruch){
	long int lhs_nenner_bruch  = lhs_bruch.getNenner(),
			 		 lhs_zaehler_bruch = lhs_bruch.getZaehler(),
			 		 rhs_nenner_bruch  = rhs_bruch[0],
					 rhs_zaehler_bruch = rhs_bruch[1];
	
	Bruch result;
	result.setBruch(lhs_zaehler_bruch * rhs_zaehler_bruch,
									lhs_nenner_bruch  * rhs_nenner_bruch);
	return result;
}

// Bruch operator- (const Bruch& lhs_bruch, const std::array<long int, 2>& rhs_bruch){
// 	long int lhs_nenner_bruch  = lhs_bruch.getNenner(),
// 			 		 lhs_zaehler_bruch = lhs_bruch.getZaehler(),
// 			 		 rhs_nenner_bruch  = rhs_bruch[0],
// 					 rhs_zaehler_bruch = rhs_bruch[1];
	
// 	Bruch result;
// 	result.setBruch(lhs_zaehler_bruch + rhs_zaehler_bruch,
// 									lhs_nenner_bruch  + rhs_nenner_bruch);
// 	return result;
// }

Bruch operator/ (const Bruch& lhs_bruch, const std::array<long int, 2>& rhs_bruch){
	long int lhs_nenner_bruch  = lhs_bruch.getNenner(),
			 		 lhs_zaehler_bruch = lhs_bruch.getZaehler(),
			 		 rhs_nenner_bruch  = rhs_bruch[0],
					 rhs_zaehler_bruch = rhs_bruch[1];
	
	Bruch result;
	result.setBruch(lhs_zaehler_bruch * rhs_nenner_bruch,
									lhs_nenner_bruch  * rhs_zaehler_bruch);
	return result;
}
