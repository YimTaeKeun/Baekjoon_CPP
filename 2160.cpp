#include <iostream>
#include <vector>
#include <string>
using namespace std;
int compare(char**, char**);
int main(){
    int result = -1;
    vector<char**> pictures;
    int n = 0, oneN = 0, twoN = 0;
    cin >> n;
    string temp;
    for(int k = 0; k < n; k++){
        char** picture = new char*[5];
        for(int a = 0; a < 5; a++) picture[a] = new char[7];
        for(int i = 0; i < 5; i++){
            cin >> temp;
            for(int j = 0; j < 7; j++) picture[i][j] = temp[j];
        }
        pictures.push_back(picture);
    }

    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            char** pic1 = pictures[i];
            char** pic2 = pictures[j];
            int cnt = compare(pic1, pic2);
            if(result == -1 || result > cnt){
                result = cnt;
                oneN = i + 1;
                twoN = j + 1;
            }
        }
    }
    cout << oneN << " " << twoN;
    return 0;
}
int compare(char** pic1, char** pic2){
    int cnt = 0;
    for(int c = 0; c < 5; c++){
        for(int r = 0; r < 7; r++) if(pic1[c][r] != pic2[c][r]) cnt++;
    }
    return cnt;
}