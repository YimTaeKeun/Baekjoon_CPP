#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n = 0, k = 0, temp = 0;
    cin >> n >> k;
    vector<int> cal;
    for(int i = 0; i < n; i++){
        cin >> temp;
        cal.push_back(temp);
    }
    sort(cal.begin(), cal.end());
    cout << cal[n - k];
    return 0;
}