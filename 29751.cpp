#include <iostream>
#include <math.h>
using namespace std;

int main(){
    double n = 0, m = 0;
    cin >> n >> m;
    cout << round(n * m / 2 * 10) / 10 << endl;
    return 0;
}