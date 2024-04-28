#include <iostream>
#include <cmath>
using namespace std;
bool is_pow(unsigned long long target);
int main(){
    long long g = 0;
    cin >> g;
    long long i = 1;
    bool is_there = false;
    while((i + 1) * (i + 1) - (i  * i) <= g){
        if(is_pow(i * i + g)){
            is_there = true;
            cout << (long long) sqrt(i * i + g) << endl;
        }
        i++;
    }
    if(!is_there) cout << -1 << endl;
    return 0;
}
bool is_pow(unsigned long long target){
    long long div = sqrt(target);
    if(target % div == 0 && target / div == div) return true;
    return false;
}