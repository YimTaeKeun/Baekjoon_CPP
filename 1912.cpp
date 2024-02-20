#include <iostream>
#include <cmath>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long* board;
    long long* dp;
    int cnt = 0;
    cin >> cnt;
    board = new long long[cnt];
    dp = new long long[cnt];
    for(int i = 0; i < cnt; i++) cin >> board[i];
    dp[0] = board[0];
    long long maxNum = board[0];
    for(int i = 1; i < cnt; i++){
        dp[i] = max(dp[i - 1] + board[i], board[i]);
        if(dp[i] > maxNum) maxNum = dp[i];
    }
    cout << maxNum;
    return 0;
}