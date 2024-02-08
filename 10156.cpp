#include <iostream>
using namespace std;
int main(){
    int k = 0, n = 0, m = 0;
    cin >> k >> n >> m;
    if(k * n - m <= 0) cout << 0;
    else cout << k * n - m;
    return 0;
}