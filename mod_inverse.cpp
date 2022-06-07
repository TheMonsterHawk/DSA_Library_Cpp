#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int const MOD = 1e9 + 7;

ll bin_pow(ll x, ll y){
    ll result = 1;
    while(y > 0){
        if(y&1) result *= x;
        y/=2;
        x *= x;
        x %= MOD;
        result %= MOD;
    }
    return result;
}

int main(){
    for(int i = 1; i < 100; i++){
        cout << i << ": " << bin_pow(i, MOD-2) << endl;
    }
}

