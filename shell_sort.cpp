#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    srand((int)time(NULL));
    int n = 10;

    vector < int > a(n, 0);

    for(int i = 0; i < n; i++) a[i] = rand()%n;
    for(int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;

    int interval = 8;
    while(interval > 0){
        for(int i = interval; i < n; i++){
            for(int j = i ; j >= interval; j-=interval){
                if(a[j] < a[j-interval]) swap(a[j], a[j-interval]);
            }
        }
        interval /= 2;
    }

    for(int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
}
