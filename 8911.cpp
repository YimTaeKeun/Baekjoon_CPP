#include <iostream>
using namespace std;
int* direction;
void changeDirection(char, int*);
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc = 0;
    cin >> tc;
    string cmd;
    for(int i = 0; i < tc; i++){
        cin >> cmd;
        int xMin = 0, xMax = 0, yMin = 0, yMax = 0, nowPosX = 0, nowPosY = 0;
        direction = new int[2];
        direction[0] = 0;
        direction[1] = 1;
        int directMode = 0;
        for(int strPos = 0; strPos < cmd.size(); strPos++){
            int goX = direction[0];
            int goY = direction[1];
            switch(cmd[strPos]){
                case 'F':
                    nowPosX += goX;
                    nowPosY += goY;
                    if(nowPosX > xMax) xMax = nowPosX;
                    else if(nowPosX < xMin) xMin = nowPosX;
                    if(nowPosY > yMax) yMax = nowPosY;
                    else if(nowPosY < yMin) yMin = nowPosY;
                    break;
                case 'L':
                    changeDirection('L', &directMode);
                    break;
                case 'R':
                    changeDirection('R', &directMode);
                    break;
                case 'B':
                    nowPosX -= goX;
                    nowPosY -= goY;
                    if(nowPosX > xMax) xMax = nowPosX;
                    else if(nowPosX < xMin) xMin = nowPosX;
                    if(nowPosY > yMax) yMax = nowPosY;
                    else if(nowPosY < yMin) yMin = nowPosY;
                    break;
            }
        }
        long long result = (yMax - yMin) * (xMax - xMin);
        cout << result << "\n";
    }
    return 0;
}
void changeDirection(char mode, int* directMode){
    int toDirection[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    if(mode == 'R'){
        (*directMode)++;
        if((*directMode) == 4) (*directMode) = 0;
    }
    else if(mode == 'L'){
        (*directMode)--;
        if((*directMode) == -1) (*directMode) = 3;
    }
    direction[0] = toDirection[*directMode][0];
    direction[1] = toDirection[*directMode][1];
}