#include <iostream>
#include <string>
#include <queue>
using namespace std;
int row_cnt = 0, col_cnt = 0;
char** board;
bool** visit;
bool is_movable(int, int);
int goto_arr[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
void bfs(int, int, int* sheep_cnt, int* wolf_cnt);
int main(){
    int tot_sheep = 0, tot_wolf = 0;
    cin >> row_cnt >> col_cnt;
    board = new char*[row_cnt];
    visit = new bool*[row_cnt];
    string temp;
    for(int i = 0; i < row_cnt; i++){
        board[i] = new char[col_cnt];
        visit[i] = new bool[col_cnt];
        fill_n(visit[i], col_cnt, false);
        cin >> temp;
        for(int j = 0; j < col_cnt; j++) board[i][j] = temp[j];
    }
    for(int i = 0; i < row_cnt; i++){
        for(int j = 0; j < col_cnt; j++){
            int sheep_cnt = 0, wolf_cnt = 0;
            if(board[i][j] != '#' && !visit[i][j]){
                visit[i][j] = true;
                bfs(i, j, &sheep_cnt, &wolf_cnt);
            }
            if(sheep_cnt > wolf_cnt) tot_sheep += sheep_cnt;
            else tot_wolf += wolf_cnt;
        }
    }
    cout << tot_sheep << " " << tot_wolf;
    return 0;
}
void bfs(int row, int col, int* sheep_cnt, int* wolf_cnt){
    // 주의: 주소를 받아옴 
    queue<int*> q;
    q.push(new int[2] {row, col});
    while(!q.empty()){
        int* now_pos = q.front();
        q.pop();
        int nowR = now_pos[0], nowC = now_pos[1];
        if(board[nowR][nowC] == 'v') (*wolf_cnt)++;
        else if(board[nowR][nowC] == 'o') (*sheep_cnt)++;
        for(int m = 0; m < 4; m++){
            int movedR = nowR + goto_arr[m][0], movedC = nowC + goto_arr[m][1];
            if(is_movable(movedR, movedC)){
                visit[movedR][movedC] = true;
                q.push(new int[2] {movedR, movedC});
            }
        }
    }
}
bool is_movable(int row, int col){
    if(row >= 0 && row < row_cnt && col >= 0 && col < col_cnt && board[row][col] != '#' && !visit[row][col]){
        return true;
    }
    return false;
}