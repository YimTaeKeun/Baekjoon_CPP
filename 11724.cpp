#include <iostream>
using namespace std;
int* nodes;
void unionArr(int, int);
int find(int);
int main(){
    int nodeCnt = 0, cmdCnt = 0;
    cin >> nodeCnt >> cmdCnt;
    nodes = new int[nodeCnt + 1];
    bool* isVisit = new bool[nodeCnt + 1];
    fill_n(isVisit, nodeCnt + 1, false);
    int result = 0;
    for(int i = 0; i <= nodeCnt; i++) nodes[i] = i;
    for(int i = 0; i < cmdCnt; i++){
        int one = 0, two = 0;
        cin >> one >> two;
        unionArr(one, two);
    }
    for(int i = 1; i <= nodeCnt; i++){
        if(!isVisit[find(i)]){
            isVisit[find(i)] = true;
            result++;
        }
    }
    cout << result;
    return 0;
}
void unionArr(int x, int y){
    int fx = find(x);
    int fy = find(y);
    if(x != fx && y != fy){
        unionArr(fx, fy);
    }
    else if(fx != fy) nodes[fy] = fx;
}
int find(int x){
    if(nodes[x] != x)
        return find(nodes[x]);
    return x;
}