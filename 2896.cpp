#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
// 최대 공약수로 나눈다.
// abc 최대 공약수: a, b계산, 그 결과를 c와 계산?
// double형
int gcd(int, int);
int main(){
    int juice[3] = {0};
    int rate[3] = {0};
    for(int i = 0; i < 3; i++) cin >> juice[i];
    for(int j = 0; j < 3; j++) cin >> rate[j];
    int div = gcd(gcd(rate[0], rate[1]), rate[2]);
    for(int i = 0; i < 3; i++) rate[i] /= div;
    double min_num = min(min((double) juice[0] / rate[0], (double) juice[1] / rate[1]), (double) juice[2] / rate[2]);
    for(int i = 0; i < 3; i++){
        double a = juice[i] - (min_num * rate[i]);
        cout << fixed << setprecision(6);
        cout << a << " ";
    }
    return 0;
}
int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}