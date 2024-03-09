#include <iostream>
using namespace std;
bool** cal;
void recursion(int, int, int);
int main(){
    int n = 0;
    cin >> n;
    cal = new bool*[n];
    for(int i = 0; i < n; i++){
        cal[i] = new bool[n];
        fill_n(cal[i], n, false);
    }
    recursion(n, 0, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(cal[i][j]) cout << '*';
            else cout << ' ';
        }
        cout << endl;
    }
    return 0;
}
void recursion(int n, int col, int row){
    if(n == 3){
        for(int i = row; i < row + 3; i++) cal[col][i] = true;
        cal[col + 1][row] = true;
        cal[col + 1][row + 2] = true;
        for(int i = row; i < row + 3; i++) cal[col + 2][i] = true;
    }
    else{
        for(int i = 0; i < 3; i++) recursion(n / 3, col, row + i * (n / 3));
        recursion(n / 3, col + n / 3, row);
        recursion(n / 3, col + n / 3, row + 2 * (n / 3));
        for(int i = 0; i < 3; i++) recursion(n / 3, col + 2 * (n / 3), row + i * (n / 3));
    }
}