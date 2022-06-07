#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

    //freopen("C:/data/suffix_array.txt", "r", stdin);

    string s;
    cin >> s;

    int n = (int)s.size();
    int logm = ceil(log2(n)), m = 1<<logm;
    int offset = (int)'a' - 1;
    for(int i = n; i < m; i++) s += (char)offset;
    //for(int i = 0; i < m; i++) cout << s[i] << " "; cout << endl;

    vector < int > rank_of_index(m, 0);
    for(int i = 0; i < m; i++) rank_of_index[i] = (int)s[i] - offset;
    //for(int i = 0; i < m; i++) cout << rank_of_index[i] << " "; cout << endl;

    function<bool(int, int, int)> is_smaller = [&](const int a, const int b, const int len){
        int x = a + len/2, y = b + len/2;
        x %= m;
        y %= m;
        return rank_of_index[a] < rank_of_index[b] or (rank_of_index[a]==rank_of_index[b] and rank_of_index[x] < rank_of_index[y]);
    };

    function<bool(int, int, int)> same = [&](const int a, const int b, const int len){
        int x = (a + len/2)%m;
        int y = (b + len/2)%m;
        return rank_of_index[a]==rank_of_index[b] and rank_of_index[x]==rank_of_index[y];
    };

    vector < int > rank_list(m, 0);
    for(int len = 2; len <= m; len *= 2){
        rank_list.assign(m, 0);
        for(int i = 0; i < m; i++) rank_list[i] = i;
        sort(rank_list.begin(), rank_list.end(), [&](const int a, const int b){
                return is_smaller(a, b, len);
             });

        //for(int i = 0; i < m; i++) cout << rank_list[i] << " "; cout << endl;

        vector < int > new_rank(m, 0);
        int rank_ = 0;
        new_rank[rank_list[0]] = rank_;
        for(int i = 1; i < m; i++){
            if(!same(rank_list[i-1], rank_list[i], len)){
                //cout << rank_list[i] << endl;
                rank_++;
            }
            new_rank[rank_list[i]] = rank_;
        }
        rank_of_index = new_rank;
        //for(int i = 0; i < m; i++) cout << rank_of_index[i] << " "; cout << endl;

    }

    for(int i = m-n; i < m; i++) cout << rank_list[i] << " "; cout << endl;

    return 0;

}
