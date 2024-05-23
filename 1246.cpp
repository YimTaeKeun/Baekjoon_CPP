#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int eggCnt = 0, clientCnt = 0, price = 0;
    long long totMoney = 0;
    cin >> eggCnt >> clientCnt;
    vector<int> prices;
    for(int i = 0; i < clientCnt; i++){
        int pi = 0;
        cin >> pi;
        prices.push_back(pi);
    }
    sort(prices.begin(), prices.end());
    int pos = 0;
    if(eggCnt < clientCnt) pos = clientCnt - eggCnt;
    for(int i = pos; i < prices.size(); i++){
        if(prices[i] * (clientCnt - i) > totMoney){
            totMoney = prices[i] * (clientCnt - i);
            price = prices[i];
        }
    }
    cout << price << " " << totMoney << endl;
    return 0;
}