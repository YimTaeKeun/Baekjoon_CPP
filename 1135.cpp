#include <iostream>
using namespace std;
int main(){
    int n = 0, temp = 0;
    int maxValue = 0;
    cin >> n;
    int* board = new int[n];
    for(int i = 0; i < n; i++){
        cin >> temp;
        if(temp == -1){
            board[i] = 1;
            continue;
        }
        board[i] = board[temp] + 1;
        if(board[i] > maxValue) maxValue = board[i];
    }
    cout << maxValue << endl;
    return 0;
}