#include <bits/stdc++.h>

using namespace std;

string subsequenceAgain(string s, int k) {
    int count[26] = {0};
    string result = "";
    for(int i = 0; i < s.length(); ++i){
        ++count[(int)(s[i]-'a')];
    }
    for(int i = 0; i < s.length(); ++i){
        if(count[(int)(s[i]-'a')] >= k) result += s[i];
    }
    return result;
}

int main() {
    string s;
    cin >> s;
    int k;
    cin >> k;
    string result = subsequenceAgain(s, k);
    cout << result << endl;
    return 0;
}
