#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector < int > parent;
vector < int > sz;

int find_parent(int x){
    return parent[x]==x? x : parent[x]=find_parent(parent[x]);
}

int merge_comp(int x, int y){
    x = find_parent(x);
    y = find_parent(y);

    if(x == y) return 0;
    else if(sz[y] > sz[x]) swap(x, y);

    sz[x] += sz[y];
    parent[y] = x;
    return 1;
}

bool same_comp(int x, int y){
    x = find_parent(x);
    y = find_parent(y);
    return x == y;
}

int find_sz(int x){
    x = find_parent(x);
    return sz[x];
}

int main(){

    freopen("C:/data/dsu.txt", "r", stdin);

    int n;
    cin >> n;

    parent.assign(n+1, 0);
    sz.assign(n+1, 1);

    for(int i = 1; i <= n; i++) parent[i] = i;

    int q;
    cin >> q;

    for(int i = 1; i <= q; i++){
        int type;
        cin >> type; // 1 for connecting two comp, 2 for finding parent of particular component
                     // 3 for finding the size of component which's member is given in input
        if(type == 1){
            int x, y;
            cin >> x >> y;
            merge_comp(x, y);
        } else if(type == 2){
            int x;
            cin >> x;
            cout << find_parent(x) << endl;
        } else if(type == 3){
            int x;
            cin >> x;
            cout << find_sz(x) << endl;
        }
    }
}
