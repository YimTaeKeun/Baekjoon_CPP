#include <iostream>
#include <string>
using namespace std;
bool** board;
void turn(int, int);
int main(){
    int col = 0, row = 0;
    cin >> col >> row;
    board = new bool*[col];
    string temp;
    for(int i = 0; i < col; i++){
        board[i] = new bool[row];
        cin >> temp;
        for(int j = 0; j < row; j++) board[i][j] = temp[j] - '0';
    }
    int result = 0;
    for(int c = col - 1; c >= 0; c--){
        for(int r = row - 1; r >= 0; r--){
            if(board[c][r]){
                result++;
                turn(c, r);
            }
        }
    }
    cout << result;
    return 0;
}
void turn(int c, int r){
    for(int i = 0; i <= c; i++){
        for(int j = 0; j <= r; j++) board[i][j] = !board[i][j];
    }
}