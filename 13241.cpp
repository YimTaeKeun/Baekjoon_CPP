#include <iostream>
using namespace std;
long long result(long long a, long long b);
long long gcd(long long a, long long b);
int main(){
    long long a = 0, b = 0;
    cin >> a >> b;
    cout << result(a, b);
    return 0;
}
long long gcd(long long a, long long b){
    if(b == 0) return a;
    return gcd(b, a % b);
}
long long result(long long a, long long b){
    return a * b / gcd(a, b);
}