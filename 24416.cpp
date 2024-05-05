#include <iostream>
#include <queue>
using namespace std;
int main(){
    int target = 0;
    cin >> target;
    queue<long long> cal;
    cal.push(0);
    cal.push(1);
    for(long long i = 0; i < target - 1; i++){
        long long f = cal.front();
        cal.pop();
        cal.push(f + cal.front());
    }
    cout << cal.back() << " " << target - 2;
    return 0;
}