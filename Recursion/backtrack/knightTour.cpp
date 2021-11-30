#include<iostream>
#include<vector>

using namespace std;

void display(vector<vector<int>> &chess){

    for (int i = 0; i < chess.size(); i++){
        for (int j = 0; j < chess[i].size(); j++){
            cout << chess[i][j] << " ";
        }
        cout << endl;
    }
        cout << endl;
}
void KnightsTour(vector<vector<int>> &chess, int r, int c, int upcomingMove)
{

    /* base cases */
    if(r<0 or c<0 or r>=chess.size() or c >= chess.size() or chess[r][c]!=0){
        return;
    }
    else if(upcomingMove==chess.size() * chess.size()){
        chess[r][c] = upcomingMove;
        display(chess);
        chess[r][c] = 0;
        return; 
    }
    // recursive case
    chess[r][c] = upcomingMove;
    KnightsTour(chess, r - 2, c + 1, upcomingMove + 1);
    KnightsTour(chess, r - 1, c + 2, upcomingMove + 1);
    KnightsTour(chess, r + 1, c + 2, upcomingMove + 1);
    KnightsTour(chess, r + 2, c + 1, upcomingMove + 1);
    KnightsTour(chess, r + 2, c - 1, upcomingMove + 1);
    KnightsTour(chess, r + 1, c - 2, upcomingMove + 1);
    KnightsTour(chess, r - 1, c - 2, upcomingMove + 1);
    KnightsTour(chess, r - 2, c - 1, upcomingMove + 1);
    chess[r][c] = 0;
}

int main(){

    int n;
    cin >> n;

    int r, c;
    cin >> r >> c;
    vector<vector<int>> chess(n, vector<int>(n, 0));
    KnightsTour(chess, r, c, 1);
}