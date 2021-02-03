#include <array>
#include <iostream>

#ifndef BRUCH_H
#define BRUCH_H

class Bruch {

	public:

		Bruch(long int nenner, long int zaehler);
		Bruch(long int z);
		Bruch();

		// Getter und Setter
		long int getNenner() const;
		long int getZaehler() const;
		void setBruch(long int n, long int z);

		// Operatoren zwischen zwei Objekten vom Typ Bruch
		friend Bruch operator+ (const Bruch& lhs, const Bruch& rhs);
		friend Bruch operator* (const Bruch& lhs, const Bruch& rhs);
		friend Bruch operator- (const Bruch& lhs, const Bruch& rhs);
		friend Bruch operator/ (const Bruch& lhs, const Bruch& rhs);
		friend std::ostream& operator<< (std::ostream& output, const Bruch& bruch);

		// Operatoren zwischen Objekten vom Typ Bruch und dem Datentyp long int
		friend Bruch operator+ (const Bruch& lhs, const std::array<long int, 2>& rhs);
		friend Bruch operator* (const Bruch& lhs, const std::array<long int, 2>& rhs);
		friend Bruch operator- (const Bruch& lhs, const std::array<long int, 2>& rhs);
		friend Bruch operator/ (const Bruch& lhs, const std::array<long int, 2>& rhs);

	private:

		long int _nenner;
		long int _zaehler;
};

#endif
