#include <iostream>
using namespace std;
void print_info(int);
int main(){
    for(int i = 0; i < 3; i++){
        int cnt = 0;
        for(int j = 0; j < 4; j++){
            int temp = 0;
            cin >> temp;
            if(temp == 0) cnt++;
        }
        print_info(cnt);
    }
    return 0;
}
void print_info(int num){
    char ch = 0;
    switch(num){
        case 0:
            ch = 'E';
            break;
        case 1:
            ch = 'A';
            break;
        case 2:
            ch = 'B';
            break;
        case 3:
            ch = 'C';
            break;
        case 4:
            ch = 'D';
            break;
    }
    cout << ch << endl;
}