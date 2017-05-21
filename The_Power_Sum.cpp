#include <cmath>
#include <iostream>
using namespace std;

int PowerSumCount(int X, int N, int value){
    int remaining = X - pow(value, N);
    if(remaining < 0)   return 0;
    if(remaining == 0)  return 1;
    return PowerSumCount(X, N, value+1) + PowerSumCount(remaining, N, value+1);
}

int main() {
    int X, N;
    cin>>X>>N;
    cout<<PowerSumCount(X, N, 1)<<endl;
    return 0;
}
