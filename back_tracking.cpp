#include <bits/stdc++.h>
using namespace std;

#include <chrono>
using namespace std::chrono;

typedef long long ll;

int n;
vector< vector<int> > grid;
vector<int> col, row, dig_sum, dig_diff;

int counter = 0;
int num_solutions = 0;

void save_solution(){
    num_solutions++;
    //cout << num_solutions << endl;
    return;
}

bool check(int r, int c){
    if(row[r] != 0) return false;
    else if(col[c] != 0) return false;
    else if(dig_sum[r+c] != 0) return false;
    else if(dig_diff[r-c+n-1] != 0) return false;
    else return true;
}

void mark(int r, int c){
    row[r] = 1;
    col[c] = 1;
    dig_sum[r+c] = 1;
    dig_diff[r-c+n-1] = 1;
    return;
}

void unmark(int r, int c){
    row[r] = 0;
    col[c] = 0;
    dig_sum[r+c] = 0;
    dig_diff[r-c+n-1] = 0;
    return;
}

//x shows row number
void solve(int x){
    if(x==n){
        save_solution();
        return;
    }
    for(int c = 0; c < n; c++){
        if(check(x, c)){
            mark(x, c);
            solve(x+1);
            unmark(x, c);
        }
        else continue;
    }
    return;
}

int main(){
    auto start = high_resolution_clock::now();
    n = 14;

    grid.assign(n, vector<int>(n, 0));
    col.assign(n, 0);
    row.assign(n, 0);
    dig_sum.assign(2*n, 0);
    dig_diff.assign(2*n, 0);

    solve(0);

    cout << num_solutions << endl;

auto stop = high_resolution_clock::now();
auto duration = duration_cast<microseconds>(stop - start);

// To get the value of duration use the count()
// member function on the duration object
cout << duration.count() << endl;

}
