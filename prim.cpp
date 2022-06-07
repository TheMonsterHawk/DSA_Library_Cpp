#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class edge{
public:
    int x, y, w;
    int index;

    edge(int a, int b, int c, int d){
        this->x = a;
        this->y = b;
        this->w = c;
        this->index = d;
    }

    bool operator() (const edge b){
        return this->w < b.w;
    }
};

int main(){

    freopen("C:/data/prim.txt", "r", stdin);

    int n, m;
    cin >> n >> m;

    int total_nodes = 0;
    int mst_weight = 0;
    vector < int > mst(n, 0);
    vector < pair < int , int > > mst_edges;
    vector < vector < int > > graph(n);
    vector < vector < int > > weight(n);
    vector < vector < int > > index_of_edge(n);

    for(int i = 0; i < m; i++){
        int x, y, w;
        cin >> x >> y >> w;
        graph[x].push_back(y);
        graph[y].push_back(x);
        weight[x].push_back(w);
        weight[y].push_back(w);
        index_of_edge[x].push_back(i);
        index_of_edge[y].push_back(i);
        //cout << x << " " << y << " " << w << endl;
    }

    auto func = [](const edge a, const edge b){
        return (a.w < b.w) or (a.w==b.w and a.index < b.index);
    };

    set < edge, decltype(func) > st(func);


    int root = 0;
    mst[root] = 1;
    total_nodes++;
    for(int i = 0; i < (int)graph[root].size(); i++){
        st.insert(edge(root, graph[root][i], weight[root][i], index_of_edge[root][i]));
    }

    //freopen("CON", "r", stdin);
    while(total_nodes < n){

        for(auto it = st.begin(); it!=st.end(); it++){
            edge temp = *it;
            //cout << temp.x << "->" << temp.y << " | ";
        }
        edge cur = *st.begin();
        st.erase(st.begin());

        if(mst[cur.x]==1 and mst[cur.y]==1){
            continue;
        }

        if(mst[cur.y]==1) swap(cur.x, cur.y);
        mst_edges.push_back({cur.x, cur.y});

        mst[cur.y] = 1;
        //cout << cur.x << " " << cur.y << " included in this term!" << endl;

        total_nodes++;
        mst_weight += cur.w;
        for(int i = 0; i < (int)graph[cur.y].size(); i++){
            int a = cur.y, b = graph[cur.y][i], c = weight[cur.y][i], ind = index_of_edge[cur.y][i];
            if(mst[b]!=1){
                st.insert(edge(a, b, c, ind));
            }
        }
    }

    for(int i = 0; i < (int)mst_edges.size(); i++){
        cout << mst_edges[i].first << " " << mst_edges[i].second << endl;
    }

}
