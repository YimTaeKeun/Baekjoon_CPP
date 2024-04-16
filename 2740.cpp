#include <iostream>
using namespace std;
int main(){
    int one_row = 0, one_col = 0;
    cin >> one_row >> one_col;
    int** one = new int*[one_row];
    for(int i = 0; i < one_row; i++){
        one[i] = new int[one_col];
        for(int j = 0; j < one_col; j++) cin >> one[i][j];
    }
    
    int two_row = 0, two_col = 0;
    cin >> two_row >> two_col;
    int** two = new int*[two_row];
    for(int i = 0; i < two_row; i++){
        two[i] = new int[two_col];
        for(int j = 0; j < two_col; j++) cin >> two[i][j];
    }

    for(int i = 0; i < one_row; i++){
        for(int j = 0; j < two_col; j++){
            long long sum = 0;
            for(int k = 0; k < two_row; k++) sum += (one[i][k] * two[k][j]);
            cout << sum << " ";
        }
        cout << endl;
    }

    return 0;
}