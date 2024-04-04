#include <iostream>
using namespace std;
int main(){
    int h = 0, m = 0, s = 0, make_time = 0;
    cin >> h >> m >> s;
    cin >> make_time;
    s = (s + (make_time) % 60);
    m = (m + (make_time) / 60 + (s / 60));
    h = h + (m / 60);
    s %= 60;
    m %= 60;
    h %= 24;
    cout << h << " " << m << " " << s;
    return 0;
}