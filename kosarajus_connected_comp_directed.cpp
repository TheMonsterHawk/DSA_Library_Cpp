#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


void dfs(int source, int vis_mark, stack < int > &st, vector < vector < int > > &graph, vector < int > &visited){
    if(visited[source] > 0) return;
    visited[source] = vis_mark;

    for(int i = 0; i < (int)graph[source].size(); i++){
        int cur = graph[source][i];
        dfs(cur, vis_mark, st, graph, visited);
    }
    st.push(source);
    return;
}

int main(){

    freopen("C:/data/kosarajus_connected_comp_directed.txt", "r", stdin);

    int n, m;
    cin >> n >> m;

    vector < vector < int > > graph;
    vector < vector < int > > rgraph;
    vector < int > visited;

    graph.assign(n, vector < int >(0, 0));
    rgraph.assign(n, vector < int >(0, 0));
    visited.assign(n, 0);

    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        x--;y--;
        graph[x].push_back(y);
        rgraph[y].push_back(x);
    }

    stack < int > st;

    for(int i = 0; i < n; i++){
        dfs(i, n+1, st, graph, visited);
    }

    vector < int > root_list;

    for(int i = 0; !st.empty(); i++){
        root_list.push_back(st.top());
        //cout << st.top() << " ";
        st.pop();
    }

    visited.assign(n, 0);
    for(int i = 0; i < (int)root_list.size(); i++){
        int cur = root_list[i];
        dfs(cur, cur+1, st, rgraph, visited);
    }

    vector < vector < int > > conn_comp(n+1);
    for(int i = 0; i < n; i++){
        conn_comp[visited[i]].push_back(i);
    }

    for(int i = 0; i <= n; i++){
        if((int)conn_comp[i].size() == 0) continue;
        for(int j = 0; j < (int)conn_comp[i].size(); j++)
            cout << conn_comp[i][j] << " ";
        cout << endl;
    }
    cout << endl;

}
