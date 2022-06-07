#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

    srand((int)time(NULL));
    int test = 1;
    while(test--){
        int n = 256;
        int m = sqrt(n);

        vector < int > a(n, 0);
        for(int i = 0; i < n; i++) a[i] = rand()%1000;

        sort(a.begin(), a.end());

        int found = -1;
        int start = 0;
        int value = a[rand()%n];
        for(int i = m; i < n; i += m){
            if(a[i] > value) break;
            else start = i;
        }
        for(int i = start; i < start + m and i < n; i++){
            if(a[i] == value){
                found = i;
                break;
            }
        }
        if(found == -1) cout << "Not Found!" << endl;
        else ++counter;
    }
}
