#include <iostream>
using namespace std;
int a[] = {0, 0};
void returnCnt(int target){
    if(target % 2 == 0){
        a[0]++;
        returnCnt(target / 2);
    }
    else if(target % 5 == 0){
        a[1]++;
        returnCnt(target / 5);
    }
}
int main(){
    int k = 0;
    cin >> k;
    for(int target = k; target > 1; target--){
        returnCnt(target);
    }
    if(a[0] < a[1]) cout << a[0];
    else cout << a[1];
    return 0;
}