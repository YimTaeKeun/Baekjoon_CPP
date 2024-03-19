#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int n = 0, length = 0;
    cin >> n >> length;
    int** board = new int*[length + 1];
    for(int i = 0; i <= length; i++){
        board[i] = new int[3];
        fill_n(board[i], 3, 0);
    }
    for(int i = 0; i < n; i++){
        int s_point = 0, f_point = 0, sub_length = 0;
        cin >> s_point >> f_point >> sub_length;
        if(f_point > length || f_point - s_point < sub_length) continue;
        if(board[s_point][0] == 0 && board[s_point][1] == 0){
            board[s_point][0] = sub_length;
            board[s_point][1] = f_point;
        }
        else if(board[s_point][1] > f_point){
            // 기존이 더 커
            int dif = board[s_point][1] - f_point;
            if(dif + sub_length < board[s_point][0]){
                board[s_point][0] = sub_length;
                board[s_point][1] = f_point;
            }
        }
        else{
            // 지금의 현재위치가 더 커
            int dif = -(board[s_point][1] - f_point);
            if(sub_length < dif + board[s_point][0]){
                board[s_point][0] = sub_length;
                board[s_point][1] = f_point;
            }
        }
    }
    long long result = 0;
    for(int i = 0; i < length; i++){
        cout << i << " " << result << endl;
        if(board[i][0] == 0 && board[i][1] == 0) result++;
        else{
            result += board[i][0];
            i = board[i][1] - 1;
        }
    }
    cout << result;
    return 0;
}