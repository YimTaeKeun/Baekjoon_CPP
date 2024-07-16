#include <iostream>
using namespace std;
int main(){
    int tc = 0;
    cin >> tc;
    for(int t = 0; t < tc; t++){
        int dist = 0;
        int row = 0, col = 0;
        cin >> row >> col;
        int** board = new int*[row];
        int* boxCnt = new int[col];
        for(int i = 0; i < row; i++){
            board[i] = new int[col];
            fill_n(board[i], col, 0);
            for(int j = 0; j < col; j++){
                int temp = 0;
                cin >> temp;
                if(temp == 1) boxCnt[j]++;
                board[i][j] = temp;
            }
        }
        for(int i = row - 1; i >= 0; i++){
            for(int j = 0; j < col; j++){
                if(board[i][j] == 1){
                    dist += (row - i) - j;
                }
            }
        }
    }
    return 0;
}