#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

enum math_type { Addition, Subtraction, Multiplication, Division };

const int MAX_ATTEMPTS = 3;
const int LEVEL_RANGE_CHANGE = 10;

int main() {
    srand(time(0));

    string userName = "hi";
    string userInput = "yes";
    int level_number = 1;
     int level_range = 10;
    int number_correct = 0;
    int incorrect_number = 0;
    int attempts = 1;
    int userAnswer = 0;
    int correctAnswer =0 ;
    string operationSymbol = "+";

    cout << "***********************************************************" << endl;
    cout << " __  __       _   _   _____      _             " << endl;
    cout << "|  \\/  | __ _| |_| |_|_   _|   _| |_ ___  _ __ " << endl;
    cout << "| |\\/| |/ _` | __| '_ \\| || | | | __/ _ \\| ‘__|" << endl;
    cout << "| |  | | (_| | |_| | | | || |_| | || (_) | |  " << endl;
    cout << "|_|  |_|\\____|\\__|_| |_|_| \\____|\\__\\___/|_|  " << endl;
    cout << "***********************************************************" << endl;
    cout << "   *       Welcome to the silly simple math tutor!     *" << endl;
    cout << "***********************************************************" << endl;
    cout << endl;
    cout << "Funny math jokes and facts: " << endl;
    cout << "  * The product of any even number times two is always even!" << endl;
    cout << "  * Every even number times two is always divisible by four!" << endl;
    cout << "  * If you're cold, go to the corner of the room. It's 90 degrees there!" << endl;
    cout << "  * Why is 69 so scared of 70? Because once they fought, and 71." << endl;
    cout << "***********************************************************" << endl;
    cout << endl;
    cout << "What is your name? ";
    cin >> userName;
    cout << "Welcome " << userName << " to the silly simple math tutor!" << endl;

  do {

          int leftNumber = rand() % level_range + 1;
          int rightNumber = rand() % level_range + 1;
          int randommath_type = rand() % (Division + 1);

          switch (randommath_type) {
              case Addition:
                  correctAnswer = leftNumber + rightNumber;
              operationSymbol = " + ";
              break;
              case Subtraction:
              correctAnswer = leftNumber - rightNumber;
              operationSymbol = " - ";
              break;
              case Multiplication:
                  correctAnswer = leftNumber * rightNumber;
              operationSymbol = " * ";
              break;
              case Division:
              correctAnswer = leftNumber / rightNumber;
              operationSymbol = " / ";
              break;
          }

          cout << "[Level #" << level_number << "]\t" << userName << ", what does " << leftNumber << operationSymbol << rightNumber << " = ";
          cin >> userAnswer;

          if (userAnswer == correctAnswer) {
              cout << "Congrats! That was correct :)" << endl;
              number_correct++;
              attempts++;
              incorrect_number = 0;
          } else {
              cout << "Bummer, that was incorrect." << endl;
              incorrect_number++;
              if (attempts >= MAX_ATTEMPTS) {
                  cout << "Sorry, you are out of attempts." << endl;
                  cout << "The correct answer was " << correctAnswer << "." << endl;
                  attempts = 1;  // Reset attempts after failure
                  cout << "Do you want to continue (y=yes | n=no)? ";
                  cin >> userInput;
              } else {
                  cout << "You have " << MAX_ATTEMPTS - attempts << " attempts left." << endl;
              }
              attempts++;
          }

      if (number_correct == 3) {
          level_number++;
          level_range += LEVEL_RANGE_CHANGE;
          number_correct = 0;
          incorrect_number = 0;
          cout << "WoHoo - Levelling up to " << level_number << endl;
          cout << "The numbers are now between 1 and " << level_range << "." << endl;
          cout << "Do you want to continue (y=yes | n=no)? ";
          cin >> userInput;
      } else if (incorrect_number == 3 && level_number > 1) {
          level_number--;
          level_range -= LEVEL_RANGE_CHANGE;
          incorrect_number = 0;
          number_correct = 0;
          cout << "Sorry, but you're leveling down to " << level_number << "." << endl;
          cout << "The numbers are now between 1 and " << level_range << "." << endl;
          cout << "Do you want to continue (y=yes | n=no)? ";
          cin >> userInput;
      }
  } while (userInput == "yes" || userInput == "y");

    cout << "Keep calm and do math!" << endl;
    return 0;
}
