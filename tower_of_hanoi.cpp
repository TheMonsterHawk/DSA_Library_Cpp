#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int counter = 0;

void solve(char source, char dest, char aux, int n){
    if(n == 1){
        ++counter;
        //cout << source << "->" << dest << endl;
        return;
    }

    solve(source, aux, dest, n-1);

    ++counter;
    //cout << source << "->" << dest << endl;
    solve(aux, dest, source, n-1);
    return;
}

int main(){
    int n;
    n = 30;

    solve('A', 'C', 'B', n);
    cout << "It took " << counter << " steps to solve." << endl;

    return 0;
}
