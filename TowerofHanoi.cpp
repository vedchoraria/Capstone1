// #include<iostream>
// using namespace std;
// #include<stack>
// // A : source rod, B : destination rod, C : auxiliary rod
// void TowerofHanoi(int n,char source, char des, char aux){
//     if(n==0) return;
//     if(n==1){
//         cout<<"Move disk 1 from "<<source<<" to "<<des<<endl;
//         return;
//     }
//     else{
//         TowerofHanoi(n-1,source,aux,des);
//         cout<<"Move disk "<<n<<" from "<<source<<" to "<<des<<endl;
//         TowerofHanoi(n-1,aux,des,source);
//     }
// }
// int main(){
//     int n;
//     cout<<"Enter the number of disks: ";
//     cin>>n;
//     char source = 'A', des = 'B', aux = 'C';
//     TowerofHanoi(n,source,des,aux);
//     return 0;
// }


#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col, int n) {
    // Check this column on upper side
    for (int i = 0; i < row; i++)
        if (board[i][col])
            return false;

    // Check upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check upper right diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQueen(vector<vector<int>>& board, int row, int n) {
    if (row == n) {
        // Solution found, print it
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << (board[i][j] ? "Q " : ". ");
            cout << endl;
        }
        cout << endl;
        return false; // Change to false if you want all solutions
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 1;
            if (solveNQueen(board, row + 1, n))
                return true;
            board[row][col] = 0; // Backtrack
        }
    }
    return false;
}

int main() {
    int n;
    cout << "Enter the value of N: ";
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n, 0));

    if (!solveNQueen(board, 0, n))
        cout << "No solution exists for N = " << n << endl;

    return 0;
}
