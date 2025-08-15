#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int NUM_LINES = 10;

class Salary 
{
public:
    double base;
    double bonus;
    double deduction;
    double net;

    void computeNet() 
    {
        double deductionAmount = (base + bonus) * deduction;
        net = (base + bonus) - deductionAmount;
    }

    void printSalary() const 
    {
        cout << "Base, Bonus, Deduction, NetSalary:";
        cout.precision(9);
        cout << setw(9) << base;
        cout << setw(7) << bonus;
        cout << setw(6) << deduction;
        cout.setf(ios::fixed);
        cout.precision(2);
        cout << setw(12) << net;
        cout.unsetf(ios::fixed);
        cout << endl;
    }
};

int main() 
{
    char fileName[20] = "payroll.txt";
    ifstream inFile(fileName);
    if( inFile.fail() )
	{
		cout << "Error opening " << fileName << endl;
		exit(1);
	}

    Salary salaries[NUM_LINES];

    for (int i = 0; i < NUM_LINES; ++i) 
    {
        inFile >> salaries[i].base;

        inFile >> salaries[i].bonus;

        inFile >> salaries[i].deduction;

        salaries[i].computeNet();

        salaries[i].printSalary();
    }

    inFile.close();

    return 0;
}
