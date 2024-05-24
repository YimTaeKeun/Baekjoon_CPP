#include <iostream>
#include <queue>
using namespace std;
int fib(int);
int main(){
    int seatCnt = 0, vipCnt = 0;
    cin >> seatCnt >> vipCnt;
    int result = 1, temp = 0, prev = 0;
    for(int i = 0; i < vipCnt; i++){
        cin >> temp;
        result *= fib(temp - prev);
        prev = temp;
    }        
    if(seatCnt - prev != 0) result *= fib(seatCnt - prev + 1);
    cout << result;
    return 0;
}
int fib(int target){
    queue<int> cal;
    cal.push(0);
    cal.push(1);
    for(int i = 0; i < target - 1; i++){
        int t = cal.front();
        cal.pop();
        cal.push(cal.front() + t);
    }
    return cal.back();
}