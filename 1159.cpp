#include <iostream>
using namespace std;
int main(){
    int alpha[26] = {0};
    int n = 0;
    cin >> n;
    string temp;
    for(int i = 0; i < n; i++){
        cin >> temp;
        alpha[temp[0] - 'a']++;
    }
    bool isThere = false;
    for(int i = 0; i < 26; i++){
        if(alpha[i] >= 5){
            isThere = true;
            cout << (char)(i + 'a');
        }
    }
    if(!isThere) cout << "PREDAJA";

    return 0;
}