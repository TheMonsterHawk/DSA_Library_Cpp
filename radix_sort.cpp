#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n = 10;

    vector<int> a(n, 0), b(10, 0), c(n, 0);
    srand((int)time(NULL));
    for(int i = 0; i < n; i++) a[i] = rand()%10 0;
    for(int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
    int cur = 1;
    int pow = 4;

    for(int i = 0; i <= pow; i++){
        for(int j = 0; j < n; j++) b[(a[j]/cur)%10]++;
        for(int j = 1; j < 10; j++) b[j] += b[j-1];
        for(int j = n-1; j >= 0; j--) c[--b[(a[j]/cur)%10]] = a[j];
        a = c;
        b.assign(10, 0);
        cur *= 10;

    }
    for(int j = 0; j < n; j++) cout << a[j] << " "; cout << endl;
}
