#include <iostream>
#include <string>
#include <queue>
using namespace std;
int** board;
bool** visit;
int main(){
    int col = 0, row = 0;
    cin >> col >> row;
    board = new int*[col];
    visit = new bool*[col];
    string temp;
    for(int i = 0; i < col; i++){
        board[i] = new int[row];
        visit[i] = new bool[row];
        fill_n(visit[i], row, false);
        cin >> temp;
        for(int j = 0; j < row; j++) board[i][j] = temp[j] - '0';
    }
    //입력 완
    bool isType = false;
    visit[0][0] = true;
    queue<int*> bfsQ;
    int moveTo[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    bfsQ.push(new int[2] {0, 0});
    int i = 1;
    int result = 0;
    for(; ; i++){
        int size = bfsQ.size();
        for(int j = 0; j < size; j++){
            int* pos = bfsQ.front();
            bfsQ.pop();
            if(pos[0] == col - 1 && pos[1] == row - 1){
                cout << i << endl;
                return 0;
            }
            for(int m = 0; m < 4; m++){
                int movedC = moveTo[m][0] + pos[0];
                int movedR = moveTo[m][1] + pos[1];
                if(movedC >= 0 && movedC < col\
                && movedR >= 0 && movedR < row\
                && board[movedC][movedR] == 1 && !visit[movedC][movedR]){
                    bfsQ.push(new int[2] {movedC, movedR});
                    visit[movedC][movedR] = true;
                }
            }
        }
    }
    return 0;
}