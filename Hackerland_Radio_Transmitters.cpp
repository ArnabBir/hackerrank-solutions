#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n;
    int k;
    cin >> n >> k;
    vector<int> x(n);
    for(int x_i = 0;x_i < n;x_i++){
       cin >> x[x_i];
    }
    sort(x.begin(), x.end());
    
    int count = 0, dist = 0, pos = 0,posnext = 1;

    while(dist <= x[n-1]){
        if(posnext + 1 < n){
            while(x[posnext] == x[posnext + 1]){
                ++posnext;
            }
        }
        while(x[pos] + 2*k > x[posnext]){
            if(posnext >= n) break;
            ++posnext;
        }
        
        if(x[pos] + 2 *k == x[posnext]){
            ++count;
            pos = posnext + 1;
            if(pos + 1 >= n) break;
            else posnext = pos + 1;
            dist = x[pos];
        }
        else{
            ++count;
            pos = posnext - 1;
            if(pos + 1 >= n) break;
            else posnext = pos + 1;
            dist = x[pos];
        }
        
    }
    cout<<count<<endl;
    
    return 0;
}
