#include <iostream>
using namespace std;
int main(){
    int caseNum = 1;
    while(true){
        int l = 0, p = 0, v = 0;
        int result = 0;
        cin >> l >> p >> v;
        if(l == 0 && p == 0 && v == 0) break;
        while(v > 0){
            if(v <= l){
                result += v;
                break;
            }
            result += l;
            v -= p;
        }
        cout << "Case " << caseNum++ << ": " << result << endl;
    }
    return 0;
}