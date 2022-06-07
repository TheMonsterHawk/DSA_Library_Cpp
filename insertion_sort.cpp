#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    srand((int)time(NULL));
    int n = 10;

    vector < int > a(n, 0);

    for(int i = 0; i < n; i++) a[i] = rand()%20;

    for(int i = 0; i < n; i++){
        for(int j = i; j > 0 and a[j-1] > a[j]; j--){
            swap(a[j], a[j-1]);
        }
    }
    for(int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
}
