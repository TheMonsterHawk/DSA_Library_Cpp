#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n, m;
    cin >> n >> m;

    vector< vector< int > > graph(n+1, vector< int > (0, 0));
    vector< int > visited(n+1, 0);
    vector< int > depth(n+1, 0);

    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    int root = 1;
    visited[root] = 1;
    depth[root] = 1;

    vector< int > st;
    st.push_back(root);

    while(!st.empty()){
        int cur = st.back();
        st.pop_back();
        cout << cur << " ";
        for(int i = 0; i < (int)graph[cur].size(); i++){
            int to = graph[cur][i];
            if(visited[to]!=1){
                visited[to] = 1;
                depth[to] = depth[cur] + 1;
                st.push_back(to);
            }
        }
    }
    cout << endl;
}
