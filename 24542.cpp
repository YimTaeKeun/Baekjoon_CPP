#include <iostream>
using namespace std;
void union_arr(int, int);
int find(int);
int* rank_;
int* board;
int main(){
    int node_cnt = 0, cmd_cnt = 0;
    cin >> node_cnt >> cmd_cnt;
    rank_ = new int[node_cnt + 1];
    board = new int[node_cnt + 1];
    fill_n(rank_, node_cnt + 1, 1);
    for(int i = 0; i <= node_cnt; i++) board[i] = i;
    for(int i = 0; i < cmd_cnt; i++){
        int one = 0, two = 0;
        cin >> one >> two;
        union_arr(one, two);
    }
    long long result = 1;
    bool* visit = new bool[node_cnt + 1];
    fill_n(visit, node_cnt + 1, false);
    for(int i = 1; i <= node_cnt; i++){
        int temp = find(i);
        if(!visit[temp]){
            visit[temp] = true;
            result = (result * rank_[temp]) % 1000000007;
        }
    }
    cout << result;
    return 0;
}
int find(int x){
    if(board[x] != x) return board[x] = find(board[x]);
    return x;
}
void union_arr(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(rank_[x] > rank_[y]){
        board[y] = x;
        rank_[x] += rank_[y];
    }
    else{
        board[x] = y;
        rank_[y] += rank_[x];
    }
}