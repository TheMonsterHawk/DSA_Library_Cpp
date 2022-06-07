#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void dfs(int source, vector < vector < int > > &graph, vector < int > &visited, stack < int > &st){
    visited[source] = 1;

    for(int i = 0; i < (int)graph[source].size(); i++){
        int cur = graph[source][i];
        if(visited[cur] == 0){
            dfs(cur, graph, visited, st);
        }
    }
    st.push(source);
}

int main(){

    freopen("C:/data/topological_sort.txt", "r", stdin);

    int n, m;
    cin >> n >> m;

    vector < vector < int > > graph;
    vector < int > visited;
    stack < int > st;

    graph.assign(n, vector < int >(0, 0));
    visited.assign(n, 0);

    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
    }

    int source = 0;
    for(int i = 0; i < n; i++){
        if(visited[i] == 0){
            dfs(i, graph, visited, st);
        }
    }

    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}
