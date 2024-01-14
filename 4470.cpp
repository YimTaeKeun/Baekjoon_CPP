#include <iostream>
#include <string>
using namespace std;
int main(){
    int cnt = 0;
    cin >> cnt;
    string* stringArr = new string[cnt];
    cin.ignore();
    for(int i = 0; i < cnt; i++) getline(cin, stringArr[i]);
    for(int i = 0; i < cnt; i++) cout << i + 1 <<". " << stringArr[i] << endl;
    return 0;
}