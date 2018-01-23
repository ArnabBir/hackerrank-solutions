#include <bits/stdc++.h>

using namespace std;

int toys(vector <int> w) {
    sort(w.begin(), w.end());
    int curr = w[0], count = 1;
    for(int i = 0; i < w.size(); ++i){
        if(curr <= w[i] && w[i] <= (curr+4)) continue;
        else{
            ++count;
            curr = w[i];
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    vector<int> w(n);
    for(int w_i = 0; w_i < n; w_i++){
       cin >> w[w_i];
    }
    int result = toys(w);
    cout << result << endl;
    return 0;
}
Priyanka and Toys
