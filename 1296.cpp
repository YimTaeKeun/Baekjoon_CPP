#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int return_score(string name, string team);
int name_cnt[26] = {0};
int main(){
    string target;
    cin >> target;
    for(int i = 0; i < target.size(); i++){
        char t = target[i];
        name_cnt[t - 'A'] += 1;
    }
    int cnt = 0;
    cin >> cnt;
    int high_score = -1;
    vector<string> result_vec;
    for(int i = 0; i < cnt; i++){
        string teamName;
        cin >> teamName;
        int score = return_score(target, teamName);
        if(high_score < score){
            high_score = score;
            result_vec.clear();
            result_vec.push_back(teamName);
        }
        else if(high_score == score) result_vec.push_back(teamName);
    }
    sort(result_vec.begin(), result_vec.end());
    cout << result_vec[0] << endl;
    // for(int i = 0; i < result_vec.size(); i++) cout << result_vec[i] << endl;
    return 0;
}
int return_score(string name, string teamName){
    int team_cnt[26] = {0};
    for(int i = 0; i < teamName.size(); i++){
        char t = teamName[i];
        team_cnt[t - 'A'] += 1;
    }
    vector<int> vec;
    for(int i = 0; i < name.size(); i++){
        vec.push_back(name_cnt[name[i] - 'A'] + team_cnt[name[i] - 'A']);
    }
    int result = 1;
    //
    for(int i = 0; i < vec.size(); i++) cout << vec[i] << endl;
    //
    for(int i = 0; i < vec.size() - 1; i++){
        for(int j =  i + 1; j < vec.size(); j++) result = result * (vec[i] + vec[j]) % 100;
    }
    cout << teamName << ": " << result << endl;
    return result;

}