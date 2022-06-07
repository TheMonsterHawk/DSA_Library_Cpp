#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    srand((int)time(NULL));
    int n = 10;

    string s = "aaabaaabaa";

    vector < int > a(n, 0), b(n, 0);


    for(int i = 1; i < n; i++){
        int j = a[i-1];
        while(j>0 and s[i]!=s[j]) j = a[j-1];
        if(s[i] == s[j]) j++;
        a[i] = j;
    }


    for(int i = 1; i < n; i++){
        for(int j = 1; j <= i; j++){
            int k = 0, l = j;
            while(l <= i and s[k]==s[l]) l++, k++;
            if(l == i+1){
                b[i] = i-j+1;
                break;
            } else continue;
        }
    }

    cout << s << endl;
    for(int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
    for(int i = 0; i < n; i++) cout << b[i] << " "; cout << endl;
}
