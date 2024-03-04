#include <iostream>
using namespace std;
int main(){
    int n = 0;
    cin >> n;
    int* dayArr = new int[n];
    int* moneyArr = new int[n];
    long long* dp = new long long[n];
    long long result = 0;
    fill_n(dp, n, 0);
    for(int i = 0; i < n; i++){
        cin >> dayArr[i];
        cin >> moneyArr[i];
    }
    for(int i = 0; i < n; i++){
        if(i + dayArr[i] <= n){
            if(dp[i] < moneyArr[i]) dp[i] = moneyArr[i];
            long cnt = i + dayArr[i];
            for(int j = cnt; j < n; j++){
                if(dp[j] < moneyArr[j] + dp[i] && j + dayArr[j] <= n) dp[j] = moneyArr[j] + dp[i];
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(result < dp[i]) result = dp[i];
    }
    cout << result << endl;
    return 0;
}