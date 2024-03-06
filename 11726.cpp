#include <iostream>
#include <queue>
using namespace std;
int main(){
    queue<long long> cal;
    cal.push(1);
    cal.push(2);
    int n = 0;
    cin >> n;
    if(n == 1 || n == 2) cout << n;
    else{
        for(int i = 0; i < n - 2; i++){
            long long temp = cal.front();
            cal.pop();
            cal.push((cal.front() + temp) % 10007);
        }
        cout << cal.back() << endl;
    }
    return 0;
}