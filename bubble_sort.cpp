#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n = 10;
    vector < int > a(n, 0);

    for(int i = 0; i < n; i++) a[i] = rand()%20;

    bool check_again = true;
    while(check_again){
        check_again = false;
        for(int i = 1; i < n; i++){
            if(a[i-1] > a[i]){
                swap(a[i-1], a[i]);
                check_again = true;
            }
        }
    }

    for(int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
}
