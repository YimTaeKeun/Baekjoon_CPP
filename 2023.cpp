#include <iostream>
#include <cmath>
using namespace std;
bool isPrime(int);
void printPrime(int, int);
int num_n = 0;
int main(){
    cin >> num_n;
    int cal = 0;
    printPrime(0, 0);
    return 0;
}
void printPrime(int n, int cnt){
    for(int i = 1; i <= 9; i++){
        if(cnt == num_n){
            cout << n << endl;
            return;
        }
        if(isPrime(10 * n + i)){
            printPrime(10 * n + i, cnt + 1);
        }
    }
}
bool isPrime(int n){
    if(n == 1) return false;
    for(int i = 2; i <= (int) sqrt(n); i++){
        if(n % i == 0) return false;
    }
    return true;
}