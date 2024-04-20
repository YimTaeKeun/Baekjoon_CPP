#include <iostream>
using namespace std;
int main(){
    int bread_len = 0, people_cnt = 0;
    cin >> bread_len >> people_cnt;
    int* bread_info = new int[bread_len + 1];
    int* human_info = new int[people_cnt + 1];
    fill_n(human_info, people_cnt + 1, 0);
    fill_n(bread_info, bread_len + 1, 0);
    int expect_human = 0, expect_high = 0;
    for(int i = 1; i <= people_cnt; i++){
        int p = 0, k = 0;
        cin >> p >> k;
        if(expect_high < k - p){
            expect_high = k - p;
            expect_human = i;
        }
        for(int j = p; j <= k; j++){
            if(bread_info[j] == 0) bread_info[j] = i;
        }
    }
    cout << expect_human << endl;
    for(int i = 1; i <= bread_len; i++) human_info[bread_info[i]]++;
    int human = 0, cnt_high = 0;
    for(int i = 1; i <= people_cnt; i++){
        if(human_info[i] > cnt_high){
            cnt_high = human_info[i];
            human = i;
        }
    }
    cout << human << endl;

    return 0;
}