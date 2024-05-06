#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int tc = 0;
    cin >> tc;
    for(int t = 0; t < tc; t++){
        int board[10] = {0};
        for(int i = 0; i < 10; i++) cin >> board[i];
        sort(board, board + 10);
        cout << board[7] << endl;
    }
    return 0;
}