#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int getMoves(long * s, long n, int m, int index){    
  
    if(index < 0)   return 0;
    if(n % s[index] == 0 && n / s[index] > 1){
        return n/s[index] * getMoves(s, s[index], m, index) + 1;
    }
    else    return getMoves(s, n, m, index-1);
}

int main() {
    int q, m, x, count;
    long n; 
    cin>>q;
    while(q--){
        count = 0;
        cin>>n>>m;
        long s[m];
        for(int i = 0; i < m; ++i){
            cin>>s[i];
        }
        sort(s, s + m);
        cout<<getMoves(s, n, m, m-1)<<endl;
    }
    return 0;
}
