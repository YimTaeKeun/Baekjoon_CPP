#include <iostream>
using namespace std;
int main(){
    int score = 0;
    int afterScore = 0;
    bool is_success = false;
    for(int i = 0; i < 10; i++){
        int temp = 0;
        cin >> temp;
        if(is_success) continue;
        if(score + temp > 100){
             is_success = true;
             afterScore = score + temp;
        }
        else score += temp;
    }
    if(!is_success) cout << score << endl;
    else{
        if(100 - score < afterScore - 100){
        cout << score << endl;
        }
        else if(100 - score >= afterScore - 100){
            cout << afterScore << endl;
        }
    }
    
    return 0;
}