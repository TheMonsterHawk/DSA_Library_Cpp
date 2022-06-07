#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    srand((int)time(NULL));
    int n = 10;
    vector < int > a(n, 0);

    for(int i = 0; i < n; i++) a[i] = rand()%n;
    for(int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;

    int mini = 1e9, maxi = 0;
    for(int i = 0; i < n; i++) maxi = max(maxi, a[i]), mini = min(mini, a[i]);
    int m = (maxi - mini + 1);
    vector < int > b(m, 0);
    vector < int > c;
    for(int i = 0; i < n; i++) b[a[i]-mini]++;

    for(int j = mini; j <= maxi; j++){
        while(b[j-mini] > 0){
            c.push_back(j);
            b[j-mini]--;
        }
    }
    for(int i = 0; i < n; i++) cout << c[i] << " "; cout << endl;
}
