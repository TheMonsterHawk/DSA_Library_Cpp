#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

    srand((int)time(NULL));

    int n = 10, sum;
    sum = rand()%20;
    cin >> n >> sum;

    vector< vector < int > > dp(n+1, vector < int > (sum+1, 0));

    vector < int > a(n+1, 0);

    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 0; i <= n; i++) dp[i][0] = 1;

    for(int j = 1; j <= sum; j++){
        for(int i = 1; i <= n; i++){
            dp[i][j] += dp[i-1][j];
            if(j-a[i] >= 0) dp[i][j] += dp[i-1][j-a[i]];
        }
    }

    cout << dp[n][sum] << endl;

}
