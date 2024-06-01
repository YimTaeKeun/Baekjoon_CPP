#include <iostream>
#include <string>
#include <map>
using namespace std;
int main(){
    map<char, char> m;
    m.insert(pair<char, char>('-', '|'));
    m.insert(pair<char, char>('|', '-'));
    m.insert(pair<char, char>('/', '\\'));
    m.insert(pair<char, char>('\\', '/'));
    m.insert(pair<char, char>('^', '<'));
    m.insert(pair<char, char>('<', 'v'));
    m.insert(pair<char, char>('v', '>'));
    m.insert(pair<char, char>('>', '^'));
    char** board;
    int row = 0, col = 0;
    string temp;
    cin >> row >> col;
    board = new char*[row];
    for(int r = 0; r < row; r++){
        board[r] = new char[col];
        cin >> temp;
        for(int c = 0; c < col; c++){
            if(m.find(temp[c]) == m.end()) board[r][c] = temp[c];
            else board[r][c] = m[temp[c]];
        }
    }
    for(int c = col - 1; c >= 0; c--){
        for(int r = 0; r < row; r++) cout << board[r][c];
        cout << endl;
    }
    return 0;
}