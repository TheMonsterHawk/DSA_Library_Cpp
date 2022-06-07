#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

set< pair< int, int > > present;

void mark(int x, int y){
    present.insert({x, y});
}

bool is_mergeable(int x, int y){
    int mid = (x + y)/2;
    return present.find({x, mid})!=present.end() and present.find({mid+1, y})!=present.end();
}

int main(){

    srand((int)time(NULL));

    int n = 10;
    vector < int > a(n, 0);

    for(int i = 0; i < n; i++) a[i] = rand()%10;
    for(int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;

    stack< pair<int, int> > st;
    st.push({0, n-1});

    while(!st.empty()){

        int x = st.top().first;
        int y = st.top().second;

        if(x == y){
            mark(x, y);
            st.pop();
            continue;
        }

        if(is_mergeable(x, y)){

            vector < int > b(y-x+1);
            int mid = (x + y)/2;
            int l = x, r = mid+1, z = 0, i = x;

            while(l <= mid and r <= y) a[l] < a[r]? b[z++] = a[l++] : b[z++] = a[r++];
            while(l <= mid) b[z++] = a[l++];
            while(r <= y) b[z++] = a[r++];
            while(i <= y) a[i] = b[i-x], i++;

            mark(x, y);
            st.pop();
        } else {
            int mid = (x + y)/2;
            st.push({x, mid});
            st.push({mid+1, y});
        }
    }

    for(int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
}
