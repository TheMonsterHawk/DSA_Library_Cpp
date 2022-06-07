#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
//1


int main(){

    freopen("C:/data/travelling_sales_man_perm.txt", "r", stdin);

    int n;
    cin >> n;

    int m = 1 << n;

    vector < vector < int > > graph(n, vector < int > (n, 0));
    vector < vector < int > > dp(m+1, vector < int >(n, 1e9 + 10));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> graph[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        int mask = 1<<i;
        dp[mask][i] = 0;
    }

    for(int mask = 0; mask < m; mask++){
        for(int i = 0; i < n; i++) if(mask & (1<<i)){
            for(int j = 0; j < n; j++) if(!(mask & (1<<j))){
                int next_mask = mask + (1<<j);
                dp[next_mask][j] = min(dp[next_mask][j], dp[mask][i] + graph[i][j]);
            }
        }
    }
    int min_cost = 1e9 + 10;

    for(int i = 0; i < n; i++) min_cost = min(min_cost, dp[m-1][i]);
    cout << min_cost << endl;
}
