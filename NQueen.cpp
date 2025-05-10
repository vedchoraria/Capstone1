#include <iostream>
using namespace std;

int board[20][20]; // Chessboard
int N;

// Function to print the solution
void printSolution() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << (board[i][j] ? "Q " : ". ");
        }
        cout << endl;
    }
    cout << endl;
}

// Function to check if it's safe to place a queen at board[row][col]
bool isSafe(int row, int col) {
    // Check column
    for (int i = 0; i < row; i++)
        if (board[i][col])
            return false;

    // Check upper-left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 , j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check upper-right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++)
        if (board[i][j])
            return false;

    return true;
}

// Recursive function to solve N-Queens
bool solveNQueen(int row) {
    if (row == N) {
        printSolution();
        return true; // Change to false if you want all solutions
    }

    bool res = false;
    for (int col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            board[row][col] = 1;
            res = solveNQueen(row + 1)|| res; 
            board[row][col] = 0; // backtrack
        }
    }

    return res;
}

int main() {
    cout << "Enter the number of queens: ";
    cin >> N;

    // Initialize board
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            board[i][j] = 0;

    if (!solveNQueen(0))
        cout << "No solution exists for " << N << " queens." << endl;

    return 0;
}
