#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int const inf = 1e9;

void heapify(int index, int n, vector < int > &heap){
    if(index >= n) return;

    int l = 2 * index + 1;
    int r = 2 * index + 2;

    int smallest = index;
    if(l < n and heap[l] < heap[smallest]){
        smallest = l;
    }

    if(r < n and heap[r] < heap[smallest]){
        smallest = r;
    }

    if(smallest != index){
        swap(heap[smallest], heap[index]);
        heapify(smallest, n, heap);
    }
    return;

}

void delete_node(int index, int n, vector < int > &heap){
    heap[index] = inf;
    heapify(index, n, heap);
    return;
}

int main(){
    srand((int)time(NULL));

    int n = 12;

    vector < int > a(n, 0);
    vector < int > heap(4*n, inf);

    for(int i = 0; i < n; i++){
        a[i] = rand()%10;
        heap[i] = a[i];
        cout << a[i] << " ";
    } cout << endl;

    for(int i = n/2 - 1; i >= 0; i--) heapify(i, n, heap);

    vector < int > arr;

    for(int i = 0; i < n; i++){
        arr.push_back(heap[0]);
        delete_node(0, n, heap);
    }
    for(int i = 0; i < n; i++) cout << arr[i] << " "; cout << endl;
}
