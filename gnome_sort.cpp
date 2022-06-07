#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    srand((int)time(NULL));

    int n = 10;
    vector < int > a(n, 0);

    for(int i = 0; i < n; i++) a[i] = rand()%n;
    for(int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
    int i = 1;

    while(i < n){
        if(i == 0) i++;
        if(a[i] >= a[i-1]) i++;
        else if(a[i] < a[i-1]) swap(a[i], a[i-1]), i--;
    }
    for(int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
}
