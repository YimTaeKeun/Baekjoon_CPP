#include <iostream>
using namespace std;
int main(){
    long long target = 0, startNum = 0;
    cin >> target >> startNum;
    bool isTrue = true;
    long long cnt = 1;
    while(startNum > target){
        if(startNum % 2 == 0){
            startNum /= 2;
            cnt++;
        }
        else if(startNum % 10 != 1){
            isTrue = false;
            break;
        }
        else{
            startNum--;
            startNum /= 10;
            cnt++;
        }
    }
    if(!isTrue || startNum < target) cout << -1;
    else cout << cnt;
    return 0;
}