#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void insertion(vector < int > &a, int x, int y){

    for(int i = x; i <= y; i++){
        for(int j = i-1; j >= 0; j--){
            if(a[j] > a[j+1]) swap(a[j], a[j+1]);
            else break;
        }
    }
    /*
    bool sorted = true;
    for(int i = x; i < y; i++) if(a[i] > a[i+1]) sorted = false;
    cout << "sorted: ";
    if(sorted) cout << "YES" << endl;
    else cout << "NO" << endl;
    */
}

void merge_insertion_sort(vector < int > &a, int x, int y, int k){
    //if(y-x >= 1000) cout << x << " " << y << endl;
    int len = y-x+1;
    if(len <= k){
        insertion(a, x, y);
        return;
    }

    int mid = (x + y)/2;
    merge_insertion_sort(a, x, mid, k);
    merge_insertion_sort(a, mid+1, y, k);
    int l = x, r = mid+1, z = 0;
    vector < int > b(len);
    while(l <= mid and r <= y){
        if(a[l] < a[r]) b[z++] = a[l++];
        else b[z++] = a[r++];
    }
    while(l <= mid) b[z++] = a[l++];
    while(r <= y) b[z++] = a[r++];
    for(int i = x; i <= y; i++) a[i] = b[i-x];
    return;
}

int main(){
    srand((int)time(NULL));
    int n = 50000;
    int k = 16;
    vector < int > a(n, 0);
    for(int i = 0; i < n; i++){
        a[i] = rand()%10;
    }
    merge_insertion_sort(a, 0, n-1, k);

    //for(int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
    bool sorted = true;
    for(int i = 1; i < n; i++) if(a[i] < a[i-1]) sorted = false;
    cout << "sorted: ";
    if(sorted) cout << "YES" << endl;
    else cout << "NO" << endl;
}
