#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int naive_lis(vector<int> &A){
    int n = (int)A.size();

    vector<int> dp(n+1, 1);
    vector<int> par(n+1, 0);

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(A[j] > A[i]){
                if(dp[i]+1 > dp[j]){
                    par[j] = i;
                    dp[j] = dp[i] + 1;
                }
            }
        }
    }
    int maxi = 0, start = 0;
    for(int i = 0; i < n; i++){
        if(maxi < dp[i]){
            maxi = dp[i];
            start = i;
        }
    }
    vector<int> ans(1, A[start]);
    while((int)ans.size() < maxi){
        start = par[start];
        ans.push_back(A[start]);
    }
    reverse(ans.begin(), ans.end());
    cout << "naive: ";
    cout << maxi << endl;
    for(int i = 0; i < (int)ans.size(); i++) cout << ans[i] << " "; cout << endl;
    return maxi;
}

int main(){

    int n = 10;
    vector<int> A(n+1, 0), lis(n+1, 0);
    int len = 0;

    srand((int)time(NULL));
    for(int i = 0; i < n; i++) A[i] = rand()%100;
    for(int i = 0; i < n; i++) cout << A[i] << " "; cout << endl;

    lis[len++] = A[0];

    for(int i = 1; i < n; i++){
        if(A[i] > lis[len-1]){
            lis[len++] = A[i];
        } else {
            auto it = lower_bound(lis.begin(), lis.begin() + len, A[i]);
            int index = it - lis.begin();
            lis[index] = A[i];
        }
    }
    naive_lis(A);

    cout << "optimized: ";
    cout << len << endl;
    for(int i = 0; i < len; i++) cout << lis[i] << " "; cout << endl;
}
