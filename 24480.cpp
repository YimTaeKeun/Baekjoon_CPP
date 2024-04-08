#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool** node_info;
int* result_arr;
bool* visit;
int result = 0;
int node_cnt = 0;
void dfs(int);
int main(){
    int line_cnt = 0, start_point = 0;
    cin >> node_cnt >> line_cnt >> start_point;
    node_info = new bool*[node_cnt + 1];
    visit = new bool[node_cnt + 1];
    result_arr = new int[node_cnt + 1];
    fill_n(result_arr, node_cnt + 1, 0);
    fill_n(visit, node_cnt + 1, false);
    for(int i = 0; i <= node_cnt; i++){
        node_info[i] = new bool[node_cnt + 1];
        fill_n(node_info[i], node_cnt + 1, false);
    }
    for(int i = 0; i < line_cnt; i++){
        int a = 0, b = 0;
        cin >> a >> b;
        node_info[a][b] = true;
        node_info[b][a] = true;
    }
    visit[start_point] = true;
    dfs(start_point);
    for(int i = 1; i <= node_cnt; i++) cout << result_arr[i] << endl;
    return 0;
}
void dfs(int now_node){
    result_arr[now_node] = ++result;
    for(int i = node_cnt; i > 0; i--){
        if(node_info[now_node][i] && !visit[i]){
            visit[i] = true;
            dfs(i);
        }
    }
}