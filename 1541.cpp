#include <iostream>
#include <string>
using namespace std;
int main(){
    string cal;
    cin >> cal;
    int pos = -1;
    string temp = "";
    bool isMinus = false;
    long long sum = 0;
    while(cal[++pos] != '\0'){
        if(cal.empty() && cal[pos] == '0') continue;
        if(cal[pos] == '+' || cal[pos] == '-'){
            long long num = stoll(temp);
            sum += (isMinus) ? -num : num;
            temp.clear();
        }
        else temp += cal[pos];
        if(cal[pos] == '-') isMinus = true;
    }
    long long numo = stoll(temp);
    sum += (isMinus) ? -numo : numo;
    cout << sum << endl;
    return 0;
}