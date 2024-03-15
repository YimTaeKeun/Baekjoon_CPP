#include <iostream>
#include <string>
using namespace std;
int main(){
    int cal[26];
    string target;
    cin >> target;
    fill_n(cal, 26, 0);
    for(int i = 0; i < target.size(); i++) cal[target[i] - 'a']++;
    for(int i = 0; i < 26; i++) cout << cal[i] << " ";
    return 0;
}