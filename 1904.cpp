#include <iostream>
#include <queue>
using namespace std;
int main(){
    queue<long long> dp;
    dp.push(1);
    dp.push(1);
    long long target = 0;
    cin >> target;
    if(target == 1) cout << 1;
    else{
        for(int i = 2; i <= target; i++){
            long long data = dp.front();
            dp.pop();
            dp.push((dp.front() + data) % 15746);
        }
        cout << dp.back();
    }
    return 0;
}