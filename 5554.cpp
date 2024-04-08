#include <iostream>
using namespace std;
int main(){
    int s = 0, temp = 0;
    for(int i = 0; i < 4; i++){
        cin >> temp;
        s += temp;
    }
    cout << s / 60 << endl;
    cout << s % 60;
    return 0;
}