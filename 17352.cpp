#include <iostream>
using namespace std;
int* nodes;
int find(int);
void union_arr(int, int);
int main(){
    int nodeCnt = 0;
    cin >> nodeCnt;
    // nodes에는 node 번호에 따름. nodes[0]은 사용하지 않음
    nodes = new int[nodeCnt + 1];
    for(int i = 0; i <= nodeCnt; i++) nodes[i] = i;
    for(int i = 0; i < nodeCnt - 2; i++){
        int x = 0, y = 0;
        cin >> x >> y;
        union_arr(x, y);
    }
    // 입력 완.
    bool exit = false;
    for(int i = 1; i <= nodeCnt - 1; i++){
        for(int j = i + 1; j <= nodeCnt; j++){
            if(find(i) != find(j)){
                cout << i << " " << j;
                exit = true;
                break;
            }
        }
        if(exit) break;
    }
    return 0;
}
int find(int x){
    // 해당 노드의 값을 최상위 부모노드로 변경
    if(x != nodes[x]) return nodes[x] = find(nodes[x]);
    return x;
}
void union_arr(int x, int y){
    x = find(x);
    y = find(y);
    if(x != y) nodes[y] = x;
}
