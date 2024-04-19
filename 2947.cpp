#include <iostream>
using namespace std;
void swap(int*, int*);
bool check(int arr[]);
void printArr(int arr[]);
int main(){
    int board[5] = {0};
    for(int i = 0; i < 5; i++) cin >> board[i];
    while(!check(board)){
        for(int i = 0; i < 4; i++){
            if(board[i] > board[i + 1]){
                swap(&board[i], &board[i + 1]);
                printArr(board);
            }
        }
        
    }
    
    return 0;
}
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
bool check(int arr[]){
    for(int i = 1; i <= 5; i++) if(arr[i - 1] != i) return false;
    return true;
}
void printArr(int arr[]){
    for(int i = 0; i < 5; i++) cout << arr[i] << " ";
    cout << endl;
}