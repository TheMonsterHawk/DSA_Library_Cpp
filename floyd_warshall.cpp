#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

    freopen("C:/data/floyd_warshall.txt", "r", stdin);

    int n, m;
    cin >> n >> m;

    int inf = 1e9 + 10;
    vector < vector < int > > graph(n, vector < int > (n, 0));
    vector < vector < int > > shortest_path(n, vector < int > (n, 0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            graph[i][j] = i==j? 0: inf;
            shortest_path[i][j] = i==j? 0: inf;
        }
    }

    for(int i = 0; i < m; i++){
        int x, y, w;
        cin >> x >> y >> w;
        x--;
        y--;
        graph[x][y] = w;
    }


    for(int source = 0; source < n; source++){
        for(int aux = 0; aux < n; aux++){
            for(int dest = 0; dest < n; dest++){
                shortest_path[source][dest] = min(shortest_path[source][dest],
                                                  shortest_path[source][aux] + graph[aux][dest]);
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << shortest_path[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
