#include <bits/stdc++.h>

using namespace std;

int sockMerchant(int n, vector <int> ar) {
    unordered_map<int, int> um;
    set<int> s;
    for(int i = 0; i < n; ++i){
        s.insert(ar[i]);
        ++um[ar[i]];
    }
    int countPairs = 0;
    for(set<int>::iterator it = s.begin(); it != s.end(); ++it){
        countPairs += um[*it] / 2;
    }
    return countPairs;
}

int main() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for(int ar_i = 0; ar_i < n; ar_i++){
       cin >> ar[ar_i];
    }
    int result = sockMerchant(n, ar);
    cout << result << endl;
    return 0;
}
