#define LOCAL
#define N 8
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int matrix[N][N];
int count = 0;

void print()
{
	for (int i = 0; i < N; i ++) {
		for (int j = 0; j < N; j ++) {
			if (matrix[i][j]) cout << "Q ";
			else cout << "0 ";
		}
		cout << endl;
	}
}

bool isSafe(int row, int column)
{
	int i, j;
	if (row == 1) return true;
	for(i = 0; i < row - 1; i ++)
		if (matrix[i][column - 1])
			return false;
	for (i = row - 2, j = column - 2; i >= 0 && j >= 0; i --, j --)
		if (matrix[i][j])
			return false;
	for (i = row - 2, j = column; i >= 0 && j < N; i--, j++)
		if (matrix[i][j])
			return false;
	return true;
}

void solutions(int row)
{
	for (int i = 0; i < N; i++) {
		
		if (isSafe(row, i + 1)) {	
			matrix[row - 1][i] = 1;
			if (row == N) {
				cout << "Puzzle " << ++ count   << ":" << endl << endl;
				print();
				cout << endl << endl;
			}
			else solutions(row + 1);	
			matrix[row - 1][i] = 0;
		}	
		
	}
}

int main() 
{
	#ifdef LOCAL
	freopen("eightqueens.out", "w", stdout);
	#endif

	memset(matrix, 0, sizeof(int) * N * N);
	solutions(1);
	return 0;
}
