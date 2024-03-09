#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
bool isSosu(long long target);
int main(){
    vector<long long> cal;
    for(int i = 2; i <= 246912; i++){
        if(isSosu(i)) cal.push_back(i);
    }
    while(true){
        long long n = 0, cnt = 0;
        cin >> n;
        if(n == 0) break;
        for(int i = 0; i < cal.size(); i++){
            if(n < cal[i] && cal[i] <= 2 * n) cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}
bool isSosu(long long target){
	for(int i = 2; i < (long long) sqrt(target) + 1; i++){
		if(target % i == 0) return false;
	}
	return true;
}