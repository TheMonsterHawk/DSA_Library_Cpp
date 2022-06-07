#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    srand((int)time(NULL));
    int n = 10;

    vector < int > a(n, 0);

    for(int i = 0; i < n; i++) a[i] = rand()%10;
    for(int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
    int m = 0;
    for(int i = 0; i < n; i++) m = max(m, a[i]);
    int bead[n][m];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < a[i]; j++) bead[i][j] = 1;
        for(int j = a[i]; j < m; j++) bead[i][j] = 0;
    }

    for(int j = 0; j < m; j++){
        int t = 0;
        for(int i = 0; i < n; i++) t += bead[i][j];
        for(int i = n-1; i >= n-t; i--) bead[i][j] = 1;
        for(int i = n-t-1; i >= 0; i--) bead[i][j] = 0;
    }
    vector < int > b(n, 0);

    for(int i = 0; i < n; i++){
        int e = 0;
        for(int j = 0; j < m; j++) e += bead[i][j];
        b[i] = e;
    }

    for(int i = 0; i < n; i++) cout << b[i] << " "; cout << endl;
    return 0;
}
