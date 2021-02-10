#include <iostream>
#include "Bruch.hpp"
#include "BruchHelper.hpp"
#include <vector>

using std::cout;
using std::cin;
using std::endl;

using namespace FractionOperator;

int main() {
  cout << "\U00002663\U00002663\tDatentype Bruch\t\U00002663\U00002663\n";
  std::string user_input;

  do{
    cout << "1. Operator zwischen Bruch und long int\n"
         << "2. Operator zwischen Brüche" << endl;
    cin >> user_input;
    cin.ignore(1);
    if(user_input == "1"){
      showUsageExample();
      callOperatorFractionLongInt();
    } else if (user_input == "2"){
      callOperatorFractions();
    } else {
      cout << "Falsche Eingabe! "
           << "Nochmal versuchen? [ja/nein] ";
      cin >> user_input;

      for (unsigned long i = 0; i < user_input.length(); i++){
        user_input[i] = static_cast<char>(tolower(user_input[i]));
      }

    }
    cout << "Möchten Sie nochmal rechnen? [ja/nein] ";
    cin >> user_input;
  } while(user_input == "ja");

  return 0;
}
