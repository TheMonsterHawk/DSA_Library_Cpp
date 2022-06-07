#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

    freopen("C:/data/knapsack.txt", "r", stdin);

    int n = 4;
    cin >> n;
    vector < int > values(n+1, 0), weight(n+1, 0);

    for(int i = 1; i <= n; i++) cin >> values[i];
    for(int i = 1; i <= n; i++) cin >> weight[i];

    int W = 100;
    cin >> W;

    int dp[n+1][W+1];
    memset(dp, 0, sizeof(dp));

    for(int i = 0; i <= n; i++){
        for(int w = 0; w <= W; w++){

            if(i == 0 || w == 0){
                dp[i][w] = 0;
                continue;
            } else if(weight[i] <= w){
                dp[i][w] = max(values[i] + dp[i-1][w-weight[i]], dp[i-1][w]);
            } else dp[i][w] = dp[i-1][w];
        }
    }

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= W; j++){
            if(dp[i][j] < 10) cout << "0";
            cout << dp[i][j] << " ";
        } cout << endl;
    }

    cout << dp[n][W] << endl;
}
