#include <iostream>
#include <string>
#include <cstring>
using namespace std;
void calculate(string target, int&, int&, int&, int&);
int main(){
    string cal;
    while(getline(cin, cal)){
        int low = 0, up = 0, num = 0, space = 0;
        calculate(cal, low, up, num, space);
        cout << low << " ";
        cout << up << " ";
        cout << num << " ";
        cout << space << endl;
    }
}
void calculate(string target, int& low, int& up, int& num, int& space){
    for(int i = 0; i < target.size(); i++){
        char my = target[i];
        if(islower(my)) low++;
        else if(isupper(my)) up++;
        else if(isalnum(my) && !isalpha(my)) num++;
        else if(my == 32) space++;
    }
}