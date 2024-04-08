#include <iostream>
using namespace std;
int** cal;
bool** visit;
int direction[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
bool is_movable(int, int, int);
int row = 0, col = 0;
int result = 0;
void dfs(int, int);
int main(){
    cin >> row >> col;
    cal = new int*[row];
    visit = new bool*[row];
    for(int r = 0; r < row; r++){
        cal[r] = new int[col];
        visit[r] = new bool[col];
        fill_n(visit[r], col, false);
        for(int c = 0; c < col; c++) cin >> cal[r][c];
    }
    // ㄴ 입력 완.
    // 가장 왼쪽 위 지점은 방문을 true로 해놓습니다.
    visit[0][0] = true;
    dfs(0, 0);
    cout << result;
    return 0;
}
bool is_movable(int r, int c, int now_h){
    if(!visit[r][c] && now_h > cal[r][c]) return true;
    return false;
}
void dfs(int r, int c){
    if(r == row - 1 && c == col - 1) result++;
    else{
        for(int d = 0; d < 4; d++){
            int movedR = r + direction[d][0];
            int movedC = c + direction[d][1];
            if(movedR >= 0 && movedR < row && movedC >= 0 && movedC < col && is_movable(movedR, movedC, cal[r][c])){
                visit[movedR][movedC] = true;
                dfs(movedR, movedC);
                visit[movedR][movedC] = false;
            }
        }
    }
}