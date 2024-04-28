#include <iostream>
#include <string>
#include <queue>
using namespace std;
int goto_arr[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; 
void bfs(int, int, char**, bool**);
bool is_valid_pos(int, int, char**, bool**);
int row_cnt = 0, col_cnt = 0;
int main(){
    int tc = 0;
    cin >> tc;
    for(int t = 0; t < tc; t++){
        cin >> row_cnt >> col_cnt;
        char** board = new char*[row_cnt];
        bool** visit = new bool*[row_cnt];
        for(int r = 0; r < row_cnt; r++){
            board[r] = new char[col_cnt];
            visit[r] = new bool[col_cnt];
            fill_n(visit[r], col_cnt, false);
            string temp;
            cin >> temp;
            for(int c = 0; c < col_cnt; c++) board[r][c] = temp[c];
        }
        int result = 0;
        for(int r = 0; r < row_cnt; r++){
            for(int c = 0; c < col_cnt; c++){
                if(board[r][c] == '#' && !visit[r][c]){
                    result++;
                    bfs(r, c, board, visit);
                }
            }
        }
        cout << result << endl;
        for(int r = 0; r < row_cnt; r++){
            delete[] board[r];
            delete[] visit[r];
        }
    }
    return 0;
}

void bfs(int row, int col, char** board, bool** visit){
    queue<int*> q;
    q.push(new int[2] {row, col});
    visit[row][col] = true;
    while(!q.empty()){
        int* nowPos = q.front();
        q.pop();
        int nowR = nowPos[0], nowC = nowPos[1];
        for(int m = 0; m < 4; m++){
            int movedR = nowR + goto_arr[m][0], movedC = nowC + goto_arr[m][1];
            if(is_valid_pos(movedR, movedC, board, visit)){
                visit[movedR][movedC] = true;
                q.push(new int[2] {movedR, movedC});
            }
        }
    }
}
bool is_valid_pos(int row, int col, char** board, bool** visit){
    if(row >= 0 && row < row_cnt && col >= 0 && col < col_cnt && board[row][col] == '#' && !visit[row][col]){
        return true;
    }
    return false;
}