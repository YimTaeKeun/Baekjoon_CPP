#include <iostream>
#include <string>
using namespace std;
int main(){
    string cal;
    cin >> cal;
    int result = 0;
    for(int i = 0; i < cal.size(); i++){
        switch(cal[i]){
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                result++;
        }
    }
    cout << result;
    return 0;
}