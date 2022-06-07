#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector< vector<int> > tree;
vector<int> depth, tour, tour_depth, first;

void dfs(int source, int parent){
    depth[source] = depth[parent] + 1;

    tour.push_back(source);
    tour_depth.push_back(depth[source]);

    for(int i = 0; i < (int)tree[source].size(); i++){
        int cur = tree[source][i];
        if(cur != parent){
            dfs(cur, source);
            tour.push_back(source);
            tour_depth.push_back(depth[source]);
        }
    }

    return;
}

class sparse_table{
private:
    vector< vector<int> > sp;
    vector<int> A;
public:
    int n, m;
    sparse_table(vector<int> &A){
        this->A = A;
        n = (int)A.size();
        m = (int)log2(n) + 1;

        sp.assign(4*n, vector<int>(m, 0));

        build();
    }

    void build(){
        for(int j = 0; j < m; j++){
            for(int i = 0; i < n; i++){
                if(j == 0) sp[i][j] = i;
                else{
                    int a = sp[i][j-1];
                    int b = sp[i + (1<<(j-1))][j-1];
                    sp[i][j] = A[a] < A[b]? a : b;
                }
            }
        }
        cout << "Build complete!" << endl;
    }

    int query(int x, int y){

        int total = y-x+1, t = 1, j = 0;
        while(2*t <= total){
            j++;
            t *= 2;
        }

        int z = y - t + 1;
        int a = sp[x][j], b = sp[z][j];
        return A[a] < A[b]? a : b;
    }
};

int main(){

    freopen("C:/data/tree1.txt", "r", stdin);

    int n;
    cin >> n;

    tree.assign(n+1, vector<int>(0));
    depth.assign(n+1, 0);
    first.assign(n+1, -1);

    for(int i = 1; i < n; i++){
        int x, y;
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }

    depth[0] = 0;
    int root = 1;
    dfs(root, 0);

    //for(int i = 0; i < (int)tour.size(); i++) cout << tour[i] << " "; cout << endl;
    //for(int i = 0; i < (int)tour_depth.size(); i++) cout << tour_depth[i] << " "; cout << endl;

    for(int i = 0; i < (int)tour.size(); i++){
        if(first[tour[i]] == -1){
            first[tour[i]] = i;
        }
    }
    //for(int i = 1; i <= n; i++) cout << first[i] << " "; cout << endl;

    sparse_table sp(tour_depth);


    int Q = 1e7 + 10;
    for(int i = 0 ; i < Q; i++){
            int x = rand()%n;
            int y = rand()%n;
            x += 1;
            y += 1;
            int ans = sp.query(x, y);
            //cout << i << ": " << sp.query(x, y) << endl;
            if(i!=0 and i%100000000 == 0) cout << i << endl;
    }

}
