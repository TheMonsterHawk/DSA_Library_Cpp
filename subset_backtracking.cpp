#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector < int > subset;
vector < int > a;
int n;
void print(){
    for(int i = 0; i < n; i++){
        if(subset[i] == 0){
            //cout << " " << " ";
        } else {
            cout << a[i] << " ";
        }
    } cout << endl;
}

void print_subset(vector < int > a, int cur){
    if(cur == n-1){
        subset[cur] = 1;
        print();
        subset[cur] = 0;
        print();
        return;
    } else {
        subset[cur] = 1;
        print_subset(a, cur+1);
        subset[cur] = 0;
        print_subset(a, cur+1);
    }
}

int main(){

    n = 5;
    a.assign(n, 0);
    subset.assign(n, 0);
    for(int i = 0; i < n; i++) a[i] = i+1;

    int cur = 0;
    print_subset(a, cur);
}
