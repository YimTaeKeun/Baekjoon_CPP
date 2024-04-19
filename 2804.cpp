#include <iostream>
using namespace std;
int findChar(string a, char target);
int main(){
    string a, b;
    cin >> a >> b;
    // A기준 B문자 탐색
    char** board = new char*[b.size()];
    for(int i = 0; i < b.size(); i++){
        board[i] = new char[a.size()];
        fill_n(board[i], a.size(), '.');
    }
    int aIdx = 0, bIdx = 0;
    for(aIdx = 0; aIdx < a.size(); aIdx++){
        char target = a[aIdx];
        bIdx = findChar(b, target);
        if(bIdx != -1) break;
    }
    for(int i = 0; i < a.size(); i++){
        board[bIdx][i] = a[i];
    }
    for(int i = 0; i < b.size(); i++){
        board[i][aIdx] = b[i];
    }
    for(int r = 0; r < b.size(); r++){
        for(int c = 0; c < a.size(); c++) cout << board[r][c];
        cout << endl; 
    }
    return 0;
}
int findChar(string a, char target){
    for(int i = 0; i < a.size(); i++){
        if(a[i] == target) return i;
    }
    return -1;
}
