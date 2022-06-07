#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector< vector<int> > tree;
vector<int> p, tin, tout;
vector< vector<int> > A;
int n;
int counter = 0;

void dfs(int source, int par){
    p[source] = par;
    A[source][0] = par;
    tin[source] = ++counter;
    for(int i = 0; i < (int)tree[source].size(); i++){
        int cur = tree[source][i];
        if(cur == par) continue;
        dfs(cur, source);
    }
    tout[source] = ++counter;
    return;
}

bool is_parent(int x, int y){
    if(x == 0) return 1;
    return tin[x] <= tin[y] and tout[y] <= tout[x];
}

void pre(){
    for(int j = 1; j < 20; j++){
        for(int i = 1; i <= n; i++){
            A[i][j] = A[A[i][j-1]][j-1];
        }
    }
    return;
}

int query(int x, int y){
    if(is_parent(x, y)) return x;
    else if(is_parent(y, x)) return y;
    for(int j = 20; j >= 0; j--){
        if(!is_parent(A[x][j], y)){
            x = A[x][j];
        }
    }
    return A[x][0];
}

int main(){

    freopen("C:/data/tree.txt", "r", stdin);

    cin >> n;

    tree.assign(n+1, vector<int>(0, 0));
    A.assign(n+1, vector<int>(20, 0));
    p.assign(n+1, 0);
    tin.assign(n+1, 0);
    tout.assign(n+1, 0);

    for(int i = 0; i < n-1; i++){
        int x, y;
        cin >> x >> y;

        tree[x].push_back(y);
        tree[y].push_back(x);
    }

    int root = 1;
    dfs(root, root);
    pre();

    freopen("CON", "r", stdin);

    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 3; j++){
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    while(1){
        int x, y;
        cin >> x >> y;
        cout << query(x, y) << endl;
    }
}
