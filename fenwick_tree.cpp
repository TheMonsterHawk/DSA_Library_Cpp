#include <bits/stdc++.h>
using namespace std;

typedef long long ll;



class Fenwik_tree{
    int n;
    vector < int > arr;
    vector < int > sum;

    build_tree(){
        for(int i = 0; i < n; i++){
            add(i, arr[i]);
        }
    }

    void add(int index, int value){
        if(index < 0 or index >= n) throw runtime_error("Index out of the bounds!");
        if(value==0) return;
        index += 1;
        while(index <= n){
            sum[index] += value;
            index += index&(-index);
        }
    }

    int get_sum(int index){
        if(index < 0 || index >= n) throw runtime_error("Index out of the bounds!");

        index += 1;
        int val = 0;
        while(index > 0){
            val += sum[index];
            index -= index&(-index);
        }
        return val;
    }

public:

    Fenwik_tree(vector < int > &a){
        this->n = (int)a.size();
        this->arr.assign(n, 0);
        this->sum.assign(n+1, 0);

        for(int i = 0; i < n; i++) this->arr[i] = a[i];
        build_tree();
    }

    void update(int index, int value){
        if(index < 0 or index >= n) throw runtime_error("Index out of the Bounds!");

        int diff = value - arr[index];
        add(index, diff);
        return;
    }

    int find_sum(int x, int y){
        if(x < 0 or x >= n or y >= n or y < 0) throw runtime_error("Index out of the bounds!");
        int s1 = x==0? 0 : get_sum(x-1);
        int s2 = get_sum(y);
        return s2 - s1;
    }


};

int main(){
    int n = 10;

    vector < int > a(n, 0);

    for(int i = 0; i < n; i++) a[i] = 1 + i;
    for(int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
    Fenwik_tree f(a);

    while(1){
        int type;
        cin >> type;
        if(type == 1){
            int x, y;
            cin >> x >> y;
            cout << f.find_sum(x, y) << endl;
        } else if(type == 2){
            int x, y;
            cin >> x >> y;
            f.update(x, y);
        } else {
            cout << "Enter the correct type input! it can be 1 or 2 only!" << endl;
        }
    }



}
