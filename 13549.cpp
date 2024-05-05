#include <iostream>
#include <queue>
using namespace std;
int main(){
    int fr = 0, to = 0;
    cin >> fr >> to;
    queue<int*> cal;
    bool is_end = false;
    cal.push(new int[2] {to, 0});
    while(!cal.empty() && !is_end){
        int* now = cal.front();
        int data = now[0], cnt = now[1];
        cal.pop();
        if(data == fr){
            cal.push(now);
            break;
        }
        else if(data + 1 == fr){
            cal.push(new int[2] {data + 1, cnt + 1});
            break;
        }
        else if(data - 1 == fr){
            cal.push(new int[2] {data - 1, cnt + 1});
            break;
        }
        if(data % 2 == 0){
            cal.push(new int[2] {data / 2, cnt});
        }
        else{
            cal.push(new int[2] {data + 1, cnt + 1});
            if(data - 1 >= 0) cal.push(new int[2] {data - 1, cnt + 1});
        }
    }
    cout << cal.back()[1];
    return 0;
}