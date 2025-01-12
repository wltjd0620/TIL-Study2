#include <bits/stdc++.h>
using namespace std;

vector <int> adj[100];
int visited[100];
int nodeList[] = {10,12,14,16,18,20,22,24};

void bfs(int here){
    // queue 선언
    queue<int> q;
    // 일단 방문처리
    visited[here] = 1;
    // queue에 push
    q.push(here);
    // queue size만큼 반복
    while(q.size()){
        // queue 맨 앞 here변수에 저장 후 해당 값 pop
        int here = q.front(); q.pop();
        // adj 해당 연결리스트의 노드 탐색
        for(int there : adj[here]){
            // 방문노드면 패스
            if(visited[there]) continue;
            // 방문하지않은 노드의 경우 +1
            visited[there] = visited[here] + 1;
            q.push(there);
        }
    }
}

int main(){
    adj[10].push_back(12);
    adj[10].push_back(14);
    adj[10].push_back(16);

    adj[12].push_back(18);
    adj[12].push_back(20);
    
    adj[20].push_back(22);
    adj[20].push_back(24);

    bfs(10);
    for(int i : nodeList){
        cout << i << " : " << visited[i] << '\n';
    }
    cout << "10번으로부터 24번까지 최단거리는 : " << visited[24] -1 << "\n";
    return 0;
}
