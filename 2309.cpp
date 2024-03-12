#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int tall[9];
    int total_sum = 0, target = 0;
    for(int i = 0; i < 9; i++){
         cin >> tall[i];
         total_sum += tall[i];
    }
    target = total_sum - 100;
    bool solve = false;
    for(int i = 0; i < 8; i++){
        if(solve) break;
        for(int j = i + 1; j < 9; j++){
            if(tall[i] + tall[j] == target){
                tall[i] = 0;
                tall[j] = 0;
                solve = true;
                break;
            }
        }
    }
    sort(tall, tall + 9);
    for(int i = 2; i < 9; i++) cout << tall[i] << endl;
    return 0;
}