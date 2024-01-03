#include <iostream>
using namespace std;
int main(){
    for(int i = 0; i < 3; i++){
        long long sum = 0, flow = 0;
        int n = 0;
        cin >> n;
        for(int i = 0; i < n; i++){
            long long prev = sum;
            long long temp = 0;
            cin >> temp;
            sum += temp;
            if(temp > 0 && prev > 0 && sum < 0) flow++;
            else if(temp < 0 && prev < 0 && sum > 0) flow--;
            cout << sum << endl;
        }
        if(flow == 0){
            if(sum == 0) cout << 0;
            else if(sum > 0) cout << "+";
            else cout << "-";
        }
        else cout << (flow > 0 ? "+" : "-");
        cout << endl;
    }
}