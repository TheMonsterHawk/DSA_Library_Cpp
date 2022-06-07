#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class dsu{
    int n;
    vector < int > parent;
    vector < int > size_of_component;

public:
    dsu(int n){
        parent.assign(n, 0);
        size_of_component.assign(n, 1);

        for(int i = 0; i < n; i++) parent[i] = i;
    }

    int find_parent(int x){
        return x==parent[x]? x : parent[x]=find_parent(parent[x]);
    }

    int merge_component(int x, int y){
        x = find_parent(x);
        y = find_parent(y);
        if(x == y) return 0;

        if(size_of_component[y] > size_of_component[x]) swap(x, y);

        parent[y] = x;
        size_of_component[x] += size_of_component[y];
        return 1;
    }
};

int main(){

    freopen("C:/data/connected_components_dsu.txt", "r", stdin);

    int n, m;
    cin >> n >> m;
    //cout << n << " " << m << endl;
    vector < vector < int > > graph(n);
    dsu f(n);

    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        x--;y--;
        //cout << x << " " << y << endl;
        graph[x].push_back(y);
        graph[y].push_back(x);
        f.merge_component(x, y);
    }
    set<int> st;

    for(int i = 0; i < n; i++) st.insert(f.find_parent(i));
    //for(auto it = st.begin(); it!=st.end(); it++) cout << (*it) << " "; cout << endl;

    cout << "number of components: " << (int)st.size() << endl;

}
