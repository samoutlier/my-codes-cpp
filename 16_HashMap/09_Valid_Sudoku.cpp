#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

bool isValid(vector<vector<char>> &board, char c, int row, int col)
{
    for (int i = 0; i < 9; i++)
    {
        if ((i != row && board[i][col] == c) || (i != col && board[row][i] == c))
            return false;

        int newrow = 3 * (row / 3) + i / 3;
        int newcol = 3 * (col / 3) + i % 3;
        if ((newrow != row && newcol != col)   && board[newrow][newcol] == c)
            return false;
    }
    return true;
}

bool isValidSudoku(vector<vector<char>> &board)
{

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] != '.' && !isValid(board, board[i][j], i, j))
            {
                cout << "False at " << i << " " << j << endl;
                return false;
            }
            // else
            // {
            //     "checked"<<
            // }
        }
    }
    return true;
}

// 5 3 . . 7 . . . .
// 6 . . 1 9 5 . . .
// . 9 8 . . . . 6 .
// 8 . . . 6 . . . 3
// 4 . . 8 . 3 . . 1
// 7 . . . 2 . . . 6
// . 6 . . . . 2 8 .
// . . . 4 1 9 . . 5
// . . . . 8 . . 7 9

// 5 3 . . 7 . . . . 
// 6 . . 1 9 5 . . .
// . 9 8 . . . . 6 .
// 8 . . . 6 . . . 3
// 4 . . 8 . 3 . . 1
// 7 . . . 2 . . . 6
// . 6 . . . . 2 8 .
// . . . 4 1 9 . 8 5
// . . . . 8 . . 7 9

//TC : O(9 ^m) m is empty cells;
// SC : O(1)

int main()
{
    vector<vector<char>> board(9);
    char data;

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> data;
            board[i].push_back(data);
        }
    }

    cout << isValidSudoku(board);
    return 0;
}