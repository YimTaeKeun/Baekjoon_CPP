#include <iostream>
#include <cmath>
using namespace std;
long long gcd(int, int);
long long minG(int, int);
long long threeMin(int, int, int);
int main(){
    int cal[5];
    long long result = 0;
    for(int i = 0; i < 5; i++) cin >> cal[i];
    for(int one = 0; one < 3; one++){
        for(int two = one + 1; two < 4; two++){
            for(int three = two + 1; three < 5; three++){
                long long temp = threeMin(cal[one], cal[two], cal[three]);
                if(result == 0) result = temp;
                else result = min(result, temp);
            }
        }
    }
    cout << result;
    return 0;
}
long long gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}
long long minG(int a, int b){
    return a * b / gcd(a, b);
}
long long threeMin(int one, int two, int three){
    long long oneT = minG(one, two);
    long long twoT = minG(two, three);
    return minG(oneT, twoT);
}