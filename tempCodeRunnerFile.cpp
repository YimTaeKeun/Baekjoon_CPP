#include <iostream>
using namespace std;
int main(){
    unsigned int n {0x6eb9};
    unsigned int mask {0x0001};
    // n << 1
    // n >> 1
    if(n & mask) cout << "n is odd" << endl;
    else cout << "n is even" << endl;
}