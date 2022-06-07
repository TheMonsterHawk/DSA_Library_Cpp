#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector < int > depth;
vector < int > visited;
vector < vector < int > > graph;


void dfs(int source, int parent){
    depth[source] = depth[parent] + 1;
    visited[source] = 1;

    for(int i = 0; i < (int)graph[source].size(); i++){
        int cur = graph[source][i];
        if(visited[cur] != 1) dfs(cur, source);
    }
    return;
}

int main(){

    freopen("C:/data/dfs_recursive.txt", "r", stdin);

    int n, m;
    cin >> n >> m;

    graph.assign(n+1, vector < int >(0, 0));

    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    visited.assign(n+1, 0);
    depth.assign(n+1, 0);

    int root = 1;

    dfs(root, root);

    for(int i = 1; i <= n; i++) cout << depth[i] << " "; cout << endl;
}
