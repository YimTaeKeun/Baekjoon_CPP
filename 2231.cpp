#include <iostream>
#include <string>
using namespace std;
int main(){
    int target = 0;
    cin >> target;
    long sum = 0;
    bool flag = true;
    int i = 1;
    for(; i <= target; i++){
        string generator = to_string(i);
        sum = i;
        for(int j = 0; j < generator.length(); j++){
            string temp = string(1, generator[j]);
            sum += stoi(temp);
        }
        if(sum == target) break; 
        else if(i == target) flag = false;
    }
    if(flag) cout << i << endl;
    else cout << 0 << endl;
    return 0;
}