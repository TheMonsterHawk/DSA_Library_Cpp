#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector< vector<int> > grid, fix;
vector< vector<int> > row, col, box;

void mark(int x, int y, int num, bool unmark = false){

    int t = 1;
    if(unmark) t = 0;

    row[x][num-1] = t;
    col[y][num-1] = t;
    int box_num = (x/3)*3 + y/3;
    box[box_num][num-1] = t;
    return;
}

bool check(int x, int y, int num){
    int box_num = (x/3)*3 + y/3;
    if(row[x][num-1]) return false;
    else if(col[y][num-1]) return false;
    else if(box[box_num][num-1]) return false;
    else return true;
}

bool solve(int cell){



    int n = (int)grid.size();
    int x = cell/n, y = cell%n;

    if(cell == n*n) return true;
    if(fix[x][y]) return solve(cell+1);

    for(int i = 1; i <= n; i++){
        if(check(x, y, i)){
            mark(x, y, i);
            grid[x][y] = i;
            if(solve(cell+1)) return true;
            mark(x, y, i, true);
        }
    }

    return false;

}

int main(){
    int n = 9;
    grid.assign(n, vector<int>(n, 0));
    fix.assign(n, vector<int>(n, 0));
    row.assign(n, vector<int>(n, 0)); //row[i][x-1] => does row i has the number x in it?
    col.assign(n, vector<int>(n, 0)); //col[i][x-1] => does col i has the number x in it?
    box.assign(n, vector<int>(n, 0)); //box[i][x-1] => does box i has the number x in it?

    freopen("C:/data/sudoko1.txt", "r", stdin);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << grid[i][j] << " ";
        } cout << endl;
    }
    cout << endl;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] != 0){
                fix[i][j] = 1;
                mark(i, j, grid[i][j]);
            }
        }
    }

    solve(0);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << grid[i][j] << " ";
        } cout << endl;
    }
}

/*
0 0 0 0 1 0 0 0 0
0 0 2 5 6 0 4 0 0
0 3 0 0 0 0 0 0 2
7 0 0 0 0 0 0 9 0
0 0 0 0 0 8 0 0 0
0 0 3 4 2 0 6 0 0
0 9 0 8 5 0 6 0 0
0 0 5 0 0 1 0 0 0
0 0 0 0 0 3 8 0 0

0 3 0 6 0 0 0 8 0
0 0 9 8 0 1 7 0 2
0 0 0 5 0 0 0 0 6
0 0 0 0 1 0 0 0 3
0 8 5 0 0 0 9 0 4
0 7 0 0 2 0 0 0 0
0 9 0 0 0 7 0 0 0
0 5 3 0 0 0 0 0 0
0 0 0 0 9 0 0 4 7
*/
