#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n = 0, k = 0, temp = 0;
    cin >> n >> k;
    int sum = 0;
    vector<int> cal;
    for(int i = 0; i < n; i++){
        cin >> temp;
        cal.push_back(temp);
    }
    for(int i = 0; i < k; i++) sum += cal[i];
    int max = sum;
    for(int i = k; i < n; i++){
        sum -= cal[i - k];
        sum += cal[i];
        if(sum > max) max = sum;
    }
    cout << max << endl;
    return 0;
}
