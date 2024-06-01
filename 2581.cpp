#include <iostream>
#include <cmath>
using namespace std;
bool isPrime(int);
int main(){
    int m = 0, n = 0, tot_sum = 0, re = 0;
    bool flag = false;
    cin >> m >> n;
    for(int i = m; i <= n; i++){
        if(isPrime(i)){
            if(!flag) re = i;
            flag = true;
            tot_sum += i;
        }
    }
    if(!flag) cout << -1 << endl;
    else{
        cout << tot_sum << endl;
        cout << re << endl;
    }
    return 0;
}
bool isPrime(int n){
    if(n == 1) return false;
    for(int i = 2; i <= (int) sqrt(n); i++){
        if(n % i == 0) return false;
    }
    return true;
}