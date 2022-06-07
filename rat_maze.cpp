#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m;
vector< vector<int> > grid, visited;

bool solve(int x, int y, int par){
    if(x >= n or y >= m or grid[x][y] == 1) return false;
    if(x == n-1 and y == m-1) return true;
    visited[x][y] = 1;
    if(solve(x+1, y, x*m+y)) return true;
    else if(solve(x, y+1, x*m+y)) return true;
    visited[x][y] = 0;
    return false;
}

int main(){
    n = 9, m = 9;

    grid.assign(n, vector<int>(m, 0));
    visited.assign(n, vector<int>(m, 0));

    freopen("C:/data/maze.txt", "r", stdin);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }

    cout << solve(0, 0, -1) << endl;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << visited[i][j] << " ";
        } cout << endl;
    }


}

/*

0 0 1 0 0 0 0 0 1
1 0 0 0 0 1 0 1 0
1 0 1 0 1 1 1 0 0
1 0 0 1 1 1 0 1 1
0 0 0 1 0 1 1 0 1
1 0 0 0 1 0 1 1 1
0 0 1 1 1 0 1 1 0
0 0 1 1 0 1 1 0 1
1 0 0 0 0 0 0 0 0

*/
