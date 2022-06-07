#include <bits/stdc++.h>
using namespace std;

vector < int > cur_perm;

int cal_cost(vector < vector < int > > graph){

    cout << "Permutation: ";
    for(int i = 0; i < (int)cur_perm.size(); i++)
        cout << cur_perm[i];
    cout << "->";

    int total = 0;
    for(int i = 1; i < (int)cur_perm.size(); i++){
        total += graph[cur_perm[i-1]][cur_perm[i]];
    }
    cout << total << endl;
    return total;
}

int process(int n, int counter, vector < int > &visited, vector < vector < int > > &graph){

    int mini = 1e9 + 10;

    if(counter == n){
        int ans = cal_cost(graph);
        mini = min(mini, ans);
        return mini;
    }

    for(int i = 0; i < n; i++){
        if(visited[i] == 0){
            cur_perm.push_back(i);
            visited[i] = 1;
            int ans = process(n, counter+1, visited, graph);
            mini = min(mini, ans);

            visited[i] = 0;
            cur_perm.pop_back();
        }
    }
    return mini;
}

int main(){

    freopen("C:/data/travelling_sales_man_perm.txt", "r", stdin);

    int n;
    cin >> n;

    int m = n*(n-1);
    m /= 2;

    vector < vector < int > > graph(n, vector < int >(n, 0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int w;
            cin >> w;
            graph[i][j] = w;
        }
    }

    vector < int > visited(n, 0);
    int counter = 0;
    int min_cost = process(n, counter, visited, graph);
    cout << min_cost << endl;
}
