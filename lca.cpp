#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

    freopen("C:/data/input.txt", "r", stdin);

    int n, m;
    cin >> n >> m;

    vector< pair<int,int> > graph[n+1];
    vector<int> distance(n+1, 1e9 + 10);

    for(int i = 0; i < m; i++){
        int x, y, w;
        cin >> x >> y >> w;
        graph[x].push_back({y, w});
        graph[y].push_back({x, w});
    }

    int root = 1;
    distance[root] = 0;

    priority_queue< pair<int,int>, vector< pair<int,int> >, greater<pair<int,int>> > pq;

    pq.push({0, root});

    while(!pq.empty()){
        int cur = pq.top().second;
        int dis = pq.top().first;
        pq.pop();

        if(distance[cur] != dis){
            continue;
        }

        for(int i = 0; i < (int)graph[cur].size(); i++){
            int to = graph[cur][i].first;
            int w = graph[cur][i].second;
            if(distance[to] > w + dis){
                distance[to] = w + dis;
                pq.push({distance[to], to});
            }
        }
    }

    for(int i = 1; i <= n; i++) cout << distance[i] << " "; cout << endl;
}
