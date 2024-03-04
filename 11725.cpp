#include <iostream>
using namespace std;
bool** nodes;
int nodeCnt = 0;
int* parents;
void bfs(int);
int main(){
    cin >> nodeCnt;
    nodes = new bool*[nodeCnt + 1];
    parents = new int[nodeCnt + 1];
    for(int i = 0; i <= nodeCnt; i++){
        nodes[i] = new bool[nodeCnt + 1];
        fill_n(nodes[i], nodeCnt + 1, false);
    }
    for(int i = 0; i < nodeCnt - 1; i++){
        int one = 0, two = 0;
        cin >> one >> two;
        nodes[one][two] = true;
        nodes[two][one] = true;
    }
    parents[1] = -1;
    bfs(1);
    for(int each = 2; each <= nodeCnt; each++) cout << parents[each] << endl;
    return 0;
}
void bfs(int par){
    for(int i = 1; i <= nodeCnt; i++){
        if(nodes[par][i] && parents[i] == 0){
            parents[i] = par;
            bfs(i);
        }
    }
}