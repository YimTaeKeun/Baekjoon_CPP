#include <iostream>
using namespace std;
bool* visit;
int main(){
    int mul_target = 0, modular_target = 0;
    cin >> mul_target >> modular_target;
    visit = new bool[modular_target + 1];
    fill_n(visit, modular_target + 1, false);
    long long start = mul_target;
    long long result = 0;
    bool break_true = false;
    do{
        start = (start * mul_target) % modular_target;
        if(visit[start]) break_true = true;
        else visit[start] = true;
    }while(!break_true);
    long long now = start;
    do{
        now = (now * mul_target) % modular_target;
        result++;
    }while(now != start);
    cout << result;
    return 0;
}