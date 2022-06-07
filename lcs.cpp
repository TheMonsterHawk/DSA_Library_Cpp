#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n = 30, m = 30;
    string a, b;
    srand((int)time(NULL));
    for(int i = 0; i < n; i++){
        char x = 'a' + rand()%26;
        a += x;
    }

    for(int j = 0; j < m; j++){
        char x = 'a' + rand()%26;
        b += x;
    }
    cout << a << endl;
    cout << b << endl;

    int dp[n+1][m+1], parx[n+1][m+1], pary[n+1][m+1];

    memset(dp, 0, sizeof(dp));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(dp[i][j-1] > dp[i-1][j]){
                dp[i][j] = dp[i][j-1];
                parx[i][j] = i;
                pary[i][j] = j-1;
            } else {
                dp[i][j] = dp[i-1][j];
                parx[i][j] = i-1;
                pary[i][j] = j;
            }

            if(a[i-1] != b[j-1]) continue;

            if(dp[i-1][j-1] + 1 > dp[i][j]){
                dp[i][j] = dp[i-1][j-1] + 1;
                parx[i][j] = i-1;
                pary[i][j] = j-1;
            }
        }
    }

    cout << dp[n][m] << endl;

    int x = n, y = m;

    string ans;
    while((int)ans.size() < dp[n][m]){
        if(parx[x][y]!=x and pary[x][y]!=y){
            ans += a[x-1];
        }
        int newx = parx[x][y];
        int newy = pary[x][y];
        x = newx;
        y = newy;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;

}
