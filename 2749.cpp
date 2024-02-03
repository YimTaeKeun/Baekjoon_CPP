#include <iostream>
#include <queue>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    queue<long long> calQueue;
    calQueue.push(1);
    calQueue.push(1);
    long long target = 0;
    cin >> target;
    if(target == 1) cout << 1;
    else{
        for(long long i = 2; i <= target; i++){
            long long t = calQueue.front();
            calQueue.pop();
            calQueue.push((t + calQueue.front()) % 1000000);
        }
        cout << calQueue.front() << endl;
    }
    return 0;
}