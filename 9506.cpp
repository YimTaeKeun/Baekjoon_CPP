#include <iostream>
#include <vector>
using namespace std;
bool is_win(vector<int>&, int x);
int main(){
    while(true){
        int target = 0;
        cin >> target;
        if(target == -1) break;
        vector<int> vec;
        //초기화
        bool is = is_win(vec, target);
        cout << target;
        if(is){
            cout << " = ";
            for(int i = 0; i < vec.size() - 1; i++) cout << vec[i]<< " + ";
            cout << vec[vec.size() - 1] << endl;
        }
        else cout << " is NOT perfect." << endl;

    }
    return 0;
}
bool is_win(vector<int>& vec, int x){
    int sum = 0;
    for(int i = 1; i < x; i++){
        if(x % i == 0){
            vec.push_back(i);
            sum += i;
        }
    }
    if(sum == x) return true;
    else return false;
}