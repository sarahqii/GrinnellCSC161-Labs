#include <iostream>
#include <cmath>

using namespace  std;

     int main( )
     {
      double amount;
         cout << "Enter floating point value: ";
         cin >> amount;

      int totalCents = round(amount * 100);
      int tenDollarBills = totalCents / 1000;
         totalCents %= 1000;
      int fiveDollarBills = totalCents / 500;
         totalCents %= 500;
      int oneDollarBills = totalCents / 100;
         totalCents %= 100;
      int quarters = totalCents / 25;
         totalCents %= 25;
      int dimes = totalCents / 10;
         totalCents %= 10;
      int nickels = totalCents / 5;
         totalCents %= 5;
      int pennies = totalCents;

      cout << tenDollarBills << "ten-dollar bill(s)" << endl;
      cout << fiveDollarBills << "five-dollar bill(s)" << endl;
      cout << oneDollarBills << "one-dollar bill(s)" << endl;
      cout << quarters << "quarter(s)" << endl;
      cout << dimes << "dime(s)" << endl;
      cout << nickels << "nickel(s)" << endl;
      cout << pennies << "pennies(s)" << endl;
      return 0;
    }