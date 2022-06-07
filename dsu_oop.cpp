#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class DSU{

    int n;
    vector < int > parent;
    vector < int > size_of_comp;

public:

    DSU(int n){
        this->n = n;
        parent.assign(n+1, 0);
        size_of_comp.assign(n+1, 0);
        for(int i = 1; i <= n; i++){
            parent[i] = i;
            size_of_comp[i] = 1;
        }
    }

    int find_parent(int x){
        return parent[x]==x? x : x=find_parent(parent[x]);
    }

    int connect_comp(int x, int y){
        x = find_parent(x);
        y = find_parent(y);

        if(x == y) return 0;
        if(size_of_comp[y] > size_of_comp[x]) swap(x, y);

        size_of_comp[x] += size_of_comp[y];
        parent[y] = x;
        return 1;
    }

    int find_size(int x){
        x = find_parent(x);
        return size_of_comp[x];
    }

    bool same_comp(int x, int y){
        x = find_parent(x);
        y = find_parent(y);
        return x==y;
    }
};

int main(){

    int n = 10;
    DSU dsu(n);
    while(1){
        int type;
        cin >> type;
        if(type == 1){
            //connet two components
            int x, y;
            cin >> x >> y;
            dsu.connect_comp(x, y);
        } else if(type == 2){
            //print parent of element
            int x;
            cin >> x;
            cout << dsu.find_parent(x) << endl;
        } else if(type == 3){
            //print size of comp which element x is part of
            int x;
            cin >> x;
            cout << dsu.find_size(x) << endl;
        }
    }
}
