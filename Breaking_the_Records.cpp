#include <bits/stdc++.h>

using namespace std;

vector < int > getRecord(vector < int > s){
    int max = s[0], min = s[0];
    int countMax = 0, countMin = 0;
    for(int i = 1; i < s.size(); ++i){
        if(s[i] > max){
            ++countMax;
            max = s[i];
        }
        if(s[i] < min){
            ++countMin;
            min = s[i];
        }
    }
    vector<int> result(2);
    result[0] = countMax;
    result[1] = countMin;
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> s(n);
    for(int s_i = 0; s_i < n; s_i++){
       cin >> s[s_i];
    }
    vector < int > result = getRecord(s);
    string separator = "", delimiter = " ";
    for(auto val: result) {
        cout<<separator<<val;
        separator = delimiter;
    }
    cout<<endl;
    return 0;
}
