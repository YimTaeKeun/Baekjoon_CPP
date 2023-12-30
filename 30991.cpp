#include <iostream>
using namespace std;
int main(){
    long long howMany = 0;
    cin >> howMany;
    long long a = -1, b = 1, c = 1;
    for(int i = 1; i < howMany; i++){
        long long prevA = a, prevB = b, prevC = c;
        a -= c;
        b += c;
        c += 2 * prevA - 2 * prevB;
    }
    cout << a + b + c;
    return 0;
}