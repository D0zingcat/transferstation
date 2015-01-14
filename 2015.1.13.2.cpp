#include <iostream>
#include <memory.h>
#define N 9
#define UNASSIGNED 0
using namespace std;
bool isSafe(int grid[N][N], int row, int col, int num);
bool FindUnassignedLocations(int grid[N][N], int &row, int &col);
bool SolveSudoku(int grid[N][N]);
bool isInRow(int grid[N][N], int row, int num);
bool isInCol(int grid[N][N], int col, int num);
bool isInBox(int grid[N][N], int startRow, int startCol, int num);
void printGrid(int grid[N][N]);
int main()
{
    int grid[N][N];
    memset(grid, 0, sizeof(int) * N * N);
    for (int i = 0; i < N; i ++)
        for (int j = 0; j < N; j ++)
            cin >> grid[i][j];
    SolveSudoku(grid) == true ? cout << "Success!" << endl : cout << "Fail!" << endl;
    return 0;
}

void printGrid(int grid[N][N])
{
    for (int row = 0; row < N; row ++) {
        for (int col = 0; col < N; col ++)
            cout << " " << grid[row][col] << " ";
        cout << endl;
    }
    return;
}

bool isInRow(int grid[N][N], int row, int num)
{
    for (int i = 0; i < N; i ++)
        if (grid[row][i] == num)
            return true;
    return false;
}

bool isInCol(int grid[N][N], int col, int num)
{
    for (int i = 0; i < N; i ++)
        if (grid[i][col] == num)
            return true;
    return false;
}

bool isInBox(int grid[N][N], int startRow, int startCol, int num)
{
    for (int i = 0; i < 3; i ++)
        for (int j = 0; j < 3; j++)
            if (grid[i + startRow][j + startCol] == num)
                return true;
    return false;
}

bool isSafe(int grid[N][N], int row, int col, int num)
{
    return (!isInRow(grid, row, num) &&
            !isInCol(grid, col, num) &&
            !isInBox(grid, row - row % 3, col - col % 3, num));
}

bool FindUnassignedLocations(int grid[N][N], int &row, int &col)
{
    for (row = 0; row < N; row ++)
        for (col = 0; col < N; col ++)
            if (grid[row][col] == UNASSIGNED)
                return true;
    return false;
}

bool SolveSudoku(int grid[N][N])
{
    int row, col;
    if (!FindUnassignedLocations(grid, row, col))
    {
        printGrid(grid);
        return true;
    }
    else
    {
        for (int num = 1; num <= 9; num ++) {
            if (isSafe(grid, row, col, num)) {
                grid[row][col] = num;
                if (SolveSudoku(grid)) return true;
                grid[row][col] = UNASSIGNED;
            }
        }

    }
    return false;
}
