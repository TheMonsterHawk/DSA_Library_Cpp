#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int const N = 1e6 + 1;
vector < int > bit(N+1, 0);
void mark(int index, int value){
    index += 1;

    while(index <= N){
        bit[index] += value;
        index += (index)&(-index);
    }
    return;
}

int get_sum(int index){
    index += 1;

    int sum = 0;
    while(index > 0){
        sum += bit[index];
        index -= (index)&(-index);
    }
    return sum;
}

int counting_sort(vector < int > &a){
    int counter = 0;
    for(int i = 0; i < (int)a.size(); i++){
        for(int j = i+1; j < (int)a.size(); j++){
            counter += a[j] < a[i];
        }
    }
    return counter;
}

int main(){
    srand((int)time(NULL));

    int n = 10;
    vector < int > a(n, 0);
    for(int i = 0; i < n; i++) a[i] = rand()%n;
    for(int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;

    int counter = 0;
    for(int i = n-1; i >= 0; i--){
        counter += get_sum(a[i]-1);
        mark(a[i], 1);
    }

    cout << counter << endl;

}
