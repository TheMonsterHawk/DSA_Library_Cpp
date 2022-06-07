#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int gcd(int a, int b){
    return a==0? b : gcd(b%a, a);
}

int main(){
    int a, b;
    if(a > b) swap(a, b);

    for(int i = 1; i <= 10000; i++){
        for(int j = 1; j <= 10000; j++){
            int x = i, y = j;
            if(x > y) swap(x, y);
            if(gcd(x, y) != __gcd(x, y)) cout << "FUCK YOU" << endl;
        }
    }
}
