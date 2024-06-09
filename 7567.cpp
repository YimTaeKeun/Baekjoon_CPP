#include <iostream>
#include <string>
using namespace std;
int main(){
    int sum = 0;
    string cal;
    cin >> cal;
    char prev = 0;
    for(int i = 0; i < cal.size(); i++){
        char now = cal[i];
        if(i == 0){
            sum += 10;
            prev = now;
            continue;
        }
        sum += (prev != now) ? 10 : 5;
        prev = now;
    }
    cout << sum;
    return 0;
}