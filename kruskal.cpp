#include <bits/stdc++.h>
using namespace std;

typedef long ll;

vector < vector < int > > graph;
vector < int > final_tree; // contains ids of all edges in final tree;

class edge{
public:
    int x, y, w, id;

    bool operator< (edge a){
        return this->w < a.w;
    }

    bool operator> (edge a){
        return this->w > a.w;
    }
};

vector < int > parent;
vector < int > sz;

int find_parent(int x){
    return x==parent[x]? x : parent[x]=find_parent(parent[x]);
}

int find_size(int x){
    return sz[find_parent(x)];
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

int main(){

    freopen("C:/data/kruskal.txt", "r", stdin);

    int n, m;
    cin >> n >> m;

    vector < edge > E(m+1);

    for(int i = 1; i <= m; i++){
        int x, y, w;
        cin >> x >> y >> w;
        E[i].x = x;
        E[i].y = y;
        E[i].w = w;
        E[i].id = i;

        cout << i << " " << x << " " << y << endl;
    }

    cout << "Edge compare: " << (E[1] < E[2]) << endl;

    sort(E.begin() + 1, E.end());

    sz.assign(n+1, 1);
    parent.assign(n+1, 0);
    for(int i = 1; i <= n; i++) parent[i] = i;

    int max_size = 0, total_weight = 0;

    for(int i = 1; i <= m; i++){
        int x = E[i].x, y = E[i].y;

        if(same_comp(x, y)) continue;
        if(max_size == n) break;

        x = find_parent(x);
        y = find_parent(y);
        final_tree.push_back(E[i].id);
        total_weight += E[i].w;

        merge_comp(x, y);
        max_size = find_size(x);
    }

    cout << "Total weight of minimum spanning tree: " << total_weight << endl;
    cout << "Edge ids and weight and vertices in final tree: " << endl;

    for(int i = 0; i < (int)final_tree.size(); i++){
        int id = final_tree[i];
        cout << id << endl;
    }
}
