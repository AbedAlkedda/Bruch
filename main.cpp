#include <vector>
#include <iostream>
#include "Bruch.hpp"
#include "BruchHelper.hpp"

using std::cout;
using std::cin;
using std::endl;

using namespace FractionOperator;

/*
  In der int main() Methode lebt das Programm und im Laufe der Zeit wird das größer, deshalb
  habe ich die Methode dünn gelassen und die ganze Logik wo anderes gepackt. Da wenn man die Methode main liest,
  versteht man die Hauptaufge des Programms und zwar Bruch rechnen
*/

int main() {
  printExerciseExample();

  cout << "\tDatentype Bruch\n";
  std::string user_input;

  do{
    cout << "1. Operator zwischen Bruch und long int\n"
         << "2. Operator zwischen Brüchen" << endl;
    cin >> user_input;
    cin.ignore(1);
    if (user_input == "1"){
      showUsageExample();
      callOperatorFractionLongInt();
      user_input = userInput();
    } else if (user_input == "2"){
      showUsageExampleFractions();
      callOperatorFractions();
      user_input = userInput();
    } else {
      cout << "Falsche Eingabe! "
           << "Nochmal versuchen? [ja/nein] ";
      cin >> user_input;

      // Zu dem Fall, dass der Nutzer JA/Ja oder jA eingibt
      for (unsigned long i = 0; i < user_input.length(); i++){
        user_input[i] = static_cast<char>(tolower(user_input[i]));
      }
    }
  } while(user_input == "ja");

  return 0;
}
