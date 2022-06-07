#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int main(){

    int n = 1e8;
    vector<int> prime_numbers, is_prime(n+1, 1);

    int counter = 0;
    for(int i = 2; i <= n; i++){
        if(is_prime[i] == 0) continue;
        counter++;
        prime_numbers.push_back(i);
        for(ll j = 1LL*i*i; j <= n; j+=i){
            is_prime[j] = 0;
            counter++;
        }
    }

    cout << (int)prime_numbers.size() << endl;
    cout << counter << endl;
    return 0;

    for(int i = 0; i < (int)prime_numbers.size(); i++){
        cout << prime_numbers[i] << " ";
    } cout << endl;
}
