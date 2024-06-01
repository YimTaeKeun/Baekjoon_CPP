#include <iostream>
using namespace std;
int main(){
    int list[6] = {500, 100, 50, 10, 5, 1};
    int cnt = 0, i = 0;
    int my = 0;
    cin >> my;
    my = 1000 - my;
    do{
        cnt += my / list[i];
        my = my - list[i] * (my / list[i]);
    }while(my != 0 && ++i != 6);
    cout << cnt;
    return 0;
}