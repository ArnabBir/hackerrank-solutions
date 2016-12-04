#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;


int main(){
    int n;
    int k;
    int q;
    cin >> n >> k >> q;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
       cin >> a[a_i];
    }
    for(int a0 = 0; a0 < q; a0++){
        int m;
        cin >> m;
        if(m < k%n) cout<<a[n+m-k%n]<<endl; 
        else cout<<a[(n+m)%n - k%n]<<endl;
    }
    return 0;
}
