#include <iostream>
#include <string>
using namespace std;
void swap_str(string& a, string& b);
int main(){
    string a, b;
    long long sum = 0;
    cin >> a >> b; // b가 더 작
    if(a.size() < b.size()) swap(a, b);
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < b.size(); j++){
            int up = a[i] - '0';
            int down = b[j] - '0';
            sum += (up * down);
        }
    }
    cout << sum << endl;
    return 0;
}
void swap_str(string& a, string& b){
    string temp = a;
    a = b;
    b = a;
}
