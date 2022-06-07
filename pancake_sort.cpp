#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    srand((int)time(NULL));
    int n = 10;
    vector < int > a(n, 0);

    for(int i = 0; i < n; i++) a[i] = rand()%n;
    for(int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;

    function<void(vector < int > &a, int index)> rev = [&](vector < int > &a, int index){
        int i = 0, j = index;
        while(i < j){
            swap(a[i], a[j]);
            i++;
            j--;
        }
    };

    int j = n-1;
    while(j > 0){
        int maxi = 0;
        for(int i = 0; i <= j; i++){
            if(a[i] > a[maxi]){
                maxi = i;
            }
        }
        //cout << maxi << " " << a[maxi] << endl;
        rev(a, maxi);
        rev(a, j);
        //for(int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
        j--;
    }

    for(int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
}
