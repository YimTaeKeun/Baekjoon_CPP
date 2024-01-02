#include <iostream>
using namespace std;
int main(){
    int size = 0;
    cin >> size;
    long M = 1234567891;
    long long r = 1;
    char* cal = new char[size];
    cin >> cal;
    long long result = 0;
    for(int i = 0; i < size; i++){
        result = (result + static_cast<long long>((cal[i] - 96) * r)) % M;
        r = (31 * r) % M;
    }
    cout << result;
    return 0;
}