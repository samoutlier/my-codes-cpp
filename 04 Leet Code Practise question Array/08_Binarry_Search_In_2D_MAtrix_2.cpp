// Binary Search IN 2D Array

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int row , col, pos1 = -1, pos2 = -1 ;
    cout << "Enter The Number Of Rows And Columns respectively : ";
    cin >> row>> col;
    cout << "Enter The ELements Of Array : " << endl;
    int arr[row][col], target;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << "Enter The Element To Search : ";
    cin >> target;
     int rowIndex = 0;
     int ColIndex = col-1; 
    while(rowIndex<row && ColIndex>=0)
    {
        int element = arr[rowIndex][ColIndex];
        if(element==target)
        {
            pos1 = rowIndex;
            pos2 = ColIndex;
            break;
        }
        else if(element < target)
        {
            rowIndex++;
        }
        else
        {
            ColIndex--;
        }

    }
    cout<<"Position of "<<target<<" is : "<<pos1<<" "<<pos2;


    return 0;
}

