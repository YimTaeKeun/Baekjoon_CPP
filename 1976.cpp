#include <iostream>
using namespace std;
void union_arr(int, int);
int find(int);
int* rank_;
int* board;
int main(){
    int node_cnt = 0, cmd_cnt = 0;
    cin >> node_cnt >> cmd_cnt;
    board = new int[node_cnt + 1];
    rank_ = new int[node_cnt + 1];
    fill_n(rank_, node_cnt, 1);
    for(int i = 0; i <= node_cnt; i++) board[i] = i;
    for(int i = 1; i <= node_cnt; i++){
        for(int j = 1; j <= node_cnt; j++){
            int temp = 0;
            cin >> temp;
            if(temp == 0) continue;
            union_arr(i, j);
        }
    }
    int a = 0;
    cin >> a;
    int compare = find(a);
    bool is_true = true;
    for(int i = 1; i < cmd_cnt; i++){
        cin >> a;
        if(compare != find(a)){
            is_true = false;
            break;
        }
    }
    if(is_true) cout << "YES";
    else cout << "NO";
    return 0;
}
int find(int x){
    if(board[x] != x) return board[x] = find(board[x]);
    return x;
}
void union_arr(int x, int y){
    x = find(x);
    y = find(y);
    if(rank_[x] > rank_[y]){
        board[y] = x;
        rank_[x] += rank_[y];
    }
    else{
        board[x] = y;
        rank_[y] += rank_[x];
    }
}