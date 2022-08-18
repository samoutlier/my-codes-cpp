#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

bool isValid(vector<vector<char>> &board, char c, int row, int col)
{
    for (int i = 0; i < 9; i++)
    {
        if ((board[i][col] == c) || (board[row][i] == c))
            return false;

        int newrow = 3 * (row / 3) + i / 3;
        int newcol = 3 * (col / 3) + i % 3;
        if ((newrow != row && newcol != col) && board[newrow][newcol] == c)
            return false;
    }
    return true;
}

bool solveSudoku(vector<vector<char>> &board)
{

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            // CHecking if cell is empty pr filled
            if (board[i][j] == '.')
            {
                for (char c = '1'; c <= '9'; c++)
                {

                    // checking if c is possible solution at that place
                    if (isValid(board, c, i, j))
                    {
                        board[i][j] = c;

                        bool check = solveSudoku(board);
                        if (check)
                            return true;
                        else
                        {
                            // BACKTRACKING
                            board[i][j] = '.';
                        }
                    }
                }
                return false;
            }
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

    bool ans = solveSudoku(board);

    cout << "SUDOKU SOLVES ->> " << endl;

    for (auto i : board)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}