#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool dfs(int source, int num, vector < vector < int > > &graph, vector < int > &visited){
    visited[source] = num;
    bool ans = false;
    for(int i = 0; i < (int)graph[source].size(); i++){
        int cur = graph[source][i];
        if(visited[cur] == num) return true;
        else ans |= dfs(cur, num, graph, visited);
    }
    return ans;
}

int main(){

    freopen("C:/data/cycle_check_directed_graph.txt", "r", stdin);

    int n, m;
    cin >> n >> m;

    vector < vector < int > > graph(n);
    vector < int > visited(n, 0);
    int counter = 0;

    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        x--;y--;
        graph[x].push_back(y);
    }

    bool is_cycle_detected = false;
    for(int i = 0; i < n; i++){
        if(visited[i] == 0){
            is_cycle_detected |= dfs(i, ++counter, graph, visited);
        }
    }

    //for(int i = 0; i < n; i++) cout << visited[i] << " "; cout << endl;

    if(is_cycle_detected) cout << "Cycle is there!" << endl;
    else cout << "Cycle is not there!" << endl;
}
