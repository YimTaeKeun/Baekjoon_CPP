#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    bool** is_there_water = new bool*[n + 1];
    int** dp = new int*[n + 1];
    for(int i = 0; i <= n; i++){
        is_there_water[i] = new bool[m + 1];
        dp[i] = new int[m + 1];
        for(int j = 0; j <= m; j++){
            fill_n(is_there_water[i], m + 1, false);
            fill_n(dp[i], m + 1, 0);
        }
    }
    for(int i = 0; i < puddles.size(); i++){
        is_there_water[puddles[i][0]][puddles[i][1]] = true;
    }
    // 웅덩이까지 조사 완료.
    dp[1][1] = 1;
    int c = 1, r = 1;
    while(true){
        // 스타트 포인트 선정 완.
        int col = c, row = r;
        while(col > 0 && row <= m){
            if(is_there_water[col][row] || (col == 1 && row == 1)){
                col--;
                row++;
                continue;
            }
            // 포인트(채워질 곳) 선정 완료
            int up = 0, left = 0;
            if(col != 1) up = dp[col - 1][row];
            if(row != 1) left = dp[col][row - 1];
            dp[col][row] = (up + left) % 1000000007;
            col--;
            row++;
        }
        //---------
        cout << c << " " << r << endl;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++) cout << dp[i][j] << " ";
            cout << endl;
        }
        cout << endl;
        //---------
        if(c == n){
            if(r == m) break;
            r++;
        }
        else c++;
    }
    return dp[n][m];
        
}
int main(){
    vector<vector<int>> nums;
    vector<int> num;
    num.push_back(2);
    num.push_back(2);
    nums.push_back(num);

    vector<int> num2;
    num2.push_back(2);
    num2.push_back(3);
    nums.push_back(num2);
    cout << solution(4, 3, nums);
    return 0;
}