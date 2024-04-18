#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int info[3][3] = {{0}};
void findMax(vector<int>&, int idx, queue<int>& target);
int main(){
    int n = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            int temp = 0;
            cin >> temp;
            switch(temp){
                case 3:
                    info[j][1]++;
                    break;
                case 2:
                    info[j][2]++;
                    break;
            }
            info[j][0] += temp;
        }
    }
    vector<int> vec;
    queue<int> target;
    target.push(0);
    target.push(1);
    target.push(2);
    for(int i = 0; i < 3; i++){
        vec.clear();
        findMax(vec, i, target);
        if(vec.size() == 1) break;
    }
    if(vec.size() > 1) cout << 0 << " ";
    else cout << vec[0] + 1 << " ";
    cout << info[vec[0]][0] << endl;
    // for(int i = 0; i < 3; i++){
    //     for(int j = 0; j < 3; j++){
    //         cout << info[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}
void findMax(vector<int>& ve, int idx, queue<int>& q){
    int high = -1;
    int size = q.size();
    for(int i = 0; i < size; i++){
        int nowE = q.front();
        q.pop();
        // cout << "info" << nowE << " " << info[nowE][idx] << endl;
        if(high < info[nowE][idx]){
            ve.clear();
            ve.push_back(nowE);
            high = info[nowE][idx];
        }
        else if(high == info[nowE][idx]) ve.push_back(nowE);
    }
    for(int i = 0; i < ve.size(); i++){
        q.push(ve[i]);
    }
}