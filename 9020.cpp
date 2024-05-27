#include <iostream>
#include <cmath>
using namespace std;
int gold(int);
bool isPrime(int);
int main(){
    int t = 0, n = 0, p = 0;
    cin >> t;
    for(int tc = 0; tc < t; tc++){
        cin >> n;
        p = gold(n);
        cout << p << " " << n - p << endl;
    }
    return 0;
}
int gold(int n){
    int from = n / 2;
    for(; from >= 2; from--){
        if(isPrime(from) && isPrime(n - from)) return from;
    }
    return from;
}
bool isPrime(int n){
    for(int i = 2; i <= (int) sqrt(n); i++){
        if(n % i == 0) return false;
    }
    return true;
}