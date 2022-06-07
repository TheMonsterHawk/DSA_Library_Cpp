#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    srand((int)time(NULL));
    int n = 7, offset = (int)'a';
    string s = "aaaabaa";
    vector < int > a(n, 0), b(n, 0);
    cout << s << endl;

    for(int i = 1, l = 0, r = 0; i < n; i++){
        if(i <= r) a[i] = min(r-i+1, a[i-l]);
        while(i+a[i]<n and s[a[i]] == s[i+a[i]]) a[i]++;
        if(i+a[i]-1 > r) l = i, r = i+a[i]-1;
    }

    for(int i = 1; i < n; i++){
        while(i+b[i]<n and s[i+b[i]] == s[b[i]]) b[i]++;
    }

    for(int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
    for(int i = 0; i < n; i++) cout << b[i] << " "; cout << endl;
}
