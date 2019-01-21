#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);



int main()
{
    int n, d;
    cin>>n>>d;
    vector<int> v(n);
    for(int i = 0; i < n; ++i) {
        cin>>v[(i+n-d)%n];
    }
    for(int i = 0; i < n; ++i) {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}


