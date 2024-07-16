#include <iostream>
using namespace std;
int main(){
    int tc = 0, temp = 0;
    cin >> tc;
    for(int t = 0; t < tc; t++){
        cin >> temp;
        for(int i = 0; i < temp; i++) cout << "=";
        cout << endl;
    }
    return 0;
}