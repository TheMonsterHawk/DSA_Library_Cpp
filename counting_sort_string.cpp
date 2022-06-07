#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string gen(int x, int y){
    int len = x;
    if(x!=y) len += rand()%(y-x);

    string s = "";
    int a = 'a';
    for(int i = 0; i < len; i++) s += (char)(a + rand()%5);
    return s;
}

int main(){

    freopen("C:/data/counting_sort_string.txt", "r", stdin);

    srand((int)time(NULL));
    int n = 10;
    cin >> n;

    vector < string > a(n);
    vector < string > b(n);
    vector < int > counter(27, 0);
    int a_int = (int)'a' - 1;

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;

    function<int(int, int)> get = [&](int string_index, int index){
        int m = (int)a[string_index].size();
        if(index >= m) return 0;
        int x = m - 1 - index;
        int offset = (int)'a' - 1;
        return (int)a[string_index][x] - offset;
    };

    int m = (int)a[0].size();
    for(int j = 0; j < m; j++){
        for(int i = 0; i < n; i++) counter[get(i, j)]++;
        for(int i = 1; i < n; i++) counter[i] += counter[i-1];
        for(int i = n-1; i >= 0; i--) b[--counter[get(i, j)]] = a[i];
        for(int i = 0; i < n; i++) a[i] = b[i];
        //for(int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
        counter.assign(27, 0);
    }

    for(int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
}
