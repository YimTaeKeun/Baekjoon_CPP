#include <iostream>
using namespace std;
bool is_guem(int x);
int main(){
    int n = 0;
    cin >> n;
    for(int i = n; i >= 4; i--){
        if(is_guem(i)){
            cout << i;
            break;
        }
    }
    return 0;
}
bool is_guem(int x){
    while(x != 0){
        if(!(x % 10 == 4 || x % 10 == 7)) return false;
        x /= 10;
    }
    return true;
}