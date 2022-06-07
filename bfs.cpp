#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

    freopen("C:/data/graph.txt", "r", stdin);

    int n, m;
    cin >> n >> m;

    vector< vector<int> > graph(n+1, vector<int>(0, 0));
    vector< int > visited(n+1, 0);
    vector< int > que;
    vector< int > level(n+1, 0);

    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    int cur = 0;
    int root = 1;
    level[root] = 1;
    visited[root] = 1;
    que.push_back(root);
    while(cur < (int)que.size()){
        int source = que[cur++];
        for(int i = 0; i < (int)graph[source].size(); i++){
            int to = graph[source][i];
            if(visited[to]!=1){
                //processing on node.
                que.push_back(to);
                visited[to] = 1;
                level[to] = level[source] + 1;
            }
        }
    }
    for(int i = 1; i <= n; i++) cout << level[i] << " "; cout << endl;
}
