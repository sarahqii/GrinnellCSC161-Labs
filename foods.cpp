#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// Class to describe a food
class Food
{
private:
	string name;					// name
	string group;					// food group
	int calories;					// calories
	float percentage;				// daily percentage

public:

	// Constructors
	Food();
	Food(string, string, int, float);

	// Access functions
	string getName();
	void setName(string);
	string getGroup();
	void setGroup(string);
	int getCalories();
	void setCalories(int);
	void setPercentage(float);
	float getPercentage();

	// Print
	void print();
};

// Programmer-defined functions
void listFoods( vector<Food> );
void calorieFoods( vector<Food> );
void calorieList( vector<Food> );
void printHeader();

// Main program
int main()
{
	// Open file
	ifstream inFile;
	inFile.open("foods.txt", ios::in);

	// Check for error
	if( inFile.fail() )
	{
		cout << "Error opening input data file" << endl;
		exit(1);
	}

	// Stores foods
	vector<Food> foodList;

	// Read until end
	string name;
	string group;
	int calories;
	float percentage;
	while( inFile >> name >> group >> calories >> percentage )
	{
		// Create food class object
		Food food(name, group, calories, percentage);

		// Add to vector
		foodList.push_back(food);
	}

	// Close file
	inFile.close();

	// Loop until done
	bool done = false;
	while(!done)
	{
		// Display menu
		cout << endl;
		cout << "--------------" << endl;
		cout << "Food list menu" << endl;
		cout << "--------------" << endl;
		cout << "1) List food items" << endl;
		cout << "2) Compute total calories of all foods" << endl;
		cout << "3) List foods above an input calorie limit" << endl;
		cout << "4) Exit" << endl;
		cout << endl;

		// Prompt user
		cout << "Please enter a selection: ";
		int menuSelect;
		cin >> menuSelect;

		// Process menu selection
		switch(menuSelect)
		{
		case 1:			// Print food list
			listFoods( foodList );
			break;

		case 2:			// Compute total calories of all foods
			calorieFoods( foodList );
			break;

		case 3:			// List foods above an input calorie limit
			calorieList( foodList );
			break;

		case 4:			// Exit
			done = true;
			break;

		default:
			cout << "Please enter a valid menu selection" << endl;
		}
	}

	return 0;
}

// Class member function definitions
Food::Food()
{
	name = "";
	group = "";
	calories = 0;
	percentage = 0.0;
}
Food::Food(string n, string g, int c, float p)
{
	name = n;
	group = g;
	calories = c;
	percentage = p;
}
string Food::getName()
{
	return name;
}
void Food::setName(string s)
{
	name = s;
}
string Food::getGroup()
{
	return group;
}
void Food::setGroup(string s)
{
	group = s;
}
int Food::getCalories()
{
	return calories;
}
void Food::setCalories(int i)
{
	calories = i;
}
float Food::getPercentage()
{
	return percentage;
}
void Food::setPercentage(float f)
{
	percentage = f;
}
void Food::print()
{
	cout << setw(20) << std::left << name;
	cout << setw(20) << std::left << group;
	cout << setw(20) << std::left << calories;
	cout << setw(20) << std::left << percentage;
	cout << endl;
}

// Function to list all foods
void listFoods( vector<Food> foodList )
{
	printHeader();
	for(unsigned int i = 0; i < foodList.size(); ++i)
	{
		foodList[i].print();
	}
}

// Function to compute total calories of all foods
void calorieFoods( vector<Food> foodList )
{
	int calorieSum = 0;
	for(unsigned int i = 0; i < foodList.size(); ++i)
	{
		calorieSum += foodList[i].getCalories();
	}
	cout << "Food calorie sum: " << calorieSum << endl;
}

// Function to list foods above an input calorie limit
void calorieList( vector<Food> foodList )
{
	// Enter calorie limit
	int limit;
	cout << "Enter calorie limit: ";
	cin >> limit;

	// List foods above calorie limit
	cout << "Foods above calorie limit: " << limit << endl;
	printHeader();
	for(unsigned int i = 0; i < foodList.size(); ++i)
	{
		if( foodList[i].getCalories() > limit )
			foodList[i].print();
	}
}

// Function print food list header
void printHeader()
{
	cout << "============================================================================" << endl;
	cout << setw(20) << std::left << "Name";
	cout << setw(20) << std::left << "Food group";
	cout << setw(20) << std::left << "Calories";
	cout << setw(20) << std::left << "Daily percentage" << endl;
	cout << "============================================================================" << endl;
}
