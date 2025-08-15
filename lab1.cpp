#include <iostream>
using namespace  std;

     int main( )
     {
      int number;
         cout << "Please enter a whole number between 0 and 9:\n";
         cin >> number;
         cout << "     +\n";
         cout << "    ***\n";
         cout << "   #####\n";
         cout << "  *******\n";

         cout << " ";
          for (int i = 0; i < 9; ++i) 
          {
            cout << number;
         }
            cout << endl;

         cout << "  *******\n";
         cout << "   #####\n";
         cout << "    ***\n";
         cout << "     +\n";
      return 0;
    }