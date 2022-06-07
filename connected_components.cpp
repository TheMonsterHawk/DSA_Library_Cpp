#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector < vector < int > > graph;
vector < int > visited;
vector < int > comp_id;

void dfs(int source, int component){
    comp_id[source] = component;
    visited[source] = 1;
    for(int i = 0; i < (int)graph[source].size(); i++){
        int cur = graph[source][i];
        if(visited[cur] != 1){
            dfs(cur, component);
        }
    }
    return;
}

int main(){

    freopen("C:/data/connected_component.txt", "r", stdin);

    int n, m;
    cin >> n >> m;

    graph.assign(n+1, vector < int > (0, 0));
    visited.assign(n+1, 0);
    comp_id.assign(n+1, 0);

    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    int total_components = 0;
    for(int i = 1; i <= n; i++){

        if(visited[i] != 1){
            dfs(i, ++total_components);
        }
    }
    for(int i = 1; i <= n; i++){
        cout << comp_id[i] << " ";
    }
    cout << endl;

}
