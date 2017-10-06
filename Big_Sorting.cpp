#include <bits/stdc++.h>

using namespace std;

bool sortString (string i,string j) { 
    int n=i.length();
    int m=j.length();
    if(n==m)
        return (i<j);
    
    return n<m;   
}

int main(){
    int n;
    cin >> n;
    vector<string> unsorted(n);
    for(int unsorted_i = 0; unsorted_i < n; unsorted_i++){
       cin >> unsorted[unsorted_i];
    }
    sort(unsorted.begin(), unsorted.end(), sortString);
    for(vector<string>::iterator it = unsorted.begin(); it != unsorted.end(); ++it)     cout<<*it<<endl;
    return 0;
}
