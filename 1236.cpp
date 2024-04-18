#include <iostream>
#include <string>
using namespace std;
int main(){
    char** board;
    int row_cnt = 0, col_cnt = 0;
    cin >> row_cnt >> col_cnt;
    board = new char*[row_cnt];
    for(int i = 0; i < row_cnt; i++){
        board[i] = new char[col_cnt];
        string temp;
        cin >> temp;
        for(int j = 0; j < col_cnt; j++) board[i][j] = temp[j];
    }
    int result = 0;
    for(int pos = 0; pos < row_cnt; pos++){
        bool is_there = false;
        for(int c = pos; c < col_cnt; c++){
            if(board[pos][c] == 'X'){
                 is_there = true;
                 break;
            }
        }
        if(!is_there) result++;
        is_there = false;
        for(int r = pos; r < row_cnt; r++){
            if(board[r][pos] == 'X'){
                 is_there = true;
                 break;
            }
        }
        if(!is_there) result++;
    }
    cout << result;
    return 0;
}