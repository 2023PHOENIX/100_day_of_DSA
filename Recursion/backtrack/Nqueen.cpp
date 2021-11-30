#include <bits/stdc++.h>
using namespace std;


bool isSafe(vector<vector<int>> &chess,int r,int c){

    // check row and column
    for (int i = r - 1; i >= 0;i--){
        if(chess[i][c]>0){
            return false;
        }
    }
    for (int i = r - 1, j = c - 1; j >= 0 and i >= 0;j--,i--){
        if(chess[i][j]>0)
            return false;
    }

    for (int i = r - 1, j = c + 1; j < chess.size() and i >= 0; j++,i--){
        if(chess[i][j]>0){
            return false;
        }
    }
    // check daigonal
    return true;
}

void printNQueens(vector<vector<int>> &chess, string qsf, int row)
{
    if(row ==chess.size()){
        cout << qsf << "." << endl;
        return;
    }
    int n = chess.size();
    for (int i = 0; i < n; i++)
    {
        if(isSafe(chess,row,i)){

        chess[row][i] = 1;
        printNQueens(chess, qsf +to_string(row) + "-" + to_string(i) + ", ", row + 1);
        chess[row][i] = 0;
        }
    }
    
    
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> chess(n, vector<int>(n));

    printNQueens(chess, "", 0);
}