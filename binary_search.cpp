#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){


    int n = 10;
    vector<int> A(n+1, 0);
    for(int i = 1; i <= n; i++) A[i] = rand()%10;
    sort(A.begin(), A.end());

    for(int i = 1; i <= n; i++) cout << A[i] << " "; cout << endl;

    while(1){
        int lo = 1, hi = n+1;
        int num;
        cin >> num;

        while(hi - lo > 1){
            int mid = (hi + lo)/2;
            if(A[mid] > num) hi = mid;
            else lo = mid;
        }

        if(A[lo] == num) cout << "Found" << endl;
        else cout << "!Found" << endl;
    }
}
