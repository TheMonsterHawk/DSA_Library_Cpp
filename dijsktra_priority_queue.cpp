#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n, m;
    cin >> n >> m;

    vector< vector<pair<int, int> > > graph(n+1);
    vector<int> distance(n+1, 1e9 + 10);
    priority_queue< pair<int, int>, vector< pair<int, int> >, greater<pair<int, int> > > pq;

    for(int i = 0; i < m; i++){
        int x, y, w;
        cin >> x >> y >> w;

        graph[x].push_back({y, w});
        graph[y].push_back({x, w});
    }

    int root = 1;
    distance[root] = 0;
    pq.push({0, root});

    while(!pq.empty()){
        int source = pq.top().second;
        int dis = pq.top().first;

        pq.pop();

        if(dis != distance[source]){
            continue;
        }

        for(int i = 0; i < (int)graph[source].size(); i++){
            int cur = graph[source][i].first;
            int w = graph[source][i].second;

            if(distance[cur] > w + dis){
                distance[cur] = w + dis;
                pq.push({distance[cur], cur});
            }
        }
    }

    for(int i = 1; i <= n; i++) cout << distance[i] << " "; cout << endl;

}
