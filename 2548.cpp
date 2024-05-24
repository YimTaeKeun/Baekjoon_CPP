#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
long long returnMinus(int, vector<int>&);
int main(){
    int n = 0;
    cin >> n;
    vector<int> board;
    for(int i = 0; i < n; i++){
        int t = 0;
        cin >> t;
        board.push_back(t);
    }
    long long min = returnMinus(0, board);
    int minIdx = 0;
    for(int i = 1; i < board.size(); i++){
        long long temp = returnMinus(i, board);
        if(min > temp){
            minIdx = i;
            min = temp;
        }
        else if(min == temp && board[minIdx] > board[i]) minIdx = i;
    }
    cout << board[minIdx] << endl;
    return 0;
}
long long returnMinus(int idx, vector<int>& vec){
    long long target = vec[idx], sum = 0;
    for(int i = 0; i < vec.size(); i++){
        if(i != idx) sum += abs(target - vec[i]);
    }
    return sum;
}