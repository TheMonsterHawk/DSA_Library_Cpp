#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    srand((int)time(NULL));
    int n = 10;

    vector < int > a(n, 0);
    for(int i = 0; i < n; i++) a[i] = rand()%n;
    for(int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;

    int no_swap = 0;
    while(no_swap == 0){
        no_swap = 1;
        for(int i = 1; i < n; i++){
            if(a[i] < a[i-1]){
                swap(a[i-1], a[i]);
                no_swap = 0;
            }
        }
        for(int i = n-2; i >= 0; i--){
            if(a[i] > a[i+1]){
                swap(a[i], a[i+1]);
                no_swap = 0;
            }
        }
    }

    for(int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
}
