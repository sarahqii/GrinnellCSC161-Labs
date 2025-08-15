#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

class Food
{
public:
    string name;
    string foodGroup;
    int calories;
    double dailyPercentage;

    Food(string n, string fg, int c, double dp) : name(n), foodGroup(fg), calories(c), dailyPercentage(dp) {}
};

void listFoods(const vector<Food>& list) 
{
    cout << "============================================================================" << endl;
    cout << left << setw(20) << "Name" << setw(20) << "Food group" << setw(20) << "Calories" << setw(20) << "Daily percentage" << endl;
    cout << "============================================================================" << endl;

    for (size_t i = 0; i < list.size(); ++i) 
    {
        const Food& food = list[i];
        cout << left << setw(20) << food.name << setw(20) << food.foodGroup << setw(20) << food.calories << setw(20) << food.dailyPercentage << endl;
    }
}

void calorieFoods(const vector<Food>& list) 
{
    int totalCalories = 0;
    for (size_t i = 0; i < list.size(); ++i)
    {
        totalCalories += list[i].calories;
    }
    cout << "Food calorie sum: " << totalCalories << endl;
}

void calorieList(const vector<Food>& list) 
{
    int calorieLimit;
    cout << "Enter calorie limit: ";
    cin >> calorieLimit;

    cout << "Foods above calorie limit: " << calorieLimit << endl;
    cout << "============================================================================" << endl;
    cout << left << setw(20) << "Name" << setw(20) << "Food group" << setw(20) << "Calories" << setw(20) << "Daily percentage" << endl;
    cout << "============================================================================" << endl;

    for (size_t i = 0; i < list.size(); ++i)
    {
        const Food& food = list[i]; 
    {
        if (food.calories > calorieLimit) 
        {
            cout << left << setw(20) << food.name << setw(20) << food.foodGroup << setw(20) << food.calories << setw(20) << food.dailyPercentage << endl;
        }
    }
    }
}

int main() 
{
    vector<Food> foodList;
    char fileName[20] = "foods.txt";
	ifstream inFile( fileName );
    string name, foodGroup;
    int calories;
    double dailyPercentage;

    if (inFile.fail() )
    {
        exit(1);
    }

    while (inFile >> name >> foodGroup >> calories >> dailyPercentage)
    {
        foodList.emplace_back(name, foodGroup, calories, dailyPercentage);
    }

    inFile.close();

    int choice;
    bool done = false;
    while( !done )
    {
        cout << "--------------" << endl;
        cout << "Food list menu" << endl;
        cout << "--------------" << endl;
        cout << "1) List food items" << endl;
        cout << "2) Compute total calories of all foods" << endl;
        cout << "3) List foods above an input calorie limit" << endl;
        cout << "4) Exit" << endl;
        cout << "Please enter a selection: ";
        cin >> choice;

        switch (choice) 
        {
        case 1:
            listFoods(foodList);
            break;
        case 2:
            calorieFoods(foodList);
            break;
        case 3:
            calorieList(foodList);
            break;
        case 4:
            done = true;
            break;
        }
    }

    return 0;
}