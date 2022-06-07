#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

    srand((int)time(NULL));

    int n = 10;

    vector < int > a(n, 0);

    for(int i = 0; i < n; i++) a[i] = rand()%n;
    for(int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;

    int gap = n;
    while(gap > 0){
        for(int i = 0; i+gap < n; i++){
            if(a[i] > a[i+gap]) swap(a[i], a[i+gap]);
        }
        if(gap > 1) gap = max(gap/1.3, (double)1);
        else gap = 0;
    }

    for(int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
}
