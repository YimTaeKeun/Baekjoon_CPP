#include <iostream>
#include <string>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cout << "Scenario #" << i + 1 << ":\n";
        int wordCnt = 0;
        cin >> wordCnt;
        string* words = new string[wordCnt];
        for(int wC = 0; wC < wordCnt; wC++) cin >> words[wC];
        int cmdCnt = 0;
        cin >> cmdCnt;
        for(int cmds = 0; cmds < cmdCnt; cmds++){
            int c = 0, temp = 0;
            cin >> c;
            for(; c > 0; c--){
                cin >> temp;
                cout << words[temp];
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}