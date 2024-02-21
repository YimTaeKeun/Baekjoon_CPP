#include <iostream>
using namespace std;
int* board;
int result = -1;
int nowPos = 0, toPos = 0;
int boardSize = 0;
bool* visit;
void bfs(int pos, int cnt, bool* check);
int main(){
    cin >> boardSize;
    board = new int[boardSize + 1];
    visit = new bool[boardSize + 1];
    fill_n(visit,boardSize + 1, false);
    for(int i = 1; i <= boardSize; i++) cin >> board[i];
    cin >> nowPos >> toPos;
    bfs(nowPos, 0, visit);
    cout << result;
    return 0;
}
void bfs(int pos, int cnt, bool* check){
    bool* tempCheck = new bool[boardSize + 1];
    fill_n(tempCheck, boardSize, false);
    for(int i = 1; i <= boardSize; i++) tempCheck[i] = check[i];
    if(pos == toPos){
        if(result == -1 || result > cnt) result = cnt;
        return;
    }
    for(int mul = 1; (pos + (mul * board[pos])) <= boardSize; mul++){
        if(!check[pos + (mul * board[pos])]){
            tempCheck[pos + (mul * board[pos])] = true;
            bfs(pos + (mul * board[pos]), cnt + 1, tempCheck);
        }
    }
    for(int mul = 1; (pos - (mul * board[pos])) >= 1; mul++){
        if(!check[pos - (mul * board[pos])]){
            tempCheck[pos - (mul * board[pos])] = true;
            bfs(pos - (mul * board[pos]), cnt + 1, tempCheck);
        }
    }
}