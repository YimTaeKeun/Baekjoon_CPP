#include <iostream>
#include <string>
#include <cmath>
using namespace std;
bool isPrime(int x);
int main(){
    string temp;
    int sum = 0;
    cin >> temp;
    for(int i = 0; i < temp.size(); i++){
        if(isupper(temp[i])) sum += temp[i] - 'A' + 27;
        else sum += temp[i] - 'a' + 1;
    }
    cout << ((isPrime(sum)) ? "It is a prime word." : "It is not a prime word.");
    return 0;
}
bool isPrime(int x){
    for(int i = 2; i <= sqrt(x); i++){
        if(x % i == 0) return false;
    }
    return true;
}