#include <iostream>
using namespace std;
int main(){
    int people_cnt = 0;
    cin >> people_cnt;
    int** people = new int*[people_cnt];
    int* count = new int[people_cnt];
    fill_n(count, people_cnt, 0);
    for(int i = 0; i < people_cnt; i++){
        people[i] = new int[5];
        for(int j = 0; j < 5; j++) cin >> people[i][j];  
    }
    for(int r = 0; r < 5; r++){
        for(int c = 0; c < people_cnt; c++){
            for(int c2 = 0; c2 < people_cnt; c2++){
                if(c != c2 && people[c][r] == people[c2][r]){
                    count[c]++;
                    break;
                }
            }
        }
    }
    long long max_num = 0;
    for(int i = 0; i < people_cnt; i++){
        if(max_num < count[i]) max_num = count[i];
    }
    for(int i = 0; i < people_cnt; i++){
        if(max_num == count[i]){
            cout << i + 1;
            break;
        }
    }
    return 0;
}