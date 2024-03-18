#include <iostream>
#include <string>
using namespace std;
int main(){
    string dayName[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int m = 0, d = 0;
    cin >> m >> d;
    long long sum = 0;
    for(int i = 1; i < m; i++) sum += days[i];
    sum += d;
    sum--;
    cout << dayName[sum % 7];
    return 0;
}