#include <iostream>
#include <fstream>
using namespace std;

struct Salary
{
    int baseSalary;
    int bonus;
    double percentageDeduction;
    double netSalary;
};

void computeNet(Salary &salary);
void printSalary(Salary salary);

int main ()
{
    ifstream inputFile("payroll.txt");

    if (!inputFile) 
    {
        cerr << "Error: Could not open the file." << endl;
        return 1;
    }

    Salary salaries[10];
    for (int i = 0; i < 10; ++i) 
    {
        inputFile >> salaries[i].baseSalary >> salaries[i].bonus >> salaries[i].percentageDeduction;
        computeNet(salaries[i]);
    }

    inputFile.close();

    for (int i = 0; i < 10; ++i) 
    {
        printSalary(salaries[i]);
    }

    return 0;
}

void computeNet(Salary &salary) 
{
    double deduction = (salary.baseSalary + salary.bonus) * (salary.percentageDeduction);
    salary.netSalary = (salary.baseSalary + salary.bonus) - deduction;
}

void printSalary(Salary salary)
{
    cout << "Base, Bonus, Deduction, NetSalary: "
              << fixed << setprecision(2)
              << salary.baseSalary << "   "
              << salary.bonus << "   "
              << salary.percentageDeduction << "   "
              << salary.netSalary << endl;
}