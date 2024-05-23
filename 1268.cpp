#include <iostream>
using namespace std;
int main(){
    int n = 0;
    cin >> n;
    int** info = new int*[n];
    bool* visit = new bool[n];
    int* cnt = new int[n];
    fill_n(cnt, n, 0);
    for(int i = 0; i < n; i++){
        info[i] = new int[5];
        for(int j = 0; j < 5; j++) cin >> info[i][j];
    }
    for(int i = 0; i < n; i++){
        fill_n(visit, n, false);
        int data = 0;
        for(int j = 0; j < 5; j++){
            data = info[i][j];
            for(int k = 0; k < n; k++){
                if(i != k && data == info[k][j] && !visit[k]){
                    visit[k] = true;
                    cnt[i]++;
                }
            }
        }
    }
    int highIdx = 0;
    for(int i = 0; i < n; i++){
        if(cnt[highIdx] < cnt[i]) highIdx = i;
    }
    cout << highIdx + 1 << endl;
    return 0;
}