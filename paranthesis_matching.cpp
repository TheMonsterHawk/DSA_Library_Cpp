#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    string s;
    cin >> s;

    stack < char > st;

    bool FORBID = false;
    for(int i = 0; i < (int)s.size() and !FORBID; i++){
        if(s[i] == '(') st.push('(');
        else{
            if(st.empty()) FORBID = true;
            else st.pop();
        }
    }

    if(st.empty() == false) FORBID = true;

    if(FORBID) cout << "WRONG" << endl;
    else cout << "RIGHT" << endl;
}
