#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int start = -1;
vector < int > ans;
int n;
bool find_hamiltonian_cycle(int source, vector < vector < int > > &graph, vector < int > &visited, int counter){
    if(visited[source]) return false;
    visited[source] = 1;
    counter++;
    ans.push_back(source);
    //cout << source << " " << counter << endl;
    if(counter == n){
        ans.push_back(start);
        return graph[source][start];
    }

    for(int i = 0; i < n; i++){
        if(graph[source][i]){
            if(find_hamiltonian_cycle(i, graph, visited, counter)){
                return true;
            }
        }
    }
    visited[source] = 0;
    counter--;
    ans.pop_back();
    return false;

}

int main(){

    freopen("C:/data/hamiltonian_cycle.txt", "r", stdin);

    int m;
    cin >> n >> m;

    vector < vector < int > > graph;
    vector < int > visited;
    int counter = 0;

    graph.assign(n+1, vector < int > (n+1, 0));
    visited.assign(n+1, 0);

    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        x--;y--;
        graph[x][y] = 1;
        graph[y][x] = 1;
    }


    for(int i = 0; i < n; i++){
        start = i;
        if(find_hamiltonian_cycle(i, graph, visited, counter)){
            cout << "cycle found!" << endl;
        }
    }
    cout << (int)ans.size() << endl;
    for(int i = 0; i < (int)ans.size(); i++) cout << ans[i]+1 << " "; cout << endl;
}
