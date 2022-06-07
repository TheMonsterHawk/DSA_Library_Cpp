#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    srand((int)time(NULL));

    int n = 10;
    vector < int > a(n, 0);

    for(int i = 0; i < n; i++) a[i] = rand()%10;
    for(int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;

    function< bool() > fun = [&](){
        for(int i = 1; i < n; i++) if(a[i] < a[i-1]) return false;
        return true;
    };

    while(!fun()){
        next_permutation(a.begin(), a.end());
    }

    for(int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
}
