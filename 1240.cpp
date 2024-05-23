#include <iostream>
using namespace std;
int* uf_board;
int* distance_arr;
int find(int x);
void union_arr(int x, int y);
int main(){
    int nodeCnt = 0, searchCnt = 0;
    cin >> nodeCnt >> searchCnt;
    uf_board = new int[nodeCnt + 1];
    distance_arr = new int[nodeCnt + 1];
    fill_n(distance_arr, nodeCnt + 1, 0);
    for(int i = 0; i <= nodeCnt; i++) uf_board[i] = i;
    for(int i = 0; i < nodeCnt - 1; i++){
        int p_node = 0, c_node = 0, distance = 0;
        cin >> p_node >> c_node >> distance;
        union_arr(p_node, c_node);
    }
    return 0;
}
int find(int x){
    if(uf_board[x] != x) return find(uf_board[x]);
    return x;
}
void union_arr(int x, int y){
    x = find(x);
    y = find(y);
    if(x != y){
        uf_board[y] = x;
    }
}