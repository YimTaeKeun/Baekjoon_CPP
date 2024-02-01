#include <iostream>
#include <vector>
using namespace std;
int find(int);
void unionHuman(int, int);
int* board;
vector<vector<int>*> events;
int main(){
    int n = 0, eventCnt = 0;
    cin >> n >> eventCnt;
    board = new int[n + 1];
    for(int i = 0; i <= n; i++) board[i] = i;
    int truthCnt = 0;
    cin >> truthCnt;
    int temp = 0;
    for(int i = 0; i < truthCnt; i++){
        temp = 0;
        cin >> temp;
        unionHuman(0, temp);
    }
    int result = 0;
    for(int e = 0; e < eventCnt; e++){
        cin >> temp;
        bool truth = false;
        events.push_back(new vector<int>);
        for(int i = 0; i < temp; i++){
            int targetHuman = 0;
            cin >> targetHuman;
            (*events[e]).push_back(targetHuman);
            if(find(targetHuman) == 0 || truth){
                truth = true;
                unionHuman(0, targetHuman);
            }
        }
        if(truth){
            for(int i = 0; i < (*events[e]).size() - 1; i++) unionHuman((*events[e])[i], (*events[e])[i + 1]);
        }
    }
    for(int i = 0; i < eventCnt; i++){
        bool isContinue = false;
        vector<int> event = *events[i];
        for(int j = 0; j < event.size(); j++){
            if(find(event[j]) == 0){
                isContinue = true;
                break;
            }
        }
        if(!isContinue){ result++; cout << i << "event" <<endl;}
    }
    cout << result;
    return 0;
}
int find(int x){
    if(board[x] != x) return find(board[x]);
    return x;
}
void unionHuman(int x, int y){
    x = find(x);
    y = find(y);
    if(x != y) board[y] = x;
}