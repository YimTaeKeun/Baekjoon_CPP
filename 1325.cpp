#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>* node_inform;
bool* visit;
// 노드 깊이 변수
int depth;
void bfs(int);
int main(){
    int node_cnt = 0, line_cnt = 0;
    cin >> node_cnt >> line_cnt;
    // 리프노드가 될 수 있는 가능성을 탐색하는 배열
    bool* is_parent = new bool[node_cnt + 1];
    node_inform = new vector<int>[node_cnt + 1];
    visit = new bool[node_cnt + 1];
    fill_n(is_parent, node_cnt + 1, true);
    fill_n(visit, node_cnt + 1, false);
    for(int i = 0; i < line_cnt; i++){
        int child = 0, parent = 0;
        cin >> child >> parent;
        // 부모 가능성 없으면 부모 가능성에서 제거
        is_parent[child] = false;
        node_inform[parent].push_back(child);
    }
    // ㄴ 노드 연결 완료
    // 탐색 시작
    vector<int> result_vector;
    int max_depth = 0;
    for(int i = 1; i <= node_cnt; i++){
        depth = 0;
        if(is_parent[i]){
            visit[i] = true;
            bfs(i);
            visit[i] = false;
            if(max_depth < depth){
            max_depth = depth;
            result_vector.clear();
            result_vector.push_back(i);
            }
            else if(max_depth == depth) result_vector.push_back(i);
        }
        
    }
    for(int i = 0; i < result_vector.size(); i++) cout << result_vector[i] << " ";
    return 0;
}
void bfs(int now_node){
    depth++;
    for(int i = 0; i < node_inform[now_node].size(); i++){
        visit[node_inform[now_node][i]] = true;
        bfs(node_inform[now_node][i]);
        visit[node_inform[now_node][i]] = false;
    }
}