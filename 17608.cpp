#include <iostream>
#include <stack>
using namespace std;
int main(){
    int cnt = 0;
    cin >> cnt;
    int high = -1;
    int result = 0;
    stack<int> cal;
    for(int i = 0; i < cnt; i++){
        int temp = 0;
        cin >> temp;
        cal.push(temp);
    }
    for(int i = 0; i < cnt; i++){
        int temp = 0;
        temp = cal.top();
        cal.pop();
        if(high < temp){
            high = temp;
            result++;
        }
    }
    cout << result;
    return 0;
}