#include <iostream>
using namespace std;
int main(){
    int target = 0;
    cin >> target;
    int result = target / 5;
    while(result != 0){
        if((target - (result * 5)) % 2 == 0) break;
        result--;
    }
    if((target - (result * 5)) % 2 == 0) result += (target - (result * 5)) / 2;
    cout << ((result != 0) ? result : -1);
    return 0;
}