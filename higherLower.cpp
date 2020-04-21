#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

//using namespace std;

int getGuess()
{
    int guess;
    bool inputOK = false;
    do
    {
        // Get the guess from the user
        std::cin >> guess;

        // Check if the guess is a logical value, if not throw an error
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n'); 
            std::cout <<  "Your guess must be a number, try again: ";
            continue;
        }            
        // Check if the input is within bounds 
        else if (guess < 1 || guess > 100) 
        {
            std::cout <<  "Your guess must be between 1 and 100, try again: ";
        }
        else 
        {
            inputOK = true;
        }
    
    } while (!inputOK);
    return guess;
}

int main() 
{
    char ContinueAnswer;
    do {
        // initialize random seed by changing it with the current second as seed
        srand (time(0));
        // generate number between 1 and 100
        int result = rand() % 100 + 1;
        
        int numberOfGuesses = 1;
        
        //std::cout << result << std::endl;
        std::cout << "Let's play a number guessing game." << std::endl;
        std::cout << "Enter a number between 1 and 100: ";
        int guess = getGuess();
        
        // Check the results
        do
        {
            if (guess > result) {
                std::cout << "Lower, try again: ";
            }
            else if (guess < result) {
                std::cout << "Higher, try again: ";
            }
            else if (guess == result) {
                break;
            }
            guess = getGuess();
            numberOfGuesses++;
        } while (!(result==guess));
        
        std::cout << "Well done! The number was " << result << std::endl;
        std::cout << "It took you " << numberOfGuesses << " guesses." << std::endl;

        std::cout << "\nDo you want another game? (Y/N)";
        std::cin >> ContinueAnswer;
        if (!(ContinueAnswer == 'Y' || ContinueAnswer == 'y'))
        {
            std::cout << "Ending program. Good bye.";
        }
    } while (ContinueAnswer == 'Y' || ContinueAnswer == 'y');
    
    return 0;
}