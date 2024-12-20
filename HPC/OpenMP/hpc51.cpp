#include<omp.h>
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define N 10

void printSolution(int board[N][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			printf("%2d ", board[i][j]);
		printf("\n");
	}
}

/* A Optimized function to check if a queen can be placed on board[row][col] */
bool isSafe(int row, int col, int slashCode[N][N], int backslashCode[N][N], bool rowLookup[], bool slashCodeLookup[], bool backslashCodeLookup[] )
{
	if (slashCodeLookup[slashCode[row][col]] || backslashCodeLookup[backslashCode[row][col]] || rowLookup[row])
	  return false;

	return true;
}

/* A recursive utility function to solve N Queen problem */
bool solveNQueensUtil(int board[N][N], int col, int slashCode[N][N], int backslashCode[N][N],  bool rowLookup[N], bool slashCodeLookup[], bool backslashCodeLookup[] )
{
	/* base case: If all queens are placed then return true */
	if (col >= N)
		return true;

	/* Consider this column and try placing this queen in all rows one by one */
	for (int i = 0; i < N; i++)
	{
		/* Check if queen can be placed on board[i][col] */
		if ( isSafe(i, col, slashCode, backslashCode, rowLookup, slashCodeLookup, backslashCodeLookup) )
		{
			/* Place this queen in board[i][col] */
			board[i][col] = 1;
			rowLookup[i] = true;
			slashCodeLookup[slashCode[i][col]] = true;
			backslashCodeLookup[backslashCode[i][col]] = true;
			/* recur to place rest of the queens */
			if ( solveNQueensUtil(board, col + 1, slashCode, backslashCode, rowLookup, slashCodeLookup, backslashCodeLookup) )
				return true;
			/* If placing queen in board[i][col] doesn't lead to a solution, then backtrack */
			/* Remove queen from board[i][col] */
			board[i][col] = 0;
			rowLookup[i] = false;
			slashCodeLookup[slashCode[i][col]] = false;
			backslashCodeLookup[backslashCode[i][col]] = false;
		}
	}
	return false;
}


bool solveNQueens()
{
	int board[N][N];
	memset(board, 0, sizeof board);
	// helper matrices
	int slashCode[N][N];
	int backslashCode[N][N];
	// arrays to tell us which rows are occupied
	bool rowLookup[N] = {false};
	//keep two arrays to tell us 
	// which diagonals are occupied
	bool slashCodeLookup[2*N - 1] = {false};
	bool backslashCodeLookup[2*N - 1] = {false};
	// initialize helper matrices
	for (int r = 0; r < N; r++) 
		for (int c = 0; c < N; c++)
                {
		  slashCode[r] = r + c ;
		  backslashCode[r] = r - c + 7 ;
		}
	if (solveNQueensUtil(board, 0, slashCode, backslashCode, rowLookup, slashCodeLookup, backslashCodeLookup) == false )
	{
		printf("Solution does not exist");
		return false;
	}
	// solution found
	printSolution(board);
	return true;
}

int main()
{
	solveNQueens();
	return 0;
}
