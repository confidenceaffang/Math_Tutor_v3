/****************************************************************************
Program:     MathTutorV4
Programmers:Confidence Affang, Jacob Ferguson
Date:        10/24/2024
Description: A simple silly math tutor program. It asks the user for their name,
has an enum for the different math types, gives the user 3 attempts max for each round
it also increase the range of questions being asked by a constant value of 10 when levelling up.
If the person gets 3 correct the person moves the next level and increases the range but if the person
gets 3 incorrect the person moves down a level if the person is currently at a level greater than 1.
After 3 attempts the program asks the user if they wish to continue and does continue and if they say no
it terminates the program. It also has a 2 vectoe components that actually store the questions asked,
the attempts, the correct answer and the level and also displays the summary report of the total questions
asked, the total correct, total incorrect and the average correct answers which is rounded to the nearest integer
Github URL:https://github.com/confidenceaffang/MathTutorv4.git
***************************************************************************/

#include <iostream> //  for cin/cout
#include <string>   //  needed for string data types
#include <cstdlib>  // for generating random numbers
#include <ctime>    // include the time library
#include <cctype>   // for isalpha
#include <limits>   // to use numeric_limits

using namespace std;

int main()
{
    const int MAX_ATTEMPS = 3;         // creates and initializes the maximum attempts
    const int LEVEL_RANGE_CHANGE = 10; // creates and initializes the changes in level range

    // sets math type as an enum
    enum MathType
    {
        MT_ADD,
        MT_SUBTRACT,
        MT_MULTIPLY,
        MT_DIVIDE
    };
    MathType questionType;

    int leftNum = 0;  // creates and initializes the left number
    int rightNum = 0; // creates and initializes the right number
    int lessThanNum = 0;
    int userAns = 0;                       // creates and initializes the user answer
    int correctAns = 0;                    // creates and initializes the correct answer
    int totalCorrect = 0;                  // creates and initializes the total correct answers
    int totalIncorrect = 0;                // creates and initializes the total incorect answers
    int currentLevel = 1;                  // creates and initializes the current level
    int currentRange = LEVEL_RANGE_CHANGE; // creates and initializes the range of values for current level
    auto attempts = 0;                     // creates and initializes the number of attempts
    char mathSymbol = '0';                 // assign mathSymbol
    string userName = "unknown";           // assign userName variable
    string userInput = "unknown";          // assign userInput

    // Display heading and jokes
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
    getline(cin, userName);
    cout << "Welcome " << userName << " to the silly simple math tutor!" << endl;

    do
    {
        // Generate random numbers based on current range
        leftNum = rand() % currentRange + 1;
        rightNum = rand() % currentRange + 1;
        questionType = static_cast<MathType>(rand() % 4);

        // Determine the correct answer and math symbol based on question type
        switch (questionType)
        {
        case MT_ADD:
            correctAns = leftNum + rightNum;
            mathSymbol = '+';
            break;
        case MT_SUBTRACT:
            if (leftNum < rightNum)
                swap(leftNum, rightNum);
            correctAns = leftNum - rightNum;
            mathSymbol = '-';
            break;
        case MT_MULTIPLY:
            correctAns = leftNum * rightNum;
            mathSymbol = '*';
            break;
        case MT_DIVIDE:
            correctAns = leftNum;
            leftNum *= rightNum;
            mathSymbol = '/';
            break;
        }

        for (attempts = 1; attempts <= MAX_ATTEMPS; attempts++)
        {
            cout << "[Level #" << currentLevel << "] ";
            cout << userName << ", what is " << leftNum << " " << mathSymbol << " " << rightNum << "? ";
            // Loop until the user enters numeric data
            while (!(cin >> userAns))
            {
                cin.clear(); // clear the cin error flag
                // need to include the limits library to use numeric limits
                cin.ignore(numeric_limits<streamsize>::max(),
                           '\n'); // ignore the max input, up to '\n'
                cout << "\tInvalid input?" << endl;
                cout << "\tPlease enter a number: ";
            } // end of get userAnswer while loop

            // Announces to the user if their answer was correct or incorrect, and handles the attempts
            if (userAns == correctAns)
            {
                cout << "\tCorrect!" << endl;
                totalCorrect++;
                break;
            }
            else
            {
                if (attempts == MAX_ATTEMPS)
                {
                    cout << "\tIncorrect! The correct answer was " << correctAns << endl;
                }
                else
                {
                    cout << "\tIncorrect! You have " << MAX_ATTEMPS - attempts << " attempts left." << endl;
                }
                totalIncorrect++;
            }
        }

        // Level adjustment based on total correct/incorrect answers
        if (totalCorrect == 3)
        {
            currentLevel++;
            totalCorrect = 0;
            totalIncorrect = 0;
            currentRange += LEVEL_RANGE_CHANGE;
            cout << "Congrats! You are now at [Level " << currentLevel << "]!" << endl;
        }
        else if (totalIncorrect == 3 && currentLevel > 1)
        {
            currentLevel--;
            currentRange -= LEVEL_RANGE_CHANGE;
            totalCorrect = 0;
            totalIncorrect = 0;
            cout << "Sorry! You are now at [Level " << currentLevel << "]. Try again!" << endl;
        }
        else if (totalIncorrect == 3)
        {
            totalCorrect = 0;
            totalIncorrect = 0;
        }

        // Ask if the user wants another question
        cin.ignore(); // Clear newline character from buffer
        while (true)
        {
            cout << "Do you want to try another question? (y=yes | n=no): ";
            getline(cin, userInput);
            for (char &c : userInput)
                c = tolower(c); // Convert input to lowercase
            if (userInput == "y" || userInput == "yes" || userInput == "n" || userInput == "no")
                break;
            cout << "Invalid input. Please try again." << endl;
        }

    } while (userInput == "y" || userInput == "yes");
    return 0;
}
