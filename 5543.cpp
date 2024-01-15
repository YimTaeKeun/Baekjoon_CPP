#include <iostream>
using namespace std;
int main(){
    int hamburger = 2000, baverage = 2000;
    for(int i = 0; i < 3; i++){
        int temp = 0;
        cin >> temp;
        if(hamburger > temp) hamburger = temp;
    }
    for(int i = 0; i < 2; i++){
        int temp = 0;
        cin >> temp;
        if(baverage > temp) baverage = temp;
    }
    cout << hamburger + baverage - 50<< endl;
    return 0;
}