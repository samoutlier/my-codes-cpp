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

bool safe(int row, int col, vector<vector<char>> &board, int n, map<int, bool> &rowcheck, map<int, bool> &lowerdiagonal, map<int, bool> &upperdiagonal)
{
    cout << "CHECKING " << row << " " << col << endl;
    // CHECKING in PREVIOUS COLUMNS
    if (rowcheck[row])
        return false;

    // CHECKING PREVIOUS UPPER DIAGONALS

    if (upperdiagonal[n - 1 + col - row])
        return false;

    // CHECKING PREVIOUS LOWER DIAGONALS

    if (lowerdiagonal[col + row])
        return false;
    return true;
}

void Solve(int col, vector<vector<string>> &ans, vector<vector<char>> &board, int n, map<int, bool> &rowcheck, map<int, bool> &lowerdiagonal, map<int, bool> &upperdiagonal)
{

    if (col == n)
    {
        addSolution(board, ans, n);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (safe(row, col, board, n, rowcheck, lowerdiagonal, upperdiagonal ))
        {
            board[row][col] = 'Q';
            rowcheck[row] = true;
            lowerdiagonal[row + col] = true;
            upperdiagonal[n - 1 + col - row] = true;
            Solve(col + 1, ans, board, n, rowcheck, lowerdiagonal, upperdiagonal);
            board[row][col] = '.';

            rowcheck[row] = false;
            lowerdiagonal[row + col] = false;
            upperdiagonal[n - 1 + col - row] = false;
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<char>> board(n, vector<char>(n, '.'));
    vector<vector<string>> ans;
    map<int, bool> rowcheck;
    map<int, bool> upperdiagonal;
    map<int, bool> lowerdiagonal;
    string path = "";
    Solve(0, ans, board, n, rowcheck, lowerdiagonal, upperdiagonal);
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