#include <iostream>
#include <string>
using namespace std;
int main(){
    int len = 0;
    cin >> len;
    string cal, temp = "";
    cin >> cal;
    long long result = 0;
    for(int i = 0; i < len; i++){
        if(cal[i] - '0' >= 0 && cal[i] - '0' <= 9){
            temp += cal[i];
        }
        else if(temp.size() > 0){
            result += stoi(temp);
            temp = "";
        }
    }
    if(temp.size() > 0){
        result += stoi(temp);
    }
    cout << result;
    return 0;
}