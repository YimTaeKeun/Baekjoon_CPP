#include <iostream>
#include <cmath>
using namespace std;
int row{ 0 }, col{ 0 };
int main(){
    cin >> col >> row;
    int pos[2] = {0, -1};
    int move[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int moveMode = 0;
    int totalCnt = row * col;
    int wr = 0, wc = 0;
    int cnt = 0;
    while(cnt != totalCnt){
        pos[0] = pos[0] + move[moveMode][0] * (row - wr);
        pos[1] = pos[1] + move[moveMode][1] * (col - wc);
        if(move[moveMode][0] != 0) wc++;
        else wr++;
        cnt += abs(move[moveMode][0] * (row - wr)) + abs(move[moveMode][1] * (col - wc));
        moveMode++;
        if(moveMode == 4) moveMode = 0;
    }
    cout << pos[1] << " " << pos[0];
    return 0;
}