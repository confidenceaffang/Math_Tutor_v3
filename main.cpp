/****************************************************************************
Program:     MathTutorV3
Programmers:Confidence Affang
Date:        10/24/2024
Description: A simple silly math tutor program. It asks the user for their name,
has an enum for the different math types, gives the user 3 attempts max for each round
it also increase the range of questions being asked by a constant value of 10 when levelling up.
If the person gets 3 correct the person moves the next level and increases the range but if the person
gets 3 incorrect the person moves down a level if the person is currently at a level greater than 1.
After 3 attempts the program asks the user if they wish to continue and does continue and if they say no
it terminates the program.
Github URL: https://github.com/confidenceaffang/Math_Tutor_v3.git
***************************************************************************/

#include <iostream> // for cin and cout
#include <cstdlib> // for generating random functions
#include <ctime> // it includes the c++ time library

using namespace std; // for cin and cout

// creates and enum for the various math types
enum math_type { Addition, Subtraction, Multiplication, Division };

const int MAX_ATTEMPTS = 3; // assigning the maximum number of attempts to 3
const int LEVEL_RANGE_CHANGE = 10; // assigning the range of which numbers are changes from on level to another

int main() {
    //used the srand fuction to seed time since the development of C++ so that the random numbers generated are not the same
    srand(time(0));
    string userName = "hi"; //creates and initializes a string of the variable userName
    string userInput = "yes"; //creates and initializes a string of the variable userInput
    int level_number = 1; //creates and initializes an integer of the variable level_number
    int level_range = 10; //creates and initializes an integer of the variable level_range
    int number_correct = 0; //creates and initializes an integer for the number of correct entries
    int incorrect_number = 0; //creates and initializes an integer for the number of incorrect entries
    int attempts = 1; //creates and initializes an integer for the number of attempts
    int userAnswer = 0; //creates and initializes an integer for the user's answer
    int correctAnswer = 0; //creates and initializes an integer for the correct answer
    string operationSymbol = "+"; //creates and initializes a string for the operating symbol
    int leftNumber = 0; // creates and initializes an integer for the left number in the question
    int rightNumber = 0; // creates and initializes an integer for the righ tnumber in the question
    int randommath_type = 0; //creates and initializes an integer for the random math types in the enum function
    int temp = 0; // creates and initializes a temporary integer to be used later on in the code

    // Displays the header of the program
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

    cout << "What is your name? "; // prints out a statement asking the user for their name
    getline(cin, userName); // takes the user's name and assigns it to the varible userName
    // prints out a welcom statement
    cout << endl;
    cout << "Welcome " << userName << " to the silly simple math tutor!" << endl;

    do {
        leftNumber = rand() % level_range + 1;
        // sets the left number to a random integer between the limits of 1 and the level's range
        rightNumber = rand() % level_range + 1;
        // sets the right number to a random integer between the limits of 1 and the level's range
        randommath_type = rand() % (Division + 1); // sets the math type to a random math_type in the enum function

        switch (randommath_type) {
            //creates a switch for the math type chosen
            //if the math type chosen is Addition
            case Addition:
                correctAnswer = leftNumber + rightNumber; // Assigns correct answer to the sum of left and right numbers
                operationSymbol = " + "; // Assigns the Operating symbol to +
                break; // ends the swtich case
            //if the math type chosen is Subtraction
            case Subtraction:
                //swaps the right and left numbers to avoid getting negative result
                if (leftNumber < rightNumber) {
                    temp = leftNumber;
                    leftNumber = rightNumber;
                    rightNumber = temp;
                };
                correctAnswer = leftNumber - rightNumber; // assigns correct answer to the difference between
                operationSymbol = " - "; // Assigns the Operating symbol to -
                break; // ends the switch case
            // If the math type is Multiplication
            case Multiplication:
                correctAnswer = leftNumber * rightNumber; // assigns correct answer to the product of both numbers
                operationSymbol = " * "; // Assigns the Operating symbol to *
                break; // ends the switch case
            //if the math type is Division
            case Division:
                correctAnswer = leftNumber / rightNumber; // Assigns correct answer to left number / right number
                operationSymbol = " / "; // assigns the operating symbol to /
                break; // ends the switch case
            // If the math type is invalid
            default:
                cout << "invalid input" << endl;
                break; // ends the default block
        }
        // prints out he question to the user showing the level
        cout << "[Level #" << level_number << "]\t" << userName << ", what does " << leftNumber << operationSymbol <<
                rightNumber << " = ";
        cin >> userAnswer; // takes in the user's answe to the quesion

        //if the user answers correctly
        if (userAnswer == correctAnswer) {
            cout << "Congrats! That was correct :)" << endl; // prints out
            number_correct++; // increases the number of correct attempts by 1
            attempts++; // increasing the number of attempts by 1
            incorrect_number =0;
        } else {
            //if the user answers incorreclty
            attempts++; // increases the number of attempts by 1
            cout << "Bummer, that was incorrect." << endl; // print out
            incorrect_number++; // increses the number of incorrect attempt by 1
            if (attempts >= MAX_ATTEMPTS) {
                cout << "Sorry, you are out of attempts." << endl; // if attempts are exhausted
                cout << "The correct answer was " << correctAnswer << "." << endl; // prints out the correct answer
                attempts = 0; // Reset attempts after failure
                cout << "Do you want to continue (y=yes | n=no)? "; // asks if the person wants to continue
                cin >> userInput; // takes in the user's input for the question
            } else {
                //if it's incorrect but there are still more attempts
                cout << "You have " << MAX_ATTEMPTS - attempts << " attempts left." << endl;
                // prints out the number of attempts left
            }

        }

        //executes if the number of correct attempt is 3
        if (number_correct == 3) {
            level_number++; // increases the level by 1
            level_range += LEVEL_RANGE_CHANGE; // increase the range of question  by the constant value of 10
            number_correct = 0; // resets the number of corrects attempt to 0
            incorrect_number = 0; // resets the number of incorrect attempts also to 0
            cout << "WoHoo - Levelling up to " << level_number << endl; // prints a levelling up statement
            cout << "The numbers are now between 1 and " << level_range << "." << endl;
            // prints the new range of questions
            cout << "Do you want to continue (y=yes | n=no)?\t"; // prints the question asking the person to continue
            cin >> userInput; // takes in the user input if the person wants to continue
            attempts = 0;// resets the attempts
        }
        //executes if the number of incorrect attemps is 3 and the level is greater than 1
        else if (incorrect_number == 3 && level_number > 1) {
            level_number--; // decrease the level by 1
            level_range -= LEVEL_RANGE_CHANGE; // decreases the range of question  by the constant value of 10
            incorrect_number = 0; // resets the number of incorrect attempts to 0
            number_correct = 0; // resets the number of corrects attempts to 0
            cout << "Sorry, but you're leveling down to " << level_number << "." << endl;
            // prints the levelling down statement
            cout << "The numbers are now between 1 and " << level_range << "." << endl; // prints the new question range
            cout << "Do you want to continue (y=yes | n=no)? "; // asks if the person would like to continue
            cin >> userInput; // takes in the user input for the question above
            attempts =0; // resets the attempts
        }
    } while (userInput == "yes" || userInput == "y"); // loops as long as the user inputs a yes

    cout << "Keep calm and do math!" << endl; // prints out when the user input anything aside a yes

    return 0; // exits with a program status code 0
}
