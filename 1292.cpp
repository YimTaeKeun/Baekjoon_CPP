#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> board;
    for(int i = 1; i <= 1000; i++){
        if(board.size() > 1000) break;
        for(int j = 0; j < i; j++) board.push_back(i);
    }
    int a = 0, b = 0;
    cin >> a >> b;
    long long sum = 0;
    for(int i = a - 1; i < b; i++) sum += board[i];
    cout << sum;
    return 0;
}