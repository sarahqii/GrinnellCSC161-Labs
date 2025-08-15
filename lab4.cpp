#include <iostream>
#include <time.h>

using namespace std;

int main ()
{
    srand(time(NULL));
    int randomNumber = rand() % 100 + 1;
    int guess;
    int guessCount = 0;

    cout << "Pick a number between 1 and 100, enter '0' to quit" << endl;

    while (true)
    {
        cin >> guess;

        if (guess == 0)
        {
            cout << "Thanks for playing" << endl;
            break;
        }

        guessCount++;

        if (guess < randomNumber)
    {
        cout << "Too low" << endl;
    }
    else if (guess > randomNumber)
    {
        cout << "Too high" << endl;
    }
    else
    {
        cout << "Correct, number of guesses: " << guessCount << endl;
        break;
    }
    }

    return 0;
}