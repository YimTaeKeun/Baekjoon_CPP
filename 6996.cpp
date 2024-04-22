#include <iostream>
using namespace std;
bool solve(string one, string two);
int main(){
    int tc = 0;
    cin >> tc;
    for(int t = 0; t < tc; t++){
        string a, b;
        cin >> a >> b;
        cout << a << " & " << b << " are " << ((solve(a, b)) ? "anagrams." : "NOT anagrams.") << endl; 
    }
    return 0;
}
bool solve(string one, string two){
    if(one.size() != two.size()) return false;
    bool* one_arr = new bool[one.size()];
    bool* two_arr = new bool[two.size()];
    fill_n(one_arr, one.size(), false);
    fill_n(two_arr, two.size(), false);

    for(int one_pos = 0; one_pos < one.size(); one_pos++){
        bool is_there = false;
        for(int two_pos = 0; two_pos < two.size(); two_pos++){
            if(one[one_pos] == two[two_pos] && !two_arr[two_pos]){
                is_there = true;
                one_arr[one_pos] = true;
                two_arr[two_pos] = true;
                break;
            }
            if(two_pos == two.size() - 1 && !is_there) return false;
        }
    }
    return true;
}