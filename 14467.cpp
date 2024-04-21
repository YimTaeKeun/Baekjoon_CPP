#include <iostream>
using namespace std;
int main(){
    int cal[11] = {-1};
    for(int i = 0; i < 11; i++) cal[i] = -1;
    int n = 0;
    cin >> n;
    int result = 0;
    for(int t = 0; t < n; t++){
        int cow_num = 0, where = 0;
        cin >> cow_num >> where;
        if(cal[cow_num] == -1) cal[cow_num] = where;
        else{
            if(where == 1 && cal[cow_num] == 0){
                cal[cow_num] = 1;
                result++;
            }
            else if(where == 0 && cal[cow_num] == 1){
                cal[cow_num] = 0;
                result++;
            }
        }
    }
    cout << result;
    return 0;
}