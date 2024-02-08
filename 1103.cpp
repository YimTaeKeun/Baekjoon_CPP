#include <iostream>
#include <queue>
#include <string>
using namespace std;
int** board;
int** dp;
bool** visited;
int col = 0, row = 0;
void initiallize();
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> col >> row;
    string temp;
    board = new int*[col];
    dp = new int*[col];
    visited = new bool*[col];
    initiallize();
    for(int i = 0; i < col; i++){
        cin >> temp;
        board[i] = new int[row];
        for(int j = 0; j < row; j++){
            if(temp[j] == 'H') board[i][j] = 0;
            else board[i][j] = temp[j] - '0';
        }
    }

    queue<int*> bfsQueue;
    bfsQueue.push(new int[2] {0, 0});
    while(!bfsQueue.empty()){
        // cout << "Start: " << endl;
        int s = bfsQueue.size();
        for(int i = 0; i < s; i++){
            int* nowPos = bfsQueue.front();
            int posC = nowPos[0], posR = nowPos[1];
            // cout << posC << " " << posR << endl;
            int nowDp = dp[posC][posR], nowData = board[posC][posR];
            bfsQueue.pop();
            int whereYouGo[4][2] = {{nowData, 0}, {0, nowData}, {-nowData, 0}, {0, -nowData}};
            for(int j = 0; j < 4; j++){
                int wentC = posC + whereYouGo[j][0], wentR = posR + whereYouGo[j][1];
                if(wentC < col && wentC >= 0 && wentR < row && wentR >= 0 && board[wentC][wentR] != 0){
                    if(visited[wentC][wentR]){
                        cout << -1;
                        return 0;
                    }
                    else{
                        visited[wentC][wentR] = true;
                        dp[wentC][wentR] = nowDp + 1;
                        bfsQueue.push(new int[2] {wentC, wentR});
                    }
                }
            }
        }
    }
    int result = 1;
    for(int i = 0; i < col; i++){
        for(int j = 0; j < row; j++){
            if(result < dp[i][j]) result = dp[i][j];
        }
    }
    cout << result;
    return 0;
}
void initiallize(){
    for(int i = 0; i < col; i++){
        dp[i] = new int[row];
        visited[i] = new bool[row];
        fill_n(dp[i], row, 0);
        fill_n(visited[i], row, false);
    }
    dp[0][0] = 1;
    visited[0][0] = true;
}