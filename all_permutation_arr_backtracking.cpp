#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int num = 0;

void all_permutation(vector < int > a, vector < int > visited, vector < int > result, int counter, int n){
    if(counter == n){
        cout << (++num) << ": ";
        for(int i = 0; i < n; i++)
            cout << result[i] << " ";
        cout << endl;
    }

    for(int i = 0; i < n; i++){
        if(visited[i] == 0){
            visited[i] = ++counter;
            result.push_back(a[i]);
            //cout << a[i] << " being pushed!" << endl;
            all_permutation(a, visited, result, counter, n);
            result.pop_back();
            visited[i] = 0;
            --counter;
        }
    }

}

int main(){
    srand((int)time(NULL));

    int n = 6;
    int counter = 0;
    vector < int > a(n, 0);
    vector < int > visited(n, 0);
    vector < int > result;

    for(int i = 0; i < n; i++) a[i] = i+1;
    //for(int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
    for(int i = 0; i < n; i++) visited[i] = 0;

    all_permutation(a, visited, result, counter, n);
}
