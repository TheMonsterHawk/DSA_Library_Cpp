#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    srand((int)time(NULL));
    int n = 10;

    vector < int > a(n, 0);

    for(int i = 0; i < n; i++) a[i] = rand()%10;
    for(int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;

    for(int i = 2; i <= n; i *= 2){
        for(int j = i; j >= 2; j/=2){
            for(int k = 0; k+j <= n; k++){
                int x = a[k], y = a[k+j-1];
                a[k] = min(x, y);
                a[k+j-1] = max(x, y);
            }
        }
    }

    for(int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
}
