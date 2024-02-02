#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    int boardSize = 0, eventCnt = 0;
    cin >> boardSize >> eventCnt;
    long long* sumBoard = new long long[boardSize];
    long long sum = 0;
    for(int i = 0; i < boardSize; i++){
        int target = 0;
        cin >> target;
        sum += target;
        sumBoard[i] = sum;
    }
    long result = 0;
    for(int i = 0; i < eventCnt; i++){
        int startPoint = 0, endPoint = 0;
        cin >> startPoint >> endPoint;
        startPoint -= 2;
        endPoint--;
        if(startPoint == -1) cout << sumBoard[endPoint] << "\n";
        else cout  << sumBoard[endPoint] - sumBoard[startPoint] << "\n";
    }
    return 0;
}