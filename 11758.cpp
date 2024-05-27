#include <iostream>
using namespace std;
int main(){
    int p[4][2] = {0};
    for(int i = 1; i <= 3; i++){
        cin >> p[i][0] >> p[i][1];
    }
    for(int i = 2; i <= 3; i++){
        p[i][0] -= p[1][0];
        p[i][1] -= p[1][1]; 
    }
    
    return 0;
}