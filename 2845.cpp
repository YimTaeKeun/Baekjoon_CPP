#include <iostream>
using namespace std;
int main(){
    int human = 0, width = 0;
    int compare = 0;
    cin >> human >> width;
    compare = human * width;
    int news[5];
    for(int i = 0; i < 5; i++) cin >> news[i];
    for(int i = 0; i < 5; i++) cout << news[i] - compare << " ";
    cout << endl;
    return 0;
}