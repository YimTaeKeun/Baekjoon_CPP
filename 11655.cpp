#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int main(){
    string cal;
    getline(cin, cal);
    for(int i = 0; i < cal.size(); i++){
        if(cal[i] == ' ' || !isalpha(cal[i])){
            cout << cal[i];
            continue;
        }
        if(isupper(cal[i])) cout << (char)((cal[i] + 13 - 'A') % 26 + 'A');
        else cout << (char)((cal[i] + 13 - 'a') % 26 + 'a');
    }
    return 0;
}