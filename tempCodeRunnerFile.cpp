#include <iostream>
#include <string.h>
using namespace std;

int N;
char relationship[50][50] = {'N',};
int max_friends = 0;
int visit[50] = {0,};
int friends = 0;

void dfs(int v, int depth){
	//현재 친구수가 max_friends보다 많다면 max_friends를 갱신한다
    if(friends > max_friends) max_friends = friends;
    
    //시작 노드로부터 거리가 2 이상인 경우, 더 이상 탐색하지 않는다
    if(depth > 1) return;
    
    //친구 탐색
    for(int i=0; i<N; i++){
    	//이전에 방문하지 않았고 노드 v와 연결되어 있는 경우, 친구수를 카운팅 한다
        if(visit[i] == 0 && relationship[v][i] == 'Y'){
            visit[i] = 1;
            friends++;
            dfs(i, depth+1);
        }
    }
}

int main(int argc, const char * argv[]) {
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> relationship[i][j];
        }
    }
    //각 사람에 대하여 친구 수를 구한다
    for(int i=0; i<N; i++){
    	//visit 함수 초기화
        memset(visit, 0, sizeof(visit));
        //친구수 0으로 초기화, 현재 시작 노드 방문 처리
        friends = 0;
        visit[i] = 1;
        dfs(i, 0);
    }
    cout << max_friends << endl;
    return 0;
}