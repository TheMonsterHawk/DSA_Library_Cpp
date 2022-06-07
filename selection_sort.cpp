#include <bits/stdc++.h>
using namespace std;

typedef long ll;

int main(){
    srand((int)time(NULL));

    int n = 10;
    vector < int > a(n, 0);

    for(int i = 0; i < n; i++) a[i] = rand()%10;
    for(int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;

    for(int i = 0; i < n-1; i++){
        int index = i;
        for(int j = i; j < n; j++){
            if(a[j] < a[index]){
                index = j;
            }
        }
        swap(a[i], a[index]);
    }
    for(int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
}
