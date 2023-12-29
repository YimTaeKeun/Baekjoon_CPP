#include <iostream>
using namespace std;

int main(){
    double n = 0, m = 0;
    cin >> n >> m;
    cout << fixed;
    cout.precision(1);
    cout << static_cast<double>(n * m / 2) << endl;
    return 0;
}