#include <iostream>
#include "Bruch.hpp"

// specifying what we ONLY need from namespace std
using std::cout;
using std::cin;
using std::endl;

int main() {

	Bruch b(2, 1); // 2/1
	Bruch c(4, 2); // 4/2
	std::array <long int, 2> a = {2, 2};
	Bruch test = b - a;

	cout << test << endl;
	return 0;
}
