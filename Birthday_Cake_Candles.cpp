#include <bits/stdc++.h>

using namespace std;

int birthdayCakeCandles(int n, vector <int> ar) {
    int maxH = -1;
    for(vector<int>::iterator it = ar.begin(); it != ar.end(); ++it){
        maxH = max(maxH, *it);
    }
    int count = 0;
    for(vector<int>::iterator it = ar.begin(); it != ar.end(); ++it){
        if(*it == maxH) ++count;
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for(int ar_i = 0; ar_i < n; ar_i++){
       cin >> ar[ar_i];
    }
    int result = birthdayCakeCandles(n, ar);
    cout << result << endl;
    return 0;
}
