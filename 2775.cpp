#include <iostream>
using namespace std;
int main(){
    int tc = 0;
    cin >> tc;
    for(int t = 0; t < tc; t++){
        int floor = 0, ho = 0;
        cin >> floor;
        cin >> ho;
        int** houses = new int*[floor + 1];
        houses[0] = new int[ho];
        for(int i = 1; i <= ho; i++) houses[0][i - 1] = i;
        for(int i = 1; i <= floor; i++){
            houses[i] = new int[ho];
            for(int j = 0; j < ho; j++){
                long sum = 0;
                for(int k = 0; k <= j; k++) sum += houses[i - 1][k];
                houses[i][j] = sum;
            }
        }
        cout << houses[floor][ho - 1] << endl;
    }
    return 0;
}