#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void quick_sort(int x, int y, vector < int > &a){

    if(y-x <= 0) return;

    int mid = (x + y)/2;

    swap(a[mid], a[y]);

    int i = x, j = y-1;
    while(i < j){
        while(a[i] < a[y]) i++;
        while(a[j] > a[y]) j--;
        if(i < j) swap(a[i], a[j]);
    }
    for(int i = x; i <= y; i++) if(a[i] > a[y]){
        swap(a[y], a[i]);
        quick_sort(x, i-1, a);
        quick_sort(i+1, y, a);
        return;
    }
    quick_sort(x, y-1, a);
    return;

}

int main(){
    srand((int)time(NULL));

    int n = 1000;
    int limit = 1e9 + 1;
    vector < int > a(n, 0);

    for(int i = 0; i < n; i++) a[i] = rand()%limit;
    //for(int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
    quick_sort(0, n-1, a);
    //for(int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;

    bool sorted = true;
    for(int i = 1; i < n; i++){
        if(a[i] < a[i-1]){
            sorted = false;
            break;
        }
    }
    if(!sorted) cout << "NOT SORTED!" << endl;
    else cout << "SORTED" << endl;
}
