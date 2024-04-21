#include <iostream>
#include <cmath>
using namespace std;
double distance();
int how_many_student();
int** board;
int pro_r = 0, pro_c = 0, my_r = 0, my_c = 0;
int main(){
    int board_size = 0;
    cin >> board_size;
    board = new int*[board_size];
    for(int r = 0; r < board_size; r++){
        board[r] = new int[board_size];
        for(int c = 0; c < board_size; c++){
            int data = 0;
            cin >> data;
            if(data == 5){
                pro_r = r;
                pro_c = c;
            }
            else if(data == 2){
                my_r = r;
                my_c = c;
            }
            board[r][c] = data;
        }
    }
    if(distance() >= 5 && how_many_student() >= 3) cout << 1;
    else cout << 0;
    
}
double distance(){
    return sqrt(pow(pro_r - my_r, 2) + pow(pro_c - my_c, 2));
}
int how_many_student(){
    // change pos
    int result = 0;
    for(int r = min(pro_r, my_r); r <= max(pro_r, my_r); r++){
        for(int c = min(pro_c, my_c); c <= max(pro_c, my_c); c++){
            if(board[r][c] == 1) result++;
        }
    }
    return result;
}