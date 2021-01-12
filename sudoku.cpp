// A Backtracking program in
// C++ to solve Sudoku problem
#include <bits/stdc++.h>
using namespace std;

#define UNASSIGNED 0
#define N 9

bool FindUnassignedLocation(int grid[N][N],int& row, int& col);
bool isSafe(int grid[N][N], int row,int col, int num);


bool isValidSudoku(int board[][N])
{
    bool unique[N + 1];
    for (int i = 0; i < N; i++) {

        memset(unique, false,
               sizeof(unique));
        for (int j = 0; j < N;j++) {

            int Z = board[i][j];
            if (unique[Z]) {
                return false;
            }
            unique[Z] = true;
        }
    }
    for (int i = 0; i < N; i++) {
        memset(unique, false,
               sizeof(unique));
        for (int j = 0; j < N;j++) {
            int Z = board[j][i];
            if (unique[Z]) {
                return false;
            }
            unique[Z] = true;
        }
    }

    for (int i = 0; i < N - 2;
         i += 3) {

        for (int j = 0; j < N - 2;
             j += 3) {

            memset(unique, false,
                   sizeof(unique));


            for (int k = 0; k < 3;k++) {

                for (int l = 0; l < 3;l++) {

                    int X = i + k;
                    int Y = j + l;
                    int Z = board[X][Y];
                    if (unique[Z]) {
                        return false;
                    }
                    unique[Z] = true;
                }
            }
        }
    }

    return true;
}

bool SolveSudoku(int grid[N][N])
{
    int row, col;

    if (!FindUnassignedLocation(grid, row, col))
       {
        return true;
       }
    for (int num = 1; num <= 9; num++)
    {
        if (isSafe(grid, row, col, num))
        {


            grid[row][col] = num;


            if (SolveSudoku(grid))
                return true;


            grid[row][col] = UNASSIGNED;
        }
    }


    return false;
}

bool FindUnassignedLocation(int grid[N][N],
                            int& row, int& col)
{
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (grid[row][col] == UNASSIGNED)
                return true;
    return false;
}

bool UsedInRow(int grid[N][N], int row, int num)
{
    for (int col = 0; col < N; col++)
        if (grid[row][col] == num)
            return true;
    return false;
}

bool UsedInCol(int grid[N][N], int col, int num)
{
    for (int row = 0; row < N; row++)
        if (grid[row][col] == num)
            return true;
    return false;
}

bool UsedInBox(int grid[N][N], int boxStartRow,
               int boxStartCol, int num)
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (grid[row + boxStartRow][col + boxStartCol] == num)
                return true;
    return false;
}
bool isSafe(int grid[N][N], int row,
            int col, int num)
{

    return !UsedInRow(grid, row, num)
           && !UsedInCol(grid, col, num)
           && !UsedInBox(grid, row - row % 3,
                         col - col % 3, num)
           && grid[row][col] == UNASSIGNED;
}

void printGrid(int grid[N][N])
{
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
            cout << grid[row][col] << " ";
        cout << endl ;
    }
}

int main()
{
    int f=0;
    int grid[N][N];
    cout<<"Enter the elements for a 9x9 Matrix(input UNASSIGNED values as 0):\n";
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cin>>grid[i][j];

            if(grid[i][j]<0||grid[i][j]>9)
              {  cout<< "Invalid input";return 0;}
            if(grid[i][j]==0)
            {  f=1;  }

        }
    }
if(f==0){
if(isValidSudoku(grid))
{
cout<<"The given sudoku is complete and valid\n\n";
printGrid(grid);
}
else
{
cout<<"The given sudoku is complete but invalid\n\n";
printGrid(grid);
}
}
else{
    if (SolveSudoku(grid) == true)
        printGrid(grid);
    else
        cout << " \n No solution exists~\n";
    }
}













