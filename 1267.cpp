#include <iostream>
using namespace std;
int main(){
    int n = 0, y = 0, m = 0, temp = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> temp;
        y += 10 * (temp / 30 + 1);
        m += 15 * (temp / 60 + 1);
    }
    if(y > m) cout << "M ";
    else if(y < m) cout << "Y ";
    else cout << "Y M ";
    cout << ((y > m) ? m : y) << endl;
    return 0;
}