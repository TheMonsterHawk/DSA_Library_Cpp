#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int const N = 1e7;
vector<int> A(N+1, 0); // we can sort numbers list where number <= 1e7

int main(){
    int n = 10;
    vector<int> a(10, 0);
    vector<int> b;
    for(int i = 0; i < n; i++) a[i] = rand()%10 + 1;
    for(int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;

    for(int i = 0; i < n; i++) A[a[i]]++;
    for(int i = 0; i <= N; i++){
        while(A[i] > 0){
            b.push_back(i);
            A[i]--;
        }
    }
    for(int i = 0; i < n; i++) cout << b[i] << " "; cout << endl;
}

