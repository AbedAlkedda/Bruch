#ifndef BRUCH_H
#define BRUCH_H

class Bruch {

	public:

		Bruch(int nenner, int zaehler);
		Bruch(int z);
		Bruch();

		int getNenner() const;
		int getZaehler() const;

		void setBruch(int n, int z);

		// Operatoren zwischen zwei Objekten vom Typ Bruch
		friend Bruch operator+(const Bruch& lhs,const Bruch& rhs);
		friend Bruch operator*(const Bruch& lhs,const Bruch& rhs);
		friend Bruch operator-(const Bruch& lhs,const Bruch& rhs);
		friend Bruch operator/(const Bruch& lhs,const Bruch& rhs);
		friend std::ostream& operator<<(std::ostream& output, const Bruch& bruch);

		// Operatoren zwischen Objekten vom Typ Bruch und dem Datentyp long int

	private:

		int nenner;
		int zaehler;
};

#endif
