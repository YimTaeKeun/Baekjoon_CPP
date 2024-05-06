#include <iostream>
#include <vector>
using namespace std;
int main(){
    int stuff_cnt = 0, w_lim = 0;
    cin >> stuff_cnt >> w_lim;
    vector<vector<int*>> cal;
    for(int i = 0; i < stuff_cnt; i++){
        int w = 0, v = 0;
        cin >> w >> v;
        if(w > w_lim) continue;
        vector<int*> temp;
        temp.push_back(new int[2] {w, v});
        if(cal.empty()){
            temp.push_back(new int[2] {w, v});
            cal.push_back(temp);
            continue;
        }
        // 비어있지 않을 때 진짜 처리 시작
        vector<int*> compare; // 원래의 나, 기존의 첫번째, 기존의 두번째
        compare.push_back(new int[2] {w, v});
        if(w + cal[i - 1][0][0] <= w_lim) compare.push_back(new int[2] {w + cal[i - 1][0][0], v + cal[i - 1][0][1]});
        if(w + cal[i - 1][1][0] <= w_lim) compare.push_back(new int[2] {w + cal[i - 1][1][0], v + cal[i - 1][1][1]});
        int max_idx = 0, max_value = 0;
        for(int c = 0; c < compare.size(); c++){
            if(max_value <= compare[c][1]){
                if(max_value == compare[c][1]){
                    if(compare[max_idx][0] > compare[c][0]){
                        max_idx = c;
                        max_value = compare[c][1];
                    }
                }
                else{
                    max_idx = c;
                    max_value = compare[c][1];
                }
            }
        }
        temp.push_back(new int[2] {compare[max_idx][0], max_value});
        cout << "hello";
        cal.push_back(temp);
        for(int c = 0; c < cal.size(); c++){
            for(int a = 0; a < cal[c].size(); a++){
                cout << "[" << cal[c][a][0] << ", " << cal[c][a][1] <<  "]" << " ";
            }
            cout << endl;
        }
    }
    int max_v = 0;
    for(int i = 0; i < cal.size(); i++){
        for(int j = 0; j < 2; j++){
            if(max_v < cal[i][j][1]) max_v = cal[i][j][1];
        }
    }
    cout << max_v;
    return 0;
}