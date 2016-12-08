#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N;
    cin>>N;
    vector<int> v(N);
    vector<int> candy(N);
    for(int i = 0; i < N; ++i){
        cin>>v[i];
        candy[i] = 1;
    }
    for(int i = 1; i < N; ++i){
        if(v[i] > v[i-1]) candy[i] = candy[i-1] + 1;
     }
    for(int i = N-1; i > 0; --i){
        if(v[i-1] > v[i] && candy[i] >= candy[i-1]){
            candy[i-1] = candy[i] + 1;
        }
    }
    cout<<accumulate(candy.begin(), candy.end(), 0)<<endl;
    return 0;
}
