#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void bfs(int mother);
bool** board;
bool* visit;
int cntMax = 0;
int n = 0;
int cnt = 1;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> resultElems;
    int lineCnt = 0;
    cin >> n >> lineCnt;
    board = new bool*[n + 1];
    visit = new bool[n + 1];
    bool* isParent = new bool[n + 1];
    fill_n(isParent, n + 1, true);
    for(int i = 0; i <= n; i++){
         board[i] = new bool[n + 1];
         fill_n(board[i], n + 1, false);
    }
    for(int i = 0; i < lineCnt; i++){
        int mother = 0, child = 0;
        cin >> child >> mother;
        isParent[child] = false;
        board[mother][child] = true;
    }
    for(int i = 1; i <= n; i++){
        cnt = 1;
        if(isParent[i]){
            fill_n(visit, n + 1, false);
            visit[i] = true;
            bfs(i);
        }
        if(cnt > cntMax){
            cntMax = cnt;
            resultElems.clear();
            resultElems.push_back(i);
        }
        else if(cnt == cntMax) resultElems.push_back(i);
    }
    for(int i = 0; i < resultElems.size(); i++){
        cout << resultElems[i] << " ";
    }
    return 0;
}
void bfs(int mother){
    queue<int> children;
    for(int i = 1; i <= n; i++){
        if(board[mother][i] && !visit[i]){
            visit[i] = true;
            children.push(i);
        }
    }
    int size = children.size();
    for(int i = 0; i < size; i++){
        cnt++;
        int data = children.front();
        children.pop();
    }
    while(!children.empty()){
        cnt++;
        int data = children.front();
        children.pop();
        bfs(data);
    }
}