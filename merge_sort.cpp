#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void merge_sort(vector<int> &a, int x, int y){

    if(x == y) return;

    int mid = (x + y)/2;
    merge_sort(a, x, mid);
    merge_sort(a, mid+1, y);

    vector<int> b(y-x+1, 0);
    int z = 0, l = x, r = mid+1;
    while(l <= mid and r <= y){
        b[z++] = a[l] < a[r]? a[l++] : a[r++];
    }
    while(l <= mid) b[z++] = a[l++];
    while(r <= y) b[z++] = a[r++];
    for(int i = x; i <= y; i++) a[i] = b[i-x];
    return;
}

int main(){
    int n = 10;

    vector<int> a(n, 0);

    for(int i = 0; i < n; i++) a[i] = n - i;
    for(int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
    merge_sort(a, 0, n-1);
    for(int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
}


