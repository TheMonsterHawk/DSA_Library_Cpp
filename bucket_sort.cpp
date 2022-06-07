#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    srand((int)time(NULL));
    int n = 1000;
    vector < int > a(n, 0);

    for(int i = 0; i < n; i++) a[i] = rand()%n;
    for(int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;

    int mini = 1e9, maxi = 0;
    for(int i = 0; i < n; i++) mini = min(mini, a[i]), maxi = max(maxi, a[i]);

    int range = (maxi - mini)/n;
    if(range < 1) range += 1;

    vector < vector < int > > bucket(n+1);

    for(int i = 0; i < n; i++){
        int x = (a[i] - mini)/range;
        bucket[x].push_back(a[i]);
    }

    for(int i = 0; i <= n; i++){
        if((int)bucket[i].size() <= 1) continue;

        vector < int > b = bucket[i];
        int m = (int)b.size();
        for(int j = 1; j < m; j++){
            while(b[j-1] > b[j]) swap(b[j-1], b[j]);
        }
        for(int j = 0; j < m; j++) bucket[i][j] = b[j];
    }

    int k = 0;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j < (int)bucket[i].size(); j++) a[k++] = bucket[i][j];
    }
    for(int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
    bool sorted = true;
    for(int i = 1; i < n; i++) if(a[i] < a[i-1]) sorted = false;
    cout << "Sorted: ";
    if(sorted) cout << "YES" << endl;
    else cout << "NO" << endl;

}
