#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    srand((int)time(NULL));
    int n = 10;
    int lo = 0, mid = 0, hi = n-1;

    vector < int > a(n, 0);
    for(int i = 0; i < n; i++) a[i] = rand()%3;
    for(int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;

    while(mid <= hi){
        switch (a[mid]){
        case 0:
            swap(a[lo++], a[mid++]);
            break;

        case 1:
            mid++;
            break;

        case 2:
            swap(a[mid], a[hi--]);
        }
    }

    for(int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
}
