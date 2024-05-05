#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int stuff_cnt = 0, w_lim = 0;
    vector<int*> cal, dp;
    cin >> stuff_cnt >> w_lim;
    for(int i = 0; i < stuff_cnt; i++){
        int w = 0, v = 0;
        cin >> w >> v;
        cal.push_back(new int[2] {w, v});
    }
    sort(cal.begin(), cal.end(),
            [](int* first, int* second) -> int
        {
            return first[0] < second[0];
        });
    for(int i = 0; i < stuff_cnt; i++){
        if(dp.empty() && cal[i][0] <= w_lim){
            dp.push_back(cal[i]);
            continue;
        }
        if(cal[i][0] > w_lim) continue;
        
        int now_w = cal[i][0], now_v = cal[i][1], max_v = now_v, to_w = now_w;
        for(int j = dp.size() - 1; j >= 0; j--){
            if(now_w + dp[j][0] <= w_lim && max_v < now_v + dp[j][1]){
                to_w = now_w + dp[j][0];
                max_v = now_v + dp[j][1];
            }
        }
        dp.push_back(new int[2] {to_w, max_v});
        dp.push_back(cal[i]);
    }
    int max_v = 0;
    for(int i = 0; i < dp.size(); i++){
        if(max_v < dp[i][1]) max_v = dp[i][1];
    }
    cout << max_v << endl;
    //
    cout << endl;
    for(int i = 0; i < cal.size(); i++){
        cout << cal[i][0] << " " << cal[i][1] << endl;
    }
    cout << endl;
    for(int i = 0; i < dp.size(); i++){
        cout << dp[i][0] << " " << dp[i][1] << endl;
    }
    //
    return 0;
}