#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector< vector<int> > grid;
int visited_cells = 0;

int xdir[] = {2, 1, -1, -2, -2, -1, 1, 2};
int ydir[] = {1, 2, 2, 1, -1, -2, -2, -1};

int num_solutions = 0;

void mark_solved(){
    num_solutions++;
    int n = (int)grid.size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << (grid[i][j]<10? "0" : "") << grid[i][j] << " ";
        }
        cout << endl;
    }

}

void dfs(int x, int y){

    if(num_solutions > 0) return;
    int n = grid.size();

    if(x < 0 or y < 0 or x > n-1 or y > n-1){
        return;
    }

    if(grid[x][y] != 0){
        return;
    }

    grid[x][y] = ++visited_cells;
    if(visited_cells == n*n){
        mark_solved();
        return;
    }

    for(int i = 0; i < 8; i++){
        dfs(x+xdir[i], y+ydir[i]);
    }
    grid[x][y] = 0;
    visited_cells--;
    return;
}

int main(){
    int n = 8;

    grid.assign(n, vector<int>(n, 0));
    visited_cells = 0;

    dfs(0, 0);
}
