#include <iostream>
#include <string>
using namespace std;
char findBomb(int col, int row);
char** board;
int n = 0;
int main(){
    cin >> n;
    board = new char*[n];
    char** resultBoard = new char*[n];
    for(int i = 0; i < n; i++){
        string temp;
        cin >> temp;
        board[i] = new char[n];
        for(int j = 0; j < n; j++) board[i][j] = temp[j];
    }
    for(int i = 0; i < n; i++){
        resultBoard[i] = new char[n];
        for(int j = 0; j < n; j++) resultBoard[i][j] = findBomb(i, j);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cout << resultBoard[i][j];
        cout << endl;
    }
    return 0;
}
char findBomb(int col, int row){
    if(board[col][row] != '.') return '*';
    else{
        int cnt = 0;
        for(int c = col - 1; c < col + 2; c++){
            if(c >= 0 && c < n){
                for(int r = row - 1; r < row + 2; r++){
                    if((r >= 0 && r < n) && board[c][r] != '.'){
                        string te = string(1, board[c][r]);
                        cnt += stoi(te);
                    }
                }
            }
        }
        if(cnt >= 10) return 'M';
        else return to_string(cnt)[0];
    }
}