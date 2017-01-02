#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;


int main(){
    int n, cost;
    cin >> n;
    string s;
    for(int a0 = 0; a0 < n; ++a0){
        cin >> s;
        if(s[0] == '\0'){
            cout<<0<<endl;
            continue;
        }
        cost = 0;
        int offset = 'a';
        bool isPresent[26] = {false};
        for(string::const_iterator it=s.begin(); it!=s.end(); ++it) {
            if(isPresent[*it - offset] == false){
                isPresent[*it - offset] = true;
                ++cost;
            }
        }
        cout<<cost<<endl;
    }
    return 0;
}

