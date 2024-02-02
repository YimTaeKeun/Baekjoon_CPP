#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int boxCnt = 0;
    cin >> boxCnt;
    int result = 1;
    int* boxes = new int[boxCnt];
    int* dp = new int[boxCnt];
    for(int i = 0; i < boxCnt; i++) dp[i] = 1;
    for(int i = 0; i < boxCnt; i++) cin >> boxes[i];
    for(int i = 0; i < boxCnt; i++){
        for(int r = i - 1; r >= 0; r--){
            if(boxes[r] < boxes[i]){
                dp[i] = max(dp[i], dp[r] + 1);
                result = max(result, dp[i]);
            }
        }
    }
    cout << result;
    return 0;
}