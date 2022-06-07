#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
///find second minimum of the array
int main(){
    int n;
    cin >> n;
    vector < int > a(n, 0);

    int first_min = 1e9 + 10;
    int second_min = first_min;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] < first_min){
            second_min = first_min;
            first_min = a[i];
        } else if(a[i] < second_min){
            second_min = a[i];
        }
    }
    cout << second_min << endl;

}
