#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

    freopen("C:/data/topological_sort.txt", "r", stdin);

    int n, m;
    cin >> n >> m;

    vector < vector < int > > graph(n);
    vector < int > visited(n, 0);
    vector < int > in_degree(n, 0);
    vector < int > arr;

    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        in_degree[y]++;
    }

    queue < int > q;

    for(int i = 0; i < n; i++){
        if(in_degree[i] == 0){
            q.push(i);
            arr.push_back(i);
        }
    }

    while(!q.empty()){
        vector < int > nex;
        for(int i = 0; !q.empty(); i++){
            int x = q.front();
            q.pop();
            for(int j = 0; j < (int)graph[x].size(); j++){
                int cur = graph[x][j];
                in_degree[cur]--;
                if(in_degree[cur] == 0){
                    nex.push_back(cur);
                }
            }
        }

        for(int i = 0; i < (int)nex.size(); i++){
            q.push(nex[i]);
            arr.push_back(nex[i]);
        }
    }

    for(int i = 0; i < (int)arr.size(); i++) cout << arr[i] << " "; cout << endl;
}
