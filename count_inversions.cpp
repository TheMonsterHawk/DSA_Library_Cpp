#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int counting_sort_naive(vector < int > &a){
    int counter = 0;
    int n = (int)a.size();
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(a[j] < a[i]) counter += 1;
        }
    }
    return counter;
}

void merge_sort(int x, int y, vector < int > &a, int &counter){
    if(y - x < 1) return;
    int mid = (x + y)/2;
    merge_sort(x, mid, a, counter);
    merge_sort(mid+1, y, a, counter);

    vector < int > b(y-x+1, 0);
    int l = x, r = mid+1, z = 0;

    while(l <= mid and r <= y){
        if(a[l] <= a[r]) b[z++] = a[l++];
        else{
            counter += mid + 1 - l;
            b[z++] = a[r++];
        }
    }
    while(l <= mid){
        b[z++] = a[l++];
    }
    while(r <= y){
        b[z++] = a[r++];
    }
    for(int i = x; i <= y; i++) a[i] = b[i-x];
    return;
}

int main(){
    srand((int)time(NULL));

    int n = 10;
    vector < int > a(n, 0);
    for(int i = 0; i < n; i++) a[i] = rand()%n;
    for(int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;


    cout << counting_sort_naive(a) << endl;

    int counter = 0;
    merge_sort(0, n-1, a, counter);
    for(int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
    cout << counter << endl;

}
