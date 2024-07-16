#include <iostream>
#include <cmath>
using namespace std;
bool height_intersect(int, int, int, int);
bool width_intersect(int, int, int, int);
int main(){
    int point_one[2][2] = {0}, point_two[2][2] = {0};
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++) cin >> point_one[i][j];
    }
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++) cin >> point_two[i][j];
    }

    return 0;
}
bool height_intersect(int one_y1, int one_y2, int two_y1, int two_y2){
    int tot = abs(one_y2 - one_y1) + abs(two_y2 - two_y1);
}