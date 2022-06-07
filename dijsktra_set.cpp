#include <bits/stdc++.h>
using namespace std;

typedef long long ll;



int main(){
    int n, m;
    cin >> n >> m;

    vector< vector< pair<int, int> > > graph;
    vector<int> distance;
    set< pair<int, int> > st;

    graph.assign(n+1, vector< pair<int, int> >(0));
    distance.assign(n+1, 1e9 + 10);

    for(int i = 0; i < m; i++){
        int x, y, w;
        cin >> x >> y >> w;
        graph[x].push_back({y, w});
        graph[y].push_back({x, w});
    }

    int root = 1;
    distance[root] = 0;
    st.insert({0, root});

    while(!st.empty()){
        int source = st.begin()->second;
        st.erase(st.begin());

        for(int i = 0; i < (int)graph[source].size(); i++){
            int cur = graph[source][i].first;
            int w = graph[source][i].second;

            if(distance[cur] > distance[source] + w){
                st.erase({distance[cur], cur});
                distance[cur] = distance[source] + w;
                st.insert({distance[cur], cur});
            }
        }
    }

    for(int i = 1; i <= n; i++) cout << distance[i] << " "; cout << endl;
}
