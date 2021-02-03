#include <iostream>
#include "Bruch.hpp"

// specifying what we ONLY need from namespace std
using std::cout;
using std::cin;
using std::endl;

int main() {
	Bruch b(1, 2); // 2/1
	Bruch c(1, 2); // 2/1	
	cout << b << endl;

	Bruch test;
	test = b + c; // 4/2
	cout << test << endl;

	return 0;
}
