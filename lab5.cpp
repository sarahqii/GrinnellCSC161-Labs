#include <iostream>
#include <cmath>

using namespace std;

int main ()
{
    const double PI = 3.14159;
    int choice;
    double a, b, alpha;

    while (true) {
        cout << "==========================\n";
	    cout << "Right Triangle calculator\n";
	    cout << "==========================\n";

        cout << "Please select an option from the menu below\n";
        cout << "1) Input the lengths of side a and a side b of a right triangle\n";
        cout << "2) Input the length of side a and angle alpha of a right triangle\n";
        cout << "3) Quit the program\n";
        cin >> choice;

        switch (choice) {
            case 1:
             cout << "Enter length of side a: ";
             cin >> a;
             cout << "Enter length of side b: ";
             cin >> b;
             {
                double c = sqrt(a * a + b * b);
                double alpha = atan(a / b) * 180 / PI;
                double beta = 90.0 - alpha;

                cout << "Results: \n";
                cout << " Length of hypotenuse (c): " << c << endl;
                cout << " Angle of alpha in degrees: " << alpha << endl;
                cout << " Angle of beta in degrees: " << beta << endl;
             }
             break;

            case 2:
             cout << "Enter length of side a: ";
             cin >> a;
             cout << "Enter angle for alpha (in degrees): ";
             cin >> alpha;
             {
                double alphaRadians = alpha * PI / 180;
                double b = a / tan(alphaRadians);
                double c = sqrt(a * a + b * b);
                double beta = 90.0 - alpha;

                cout << "Results:\n";
                cout << "  Length of side b: " << b << endl;
                cout << "  Length of hypotenuse (c): " << c << endl;
                cout << "  Angle of beta in degrees: " << beta << endl;
             }
             break;

            case 3:
             break;

            default:
             cout << "Incorrect menu selection, please try again\n";
             break;

        }
    }
    


}