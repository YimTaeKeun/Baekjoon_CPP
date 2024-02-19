#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int returnValue(string);
int main(){
    long long result = 0;
    string one, two, three;
    cin >> one >> two >> three;
    result = (10 * returnValue(one) + returnValue(two)) * ceil(pow(10, returnValue(three)));
    cout << result << endl;
    return 0;
}
int returnValue(string color){
    if(color == "black") return 0;
    else if(color == "brown") return 1;
    else if(color == "red") return 2;
    else if(color == "orange") return 3;
    else if(color == "yellow") return 4;
    else if(color == "green") return 5;
    else if(color == "blue") return 6;
    else if(color == "violet") return 7;
    else if(color == "grey") return 8;
    else if(color == "white") return 9;
}