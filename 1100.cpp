#include <iostream>
using namespace std;
int main(){
    bool is_white = true;
    string cal;
    int result = 0;
    for(int i = 0; i < 8; i++){
        cin >> cal;
        for(int j = 0; j < 8; j++){
            if(is_white && cal[j] == 'F') result++;
            is_white = !is_white;
        }
        is_white = !is_white;
    }
    cout << result;
    return 0;
}