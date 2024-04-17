#include <iostream>
#include <cmath>
using namespace std;
bool calP[1005] = {false};
bool calN[1005] = {false};
int main(){
    int n = 0, temp = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> temp;
        if(temp < 0){
            if(!calN[abs(temp)]) calN[abs(temp)] = true;
        }
        else if(!calP[temp]) calP[temp] = true;
        
    }
    for(int i = 1000; i > 0; i--) if(calN[i]) cout << -i << " ";
    for(int i = 0; i < 1001; i++) if(calP[i]) cout << i << " ";
    return 0;
}