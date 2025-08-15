# include <iostream>
using namespace std;

int main ()
{
    int number;
    int evenCount = 0;
    int oddCount = 0;

    while (true)
    {
        cout << "Enter a positive integer (or negative integer to quit): ";
        cin >> number;

        if (number < 0)
        {
            break;
        }
        else
        {
            if (number % 2 == 0)
            {
                evenCount++;
            }
            else
            {
                oddCount++;
            }
        }
    }
    cout << "Number of even digits entered: " << evenCount << endl;
    cout << "Number of odd digits entered: " << oddCount << endl;

    return 0;
}