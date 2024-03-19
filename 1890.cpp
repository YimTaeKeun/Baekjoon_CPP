#include <iostream>
#include <vector>
using namespace std;
int** board;
void dfs_board(int*);
long result{ 1 };
int board_size{ 0 };
int main(){
    cin >> board_size;
    board = new int*[board_size];
    for(int i = 0; i < board_size; i++){
        board[i] = new int[board_size];
        for(int j = 0; j < board_size; j++) cin >> board[i][j];
    }

    dfs_board(new int[2] {0, 0});
    cout << result;
    return 0;
}
void dfs_board(int* pos){
    int c = pos[0], r = pos[1];
    int value = board[c][r];
    if(value == 0) return;
    // cout << "H";
    int move[2][2] = {{0, value}, {value, 0}};
    bool isThere = false;
    for(int i = 0; i < 2; i++){
        int movedCol = c + move[i][0];
        int movedRow = r + move[i][1];
        if(movedCol < board_size && movedRow < board_size){
            if(!isThere) isThere = true;
            else result++;
            dfs_board(new int[2] {movedCol, movedRow});
        }
    }
}