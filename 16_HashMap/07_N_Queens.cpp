#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <stack>
using namespace std;

void addSolution(vector<vector<char>> &board, vector<vector<string>> &ans, int n)
{
    vector<string> temp;

    for (int i = 0; i < n; i++)
    {
        string s = "";
        for (int j = 0; j < n; j++)
        {
            s.push_back(board[i][j]);
        }
        temp.push_back(s);
    }
    ans.push_back(temp);
}

bool safe(int row, int col, vector<vector<char>> &board, int n)
{
    cout << "CHECKING " << row << " " << col << endl;
    // CHECKING in PREVIOUS COLUMNS
    for (int i = col - 1; i >= 0; i--)
    {
        if (board[row][i] == 'Q')
        return false;
    }

    // CHECKING PREVIOUS UPPER DIAGONALS

    for (int i = 1; row - i >= 0 && col - i >= 0; i++)
    {
        if (board[row - i][col - i] == 'Q')
            return false;
    }

     // CHECKING PREVIOUS LOWER DIAGONALS

    for (int i = 1; row + i < n && col - i >= 0; i++)
    {
        if (board[row + i][col - i] == 'Q')
            return false;
    }
    return true;
}

void Solve(int col, vector<vector<string>> &ans, vector<vector<char>> &board, int n)
{

    if (col == n)
    {
        addSolution(board, ans, n);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (safe(row, col, board, n))
        {
            board[row][col] = 'Q';
            Solve(col + 1, ans, board, n);
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<char>> board(n, vector<char>(n, '.'));
    vector<vector<string>> ans;
    string path = "";
    Solve(0, ans, board, n);
    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<string>> ans = solveNQueens(n);

    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}