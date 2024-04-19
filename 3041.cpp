#include <iostream>
#include <string>
#include <cmath>
using namespace std;
void originPos(int* r, int* c, char);
int main(){
    long long result = 0;
    for(int r = 0; r < 4; r++){
        string temp;
        cin >> temp;
        for(int c = 0; c < 4; c++){
            // 현재 위치
            if(temp[c] == '.') continue;
            int origin_r = 0, origin_c = 0;
            originPos(&origin_r, &origin_c, temp[c]);
            result += abs(origin_r - r) + abs(origin_c - c);
        }
    }
    cout << result;
    return 0;
}
void originPos(int* r, int* c, char target){
    *r = (target - 'A') / 4;
    *c = (target - 'A') % 4;
}