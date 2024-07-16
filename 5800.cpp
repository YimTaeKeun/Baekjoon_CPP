#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
    int classCnt = 0;
    cin >> classCnt;
    for(int i = 1; i <= classCnt; i++){
        vector<int> cal;
        
        int n = 0;
        cin >> n;
        for(int j = 0; j < n; j++){
            int temp = 0;
            cin >> temp;
            cal.push_back(temp);
        }
        sort(cal.begin(), cal.end());
        int gap = 0;
        for(int j = 0; j < n - 1; j++){
            if(cal[j + 1] - cal[j] > gap) gap = cal[j + 1] - cal[j];
        }
        cout << "Class " << i << endl;
        cout << "Max " << cal[cal.size() - 1] << ", ";
        cout << "Min " << cal[0] << ", ";
        cout << "Largest gap " << gap << endl;
    }
    return 0;
}