#include <iostream>
#include <vector>
using namespace std;
int main(){
    int num_cnt = 0;
    vector<int> inc;
    int prev = 0;
    int result = 0;
    cin >> num_cnt;
    for(int i = 0; i < num_cnt; i++){
        int temp = 0;
        cin >> temp;
        if(inc.empty()){
            inc.push_back(temp);
            prev = temp;
            continue;
        }
        if(prev < temp){
            inc.push_back(temp);
        }
        else{
            if(result < inc[inc.size() - 1] - inc[0]) result = inc[inc.size() - 1] - inc[0];
            inc.clear();
            inc.push_back(temp);
        }
        prev = temp;
    }
    if(inc.size() > 1){
        if(result < inc[inc.size() - 1] - inc[0]) result = inc[inc.size() - 1] - inc[0];
    }
    cout << result << endl;
    return 0;
}