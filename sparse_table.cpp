#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int M = 19;
int N = (1<<20);
int main(){
    int n = 10;
    vector<int> A(n, 0);

    for(int i = 0; i < n; i++) A[i] = rand()%100;
    for(int i = 0; i < n; i++) cout << A[i] << " ";
    cout << endl;

    int m = (int)log2(n) + 1;

    vector< vector<int> > sp(4*n, vector<int>(m, 0));

    for(int j = 0; j < m; j++){
        for(int i = 0; i < n; i++){
            if(j == 0) sp[i][j] = A[i];
            else{
                int x = i + (1<<(j-1));
                sp[i][j] = max(sp[i][j-1], sp[x][j-1]);
            }
        }
    }

    for(int x = 0; x < n; x++){
        for(int y = x; y < n; y++){
            int total = y-x+1;
            int num = 1, t = 0;
            while(2*num <= total){
                num*=2;
                t++;
            }

            int z = y - (1<<t) + 1;
            cout << max(sp[x][t], sp[z][t]) << " ";
        }
        cout << endl;
    }

    return 0;
}
