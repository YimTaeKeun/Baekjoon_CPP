#include <iostream>
#include <string>
using namespace std;
int main(){
    int alpha[26] = {0};
    string target;
    cin >> target;
    bool is_there = false;
    for(int i = 0; i < target.size(); i++){
        if(target[i] >= 'a') alpha[target[i] - 'a']++;
        else alpha[target[i] - 'A']++;
    }
    int max_cnt = 0;
    for(int i = 0; i < 26; i++){
        if(max_cnt < alpha[i]) max_cnt = alpha[i];
    }
    char result = 0;
    for(int i = 0; i < 26; i++){
        if(alpha[i] == max_cnt){
            if(is_there){
                cout << "?";
                return 0;
            }
            result = i + 'A';
            is_there = true;
        }
    }
    cout << result << endl;
    return 0;
}