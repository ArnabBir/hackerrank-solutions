#include <bits/stdc++.h>

using namespace std;

string uglyOrBeautiful(vector <int> a) {
    int n = a.size();
    int   count[n+1];
    memset(count, 0, sizeof count);
    bool flag = true;
    for(int i = 0; i < n; ++i){
        if(a[i] < 1 || a[i] > n){
            flag = false;
            break;
        }
        if(count[a[i]] > 0){
            flag = false;
            break;
        }
        ++count[a[i]];
    }
    bool isAsc = true;
    for(int i = 0; i < n-1; ++i){
        if(a[i] > a[i+1]){
            isAsc = false;
            break;
        }
    }
    if(!isAsc && flag)  return "Beautiful";
    else    return "Ugly";
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int a_i = 0; a_i < n; a_i++){
           cin >> a[a_i];
        }
        string result = uglyOrBeautiful(a);
        cout << result << endl;
    }
    return 0;
}
