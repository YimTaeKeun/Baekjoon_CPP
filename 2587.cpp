#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int sum = 0, temp = 0;
    vector<int> cal;
    for(int i = 0; i < 5; i++){
        cin >> temp;
        sum += temp;
        cal.push_back(temp);
    }
    sort(cal.begin(), cal.end());
    cout << sum / 5 << endl;
    cout << cal[2] << endl;
    return 0;
}