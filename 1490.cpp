#include <iostream>
#include <cmath>
using namespace std;
long long gcd(long long, long long);
long long lcm(long long, long long);
int main(){
    unsigned long long N = 0;
    cin >> N;
    unsigned long long temp = N;
    long long div = 1;
    while(temp != 0){
        if(temp % 10 != 0) div = lcm(div, temp % 10);
        temp /= 10;
    }
    int k = 1;
    do{
        if(N % div == 0) break;
        N *= 10;
        if(N % div == 0) break;
        if((div - (N % div)) < pow(10, k)){
            N += div - (N % div);
            break;
        }
        k++;
    }while(true);
    cout << N << endl;
    return 0;
}
long long gcd(long long a, long long b){
    if(b == 0) return a;
    return gcd(b, a % b);
}
long long lcm(long long a, long long b){
    return a * b / gcd(a, b);
}