#include <bits/stdc++.h>

using namespace std;

int digitSum(string n, int k) {
    
    if(n.length() == 1 && k == 1){
        return (int) (n[0]-'0');
    }
    long sum = 0;
    if( k == 1){
        for(int i = 0; i < n.length(); ++i){
            sum += (int) (n[i] - '0');
        }
        return digitSum(to_string(sum), 1);
    }
    else{
        return digitSum(to_string(k * (int)digitSum(n , 1)),1);
    }
    
}

int main() {
    string n;
    int k;
    cin >> n >> k;
    int result = digitSum(n, k);
    cout << result << endl;
    return 0;
}
