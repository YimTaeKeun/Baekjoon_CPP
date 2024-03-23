#include <iostream>
using namespace std;
bool union_arr(int, int);
int find(int);
int* board;
int* rank_;
int main(){
    int node_cnt = 0, cmd_cnt = 0;
    cin >> node_cnt >> cmd_cnt;
    board = new int[node_cnt];
    rank_ = new int[node_cnt];
    fill_n(rank_, node_cnt, 1);
    for(int i = 0; i < node_cnt; i++) board[i] = i;
    bool result = false;
    int result_int = 0;
    for(int i = 0; i < cmd_cnt; i++){
        int one = 0, two = 0;
        cin >> one >> two;
        if(result) continue;
        result = union_arr(one, two);
        if(result) result_int = i + 1;
    }
    cout << ((result) ? result_int : 0);
    return 0;
}
int find(int x){
    if(board[x] != x) return board[x] = find(board[x]);
    return x;
}
bool union_arr(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return true;
    if(rank_[x] > rank_[y]){
        board[y] = x;
        rank_[x] += rank_[y];
    }
    else{
        board[x] = y;
        rank_[y] += rank_[x];
    }
    return false;
    
}