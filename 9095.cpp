#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(NULL);
    int n = 0;
    cin >> n;
    vector<long long> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(4);
    for(int i = 0; i < n; i++){
        long long target = 0;
        cin >> target;
        int size = vec.size();
        if(size < target){
            for(int i = 0; i < target - size; i++){
                vec.push_back(vec[vec.size() - 1] + vec[vec.size() - 2] + vec[vec.size() - 3]);
            }
        }
        cout << vec[target - 1] << "\n";
    }
    return 0;
}