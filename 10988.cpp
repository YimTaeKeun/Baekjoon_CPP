#include <iostream>
#include <string>
using namespace std;
int main(){
    string target;
    cin >> target;
    int half = target.length() / 2;
    bool is_pal = true;
    for(int i = 0; i < half; i++){
        if(target[i] != target[target.length() - 1 - i]){
            is_pal = false;
            break;
        }
    }
    cout << ((is_pal) ? 1 : 0);
    return 0;
}