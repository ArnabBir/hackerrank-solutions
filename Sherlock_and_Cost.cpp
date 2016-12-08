#include <vector>
#include<cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int T, N, l, h, low, high;
    cin>>T;
    while(T--){
        low = 0; high = 0;
        cin>>N;
        vector<int> B(N);
        for(int i = 0; i < N; ++i){
            cin>>B[i];
        }
        for(int i =1; i < N; ++i){
            l = ((abs(1-B[i-1])+high > low) ? abs(1-B[i-1])+high : low);
            h = ((abs(B[i]-1)+low, abs(B[i]-B[i-1])+high) ? abs(B[i]-1)+low : abs(B[i]-B[i-1])+high);
            low = l;
            high = h;
        }
        cout<<max(low, high)<<endl;
    }
    return 0;
}
