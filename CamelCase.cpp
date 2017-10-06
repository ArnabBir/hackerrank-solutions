#include <bits/stdc++.h>

using namespace std;


int main(){
    string s;
    cin >> s;
    int count = 1;
    for(int i = 1; i < s.length(); ++i){
        if(s[i] >= 'A' && s[i] <= 'Z')  ++count;
    }
    cout<<count<<endl;
    return 0;
}
