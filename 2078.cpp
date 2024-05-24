#include <iostream>
using namespace std;
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int L = 0, R = 0;
    int lCnt = 0, rCnt = 0;
    cin >> L >> R;
    while(!(L == 1 && R == 1)){
        if(L == 1){
            rCnt += R - 1;
            break;
        }
        else if(R == 1){
            lCnt += L - 1;
            break;
        }
        if(L > R){
            lCnt++;
            L -= R;
        }
        else{
            rCnt++;
            R -= L;
        }
    }
    cout << lCnt << " " << rCnt << endl; 
    return 0;
}