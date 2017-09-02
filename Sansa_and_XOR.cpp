#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T, N;
    cin>>T;
    while(T--){
        cin>>N;
        int a[N];
        bool isNodd = N%2;
        for(int i = 0; i < N; ++i){
            cin>>a[i];
        }
        if(N == 0){
            cout<<0<<endl;
            continue;
        }
        if(N == 1){
            cout<<a[0]<<endl;
            continue;
        }
        int XOR;
        if(isNodd){
            XOR = a[0]^a[N-1];
            for(int i = 2; i < N/2; i += 2){
                XOR ^= a[i]^a[N-1-i];
            }
            if((N/2)%2 == 0)    XOR ^= a[N/2];
        }
        else{
            XOR = 0; 
        }
        cout<<XOR<<endl;
        
    }
    return 0;
}
