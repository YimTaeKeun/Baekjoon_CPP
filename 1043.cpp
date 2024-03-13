#include <iostream>
using namespace std;
int find(int);
void union_arr(int, int);
int* cal;
int** commands;
int main(){
    // union-find
    int peopleCnt = 0, commandCnt = 0, know = 0;
    cin >> peopleCnt >> commandCnt;
    cal = new int[peopleCnt + 1];
    commands = new int*[commandCnt];
    for(int i = 0; i <= peopleCnt; i++) cal[i] = i;
    cin >> know;
    for(int i = 0; i < know; i++){
        int a = 0;
        cin >> a;
        cal[a] = 0;
    }
    for(int i = 0; i < commandCnt; i++){
        int cnt = 0;
        cin >> cnt;
        commands[i] = new int[cnt + 1];
        commands[i][0] = cnt;
        for(int j = 1; j <= cnt; j++) cin >> commands[i][j];
        for(int j = 1; j <= cnt - 1; j++) union_arr(commands[i][j], commands[i][j + 1]);
    }
    int result = 0;
    for(int c = 0; c < commandCnt; c++){
        for(int r = 1; r <= commands[c][0]; r++){
            if(find(commands[c][r]) == 0){
                result++;
                break;
            }
        }
    }
    cout << commandCnt - result;
    return 0;
}
int find(int x){
    if(cal[x] != x) return find(cal[x]);
    return x;
}
void union_arr(int x, int y){
    x = find(x);
    y = find(y);
    if(x == 0) cal[y] = 0;
    else if(y == 0) cal[x] = 0;
    else if(x != y) cal[y] = x;
}