#include <iostream>
#include <string>
using namespace std;
int main(){
    while(true){
        string name;
        int age, weight;
        cin >> name >> age >> weight;
        if(name == "#" && age == 0 && weight == 0) break;
        cout << name << " ";
        if(age > 17 || weight >= 80) cout << "Senior" << endl;
        else cout << "Junior" << endl;
    }
    return 0;
}