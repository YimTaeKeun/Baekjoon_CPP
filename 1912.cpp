#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int* board;
    long long* sumBoard;
    int cnt = 0;
    cin >> cnt;
    board = new int[cnt];
    sumBoard = new long long[cnt];
    for(int i = 0; i < cnt; i++) cin >> board[i];
    long long sum = 0;
    for(int i = 0; i < cnt; i++){
        sum += board[i];
        sumBoard[i] = sum;
    }
    long long maxNum = sumBoard[0];
    for(int i = 0; i < cnt; i++){
        long long target = sumBoard[i];
        if(target > maxNum) maxNum = target;
        for(int j = 0; j < i; j++){
            if(target - sumBoard[j] > maxNum) maxNum = target - sumBoard[j];
        }
    }
    cout << maxNum;
    return 0;
}