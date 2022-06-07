#include <bits/stdc++.h>
using namespace std;


typedef long long ll;

void preprocess_1(vector < int > &a, vector < int > &b){
    int n = (int)a.size();
    int m = (int)sqrt(n);
    b.assign(m, 0);
    for(int i = 0; i < n; i += m){
        for(int j = i; j < i+m; j++) b[i/m] += a[i];
    }
    return;
}

int query_1(vector < int > &a, vector < int > &b, int x, int y){
    int n = (int)a.size();
    int m = (int)b.size();

    int sum = 0, counter = 0;
    while(x%m!=0) sum += a[x++], counter++;
    while(x+m-1 <= y) sum += b[x/m], x += m, counter++;
    while(x <= y) sum += a[x++], counter++;
    return sum;
}

int main(){
    srand((int)time(NULL));
    int n = 16;
    int m = sqrt(n);

    vector < int > a(n, 0);
    for(int i = 0; i < n; i++) a[i] = rand()%10;
    for(int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
    vector < int > b;
    preprocess_1(a, b);
    while(1){
        int x, y;
        cin >> x >> y;
        int ans = query_1(a, b, x, y);
        cout << ans << endl;
    }
}
