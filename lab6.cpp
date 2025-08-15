#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.14159;
double triangleArea(double base, double height)
{
    return 0.5 * base * height;
}
double rectangleArea(double length, double width)
{
    return length * width;
}
double circleArea(double radius)
{
    return PI * pow(radius, 2);
}

int main()
{
	bool done = false;
	while( !done )
	{
		cout << endl;
		cout << "=========================" << endl;
		cout << "Shape areas calculator" << endl;
		cout << "=========================" << endl;
		cout << "Please select an option from the menu below" << endl;
		cout << "1) Compute the area of a triangle" << endl;
		cout << "2) Compute the area of a rectangle" << endl;
		cout << "3) Compute the area of a circle" << endl;
        cout << "4) Quit the program" << endl;

		int menuItem;
		cin >> menuItem;

		double base, height, width, length, radius;

		switch(menuItem)
		{
		case 1:
			cout << "Enter base and height separated by a space: ";
			cin >> base >> height;
			cout << "Area of triangle: " << triangleArea(base, height) << endl;
			break;

		case 2:
			cout << "Enter length and width separated by a space: ";
			cin >> length >> width;
			cout << "Area of rectangle: " << rectangleArea(length, width) << endl;
			break;
        
        case 3:
            cout << "Enter radius: ";
			cin >> radius;
			cout << "Area of circle: " << circleArea(radius) << endl;
			break;

		case 4:
			done = true;
			break;

		default:
			cout << "Incorrect menu selection, please try again" << endl;
		}
	}

	return 0;
}



