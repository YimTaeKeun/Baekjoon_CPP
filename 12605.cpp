#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main(){
    string num;
    int tc = 0;
    string cal;
    getline(cin, num);
    tc = stoi(num);
    for(int i = 1; i <= tc; i++){
        stack<string> st;
        string temp;
        getline(cin, cal);
        for(int j = 0; j < cal.size(); j++){
            if(cal[j] == ' '){
                st.push(temp);
                temp.clear();
            }
            else temp += cal[j];
        }
        if(temp != "") st.push(temp);
        cout << "Case #" << i << ": ";
        while(!st.empty()){
            cout << st.top() << " ";
            st.pop(); 
        }
        cout << endl;
    }
}