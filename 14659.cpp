#include <iostream>
using namespace std;
int main(){
    int n = 0;
    cin >> n;
    int* cal = new int[n];
    for(int i = 0; i < n; i++) cin >> cal[i];
    int prev = cal[0]; // 나의 높이
    int high = 0;
    int temp_cnt = 0;
    for(int i = 1; i < n; i++){
        if(cal[i] < prev) temp_cnt++;
        else{
            prev = cal[i];
            if(high < temp_cnt) high = temp_cnt;
            temp_cnt = 0;
        }
    }
    if(high < temp_cnt) high = temp_cnt;
    cout << high;
    return 0;
}