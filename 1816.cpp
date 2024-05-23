#include <iostream>
#include <cmath>
using namespace std;
bool isKey(long long cal);
int main(){
    int n = 0;
    long long cal = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> cal;
        cout << (isKey(cal) ? "YES" : "NO") << endl;
    }
    return 0;
}
bool isKey(long long cal){
    long long lim = sqrt(cal);
    for(int i = 2; i <= 1000000; i++){
        if(cal % i == 0) return false;
    }
    return true;
}