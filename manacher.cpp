#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    string s = "ababaaaabba";
    int n = (int)s.size();

    string t = "";
    int m = 2*n+1;
    for(int i = 0; i < m; i++){
        if(i%2==0) t += "#";
        else t += s[i/2];
    }

    vector < int > len(m, 0);
    int l = 0, r = -1;
    for(int i = 0; i < m; i++){
        len[i] = min(r-i, len[l+r-i]);
        if(len[i] < 0) len[i] = 0;
        while(i+len[i] < m and i-len[i]>=0 and t[i+len[i]]==t[i-len[i]]) len[i]++;
        if(r < i+len[i]-1){
            r = i+len[i];
            l = i-len[i];
        }
    }

    for(int i = 0; i < m; i++) len[i] = 2*len[i]-1;

    vector < int > odd(n, 0);
    for(int i = 1; i < m; i+=2){
        odd[i/2] = (len[i]-1)/2;

    }

    vector < int > even(n, 0); //i and i+1 are center of palindrome
    for(int i = 1; i < m; i+=2){
        even[i/2] = len[i+1]/2;
    }


    for(int i = 0; i < m; i++) cout << " " << t[i] << " "; cout << endl;
    for(int i = 0; i < m; i++) cout << (len[i]<=9? "0" : "") <<  len[i] << " ";
    cout << "\n\n";

    for(int i = 0; i < n; i++) cout << s[i] << " "; cout << endl;
    for(int i = 0; i < n; i++) cout << odd[i] << " "; cout << endl;
    for(int i = 0; i < n; i++) cout << even[i] << " "; cout << endl;
}
