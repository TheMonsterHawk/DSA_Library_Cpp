#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

    srand((int)time(NULL));
    int n = 100;
    vector < int > a(n, 0);

    for(int i = 0; i < n; i++) a[i] = rand()%n;

    bool sorted = false;

    while(!sorted){
        sorted = true;
        for(int i = 0; i < n-1; i+=2) if(a[i] > a[i+1]){
            sorted = false;
            swap(a[i], a[i+1]);
        }

        for(int i = 1; i < n; i += 2) if(a[i] > a[i+1]){
            sorted = false;
            swap(a[i], a[i+1]);
        }
    }

    for(int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;

    sorted = true;
    for(int i = 0; i < n-1; i++) if(a[i] > a[i+1]) sorted = false;
    cout << "Sorted: ";
    if(sorted) cout << "YES" << endl;
    else cout << "NO" << endl;

}
