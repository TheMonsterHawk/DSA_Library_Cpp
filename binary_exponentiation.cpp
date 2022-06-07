#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll pow(ll x, ll y, ll M = 1e9 + 7){
    if(y == 0) return 1;

    ll z = pow(x*x%M, y/2)%M;
    z = z*(y&1? x : 1)%M;
    return z;
}

int main(){
    int a = 1234567890, b = 10000000;
    int M = 1e9 + 7;
    int ans = pow(a, b, M);
    ll t = 1;

    for(int i = 1; i <= b; i++){
        t *= a;
        t %= M;
    }

    cout << ans << endl;
    cout << t << endl;
}
