#include <iostream>
using namespace std;
long long binarySearch(long long, long long);
int main(){
    long long x = 0, y = 0;
    cin >> x >> y;
    if(x == y){
        cout << -1;
        return 0;
    }
    long long left = 1, right = 1000000000;
    long long compareTarget = (y * 100) / x;
    if(compareTarget >= 99){
        cout << -1;
        return 0;
    }
    while(left != right){
        long long halfPos = binarySearch(left, right);
        if(((y + halfPos) * 100) / (x + halfPos) > compareTarget) right = halfPos;
        else left = halfPos;
        if(left + 1 == right) break;
    }
    if(((y + left) * 100) / (x + left) > compareTarget) cout << left;
    else cout << right;
    return 0;
}
long long binarySearch(long long start, long long end){
    return (start + end) / 2;
}