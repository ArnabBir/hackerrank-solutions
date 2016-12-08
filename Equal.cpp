#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int T, N, difference;
    cin>>T;
    while(T--){
        cin>>N;
        int count = 0;
        vector<int> v(N); 
        for(int i = 0; i < N; ++i){
            cin>>v[i];
        }
        sort(v.begin(), v.end());
        for(int i = 1; i < N; ++i){
            difference = v[i] - v[0];
            count += difference / 5 + (difference % 5) / 2 + ((difference % 5) % 2);
        }
        cout<<count<<endl;
    }
    return 0;
}
