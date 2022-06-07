#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n = 10;
    vector < int > a(n, 0);

    for(int i = 0; i < n; i++) a[i] = rand()%100;
    for(int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;

    for(int i = 1; i < n; i++){
        int index = lower_bound(a.begin(), a.begin()+ i-1, a[i]) - a.begin();
        int t = a[i];
        for(int j = index; j < i; j++) a[j+1] = a[j];
        a[index] = t;
    }

    for(int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
}
