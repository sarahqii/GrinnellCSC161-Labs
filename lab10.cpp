#include <iostream>
using namespace std;

class MultiplicationTable
{
    private:
      int table[5][5];
      int minVal;
      int maxVal;

    public:
      MultiplicationTable()
      {
        fillTable();
        findMinMax();
      }
      void fillTable()
      {
        for (int i = 0; i < 5; ++i)
        {
            for (int j = 0; j < 5; ++j)
            {
                table[i][j] = (i + 1) * (j + 1);
            }
        }
      }
      void findMinMax()
      {
        minVal = table[0][0];
        maxVal = table[4][4];
      }
      void printTable()
      {
        cout << "Multiplication Table:\n";
        cout << "minimun value: " << minVal << endl;
        cout << "maximum value: " << maxVal << endl;
        for (int i = 0 ; i <5; ++i)
        {
            for (int j = 0; j < 5; ++j)
            {
                cout << table [i][j] << "\t";
            }
            cout << endl;
        }
      }
      void setValue(int row, int col, int value) 
      {
        if (row >= 0 && row < 5 && col >= 0 && col < 5) 
        {
            table[row][col] = value;
            findMinMax();
        }
      }
      int getValue(int row, int col) 
      {
        if (row >= 0 && row < 5 && col >= 0 && col < 5) 
        {
          return table[row][col];
        }
        return -1;
      }
};
      void findMatch(MultiplicationTable mt, int valueToFind)
      {
        bool found = false;
        for (int i = 0; i < 5; ++i)
        {
          for (int j = 0; j < 5; ++j)
          {
            if (mt.getValue(i, j) == valueToFind)
            {
                cout << valueToFind << " found in table at row, col: " << i << ", " << j << endl;
                found = true;
            }
          }
        }
        if (!found) 
        {
        cout << valueToFind << " not found in table\n";
        }
    }

int main()
{
    MultiplicationTable mt;
    mt.printTable();
    
    int value;
    cout << "Enter a value in the multiplication table: ";
    cin >> value;
    
    findMatch(mt, value);
    
    return 0;
}