#include <iostream>
using namespace std;


int main() {
    int T, n;
    cin>>T;
    while(T--){
        int count = 0;
        cin>>n;
        int remainder = n%7;
        if (remainder == 0 || remainder == 1) cout<<"Second"<<endl;
        else cout<<"First"<<endl;
    }
    return 0;
}
