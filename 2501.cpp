#include <iostream>
using namespace std;
int main(){
    int target, k, i = 1;
    cin >> target >> k;
    for(i = 1; i <= target; i++){
        if(target % i == 0) k--;
        if(k == 0) break;
    }
    if(k != 0) cout << 0;
    else cout << i;
    return 0;
}