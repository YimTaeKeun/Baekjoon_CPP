#include <iostream>
#include <string>
using namespace std;
int main(){
    string cal, binStr = "";
    cin >> cal;
    for(int i = 0; i < cal.size(); i++){
        binStr.clear();
        int data = cal[i] - '0';
        for(int j = 0; j < 3; j++) binStr = to_string((data >> j) & 1) + binStr;
        if(i == 0) cout << stoi(binStr);
        else cout << binStr;
    }
    return 0;
}