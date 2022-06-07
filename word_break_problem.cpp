#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector < int > ans;

bool word_break(string s, int index, unordered_map<string, int> dictionary){
    if(index == (int)s.size()){
        ans.push_back(index);
        return true;
    }
    for(int i = index; i < (int)s.size(); i++){
        if(dictionary[s.substr(index, i-index+1)] == 1){
            if(word_break(s, i+1, dictionary)){
                ans.push_back(index);
                return true;
            }
        }
    }
    return false;
}

int main(){
    string query_string = "thisisadog";

    vector < string > list_of_words = {"I", "have", "Jain", "Sumit", "am", "this", "dog", "is", "a"};
    int n = (int)list_of_words.size();

    unordered_map < string , int > dictionary;
    for(int i = 0; i < n; i++) dictionary[list_of_words[i]] = 1;

    bool possible = word_break(query_string, 0, dictionary);

    if(possible) cout << "YES" << endl;
    else cout << "NO" << endl;

    reverse(ans.begin(), ans.end());

    for(int i = 0; i+1 < (int)ans.size(); i++){
        for(int j = ans[i]; j < ans[i+1]; j++)
            cout << query_string[j];
        cout << " ";
    }
    cout << endl;
}
/*
    srand((int)time(NULL));

    vector < string > a = {"I", "have", "Jain", "Sumit", "am", "this", "dog", "is", "a"};
    int n = (int)a.size();
    unordered_map<string, int> dictionary;

    string s = "IamSumit";
    s = "thisisadog";

    for(int i = 0; i < n; i++) dictionary[a[i]]= 1;
    bool possible = word_break(s, 0, dictionary);

    if(possible){
        cout << "YES" << endl;
    } else cout << "NO" << endl;

    reverse(ans.begin(), ans.end());
    int x = 0, y = 0;
    while(x < (int)s.size()){
        for(int i = x; i <= ans[y]; i++) cout << s[i]; cout << " ";

        x = ans[y] + 1;
        y++;
    }

    */
