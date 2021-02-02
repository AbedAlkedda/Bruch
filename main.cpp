#include <iostream>
#include "Bruch.h"

// specifying what we ONLY need from namespace std
using std::cout;
using std::cin;
using std::endl;

int main() {
	Bruch b(1, 10);
	Bruch c(3, 4);
	Bruch a(10);

	Bruch d = b + c;
	Bruch e = b * c;
	Bruch f = b - c;
	Bruch g = b / c;

	cout << d.getZaehler() << " " << d.getNenner()<< endl;
	cout << e.getZaehler() << " " << e.getNenner()<< endl;
	cout << f.getZaehler() << " " << f.getNenner()<< endl;
	cout << g.getZaehler() << " " << g.getNenner()<< endl;

	cout << a << endl;
	return 0;
}
