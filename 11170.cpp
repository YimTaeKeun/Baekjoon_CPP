#include <iostream>
using namespace std;
int how_many_cnt(int target);
int main(){
    int tc = 0;
    cin >> tc;
    for(int i = 0; i < tc; i++){
        int fr = 0, to = 0;
        long long result = 0;
        cin >> fr >> to;
        for(int now = fr; now <= to; now++){
            result += how_many_cnt(now);
        }
        cout << result << endl;
    }
    return 0;
}
int how_many_cnt(int target){
    int result = 0;
    if(target == 0) return 1;
    while(target != 0){
        if(target % 10 == 0) result++;
        target /= 10;
    }
    return result;
}