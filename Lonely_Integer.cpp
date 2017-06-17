#include <bits/stdc++.h>

using namespace std;

int lonelyinteger(vector <int> a) {
    int result = *a.begin();
    for(vector<int>::iterator it = a.begin() + 1; it != a.end(); ++it){
        result ^= *it;
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
       cin >> a[a_i];
    }
    int result = lonelyinteger(a);
    cout << result << endl;
    return 0;
}
