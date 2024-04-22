#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    vector<int> cal;
    int apple_cnt = 0, len = 0;
    cin >> apple_cnt >> len;
    for(int i = 0; i < apple_cnt; i++){
        int temp = 0;
        cin >> temp;
        cal.push_back(temp);
    }
    sort(cal.begin(), cal.end());
    for(int i = 0; i < cal.size(); i++){
        if(cal[i] <= len){
            len++;
        }
    }
    cout << len;
    return 0;
}