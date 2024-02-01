#include <iostream>
#include <queue>
using namespace std;
void dfs(int);
void bfs(int);
bool** board;
bool* visit;
int nodeCnt = 0;
queue<int> bfsQueue;
int main(){
    int eventCnt = 0, startPoint = 0;
    cin >> nodeCnt >> eventCnt >> startPoint;
    board = new bool*[nodeCnt + 1];
    for(int i = 0; i <= nodeCnt; i++) board[i] = new bool[nodeCnt + 1] {false, };
    for(int i = 0; i < eventCnt; i++){
        int one = 0, two = 0;
        cin >> one >> two;
        board[one][two] = true;
        board[two][one] = true;
    }
    visit = new bool[nodeCnt + 1] {false, };
    dfs(startPoint);
    cout << endl;
    visit = new bool[nodeCnt + 1] {false, };
    bfsQueue.push(startPoint);
    bfs(startPoint);
    cout << endl;
    return 0;
}
void dfs(int startPoint){
    visit[startPoint] = true;
    cout << startPoint << " ";
    for(int i = 1; i <= nodeCnt; i++){
        if(board[startPoint][i] && !visit[i]) dfs(i);
    }
}
void bfs(int startPoint){
    while(true){
        int size = bfsQueue.size();
        if(size == 0) break;
        for(int i = 0; i < size; i++){
            int data = bfsQueue.front();
            visit[data] = true;
            cout << data << " ";
            bfsQueue.pop();
            for(int j = 1; j <= nodeCnt; j++){
                if(board[data][j] && !visit[j]){
                    visit[j] = true;
                    bfsQueue.push(j);
                }
            }
            
        }
    }
}