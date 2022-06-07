#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n = 10;
    vector < int > a(n);

    srand((int)time(NULL));
    for(int i = 0; i < n; i++) a[i] = rand()%11 - 5;
    for(int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;

    int max_sum = 0;
    int cur_sum = 0;
    for(int i = 0 ; i < n; i++){
        if(cur_sum + a[i] > 0){
            cur_sum += a[i];
            max_sum = max(max_sum, cur_sum);
        } else cur_sum = 0;
    }
    cout << max_sum << endl;
}
