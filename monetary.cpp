
#include <iostream>
using namespace std;

int main()
{
	// Prompt user for double precision floating-point value and store
	cout << "Enter floating point value: ";
	double inputValue;
	cin >> inputValue;

	// Convert to amount of cents (pennies)
    int remainingCents = (inputValue * 100);

    // Compute number of tens
    int tens = remainingCents / 1000;

    // Number of remaining pennies
    remainingCents = remainingCents % 1000;
    // Note you could also write the statement above as:
    // remainingCents %= 1000;

    // Compute number of fives
    int fives = remainingCents / 500;

    // Number of remaining pennies
    remainingCents = remainingCents % 500;

    // Number of ones
    int ones = remainingCents / 100;

    // Number of remaining pennies
    remainingCents = remainingCents % 100;

    // Computer number of quarters
    int quarters = remainingCents / 25;

    // Number of remaining pennies
    remainingCents = remainingCents % 25;

    // Computer number of dimes
    int dimes = remainingCents / 10;

    // Number of remaining pennies
    remainingCents = remainingCents % 10;

    // Computer number of nickels
    int nickels = remainingCents / 5;

    // Number of remaining pennies
    remainingCents = remainingCents % 5;

    // Print output results
    cout << tens << " ten-dollar bill(s)" << endl;
    cout << fives << " five-dollar bill(s)" << endl;
    cout << ones << " one-dollar bill(s)" << endl;
    cout << quarters << " quarter(s)" << endl;
    cout << dimes << " dimes(s)" << endl;
    cout << nickels << " nickel(s)" << endl;
    cout << remainingCents << " pennies(s)" << endl;

	return 0;
}
