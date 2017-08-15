#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
/*
 * Complete the function below.
 */
int maxXor(int l, int r) {
    int L = l, R = r;
    stack<int> bits[2];
    int len = 0;
    while(L || R){
        ++len;
        bits[0].push(L%2);
        L /= 2;
        bits[1].push(R%2);
        R /= 2;
        
    }
    int bitCount = 0;
    while(bits[0].top() == bits[1].top()){
        ++bitCount;
        bits[0].pop();
        bits[1].pop();
    }
    return (int)pow(2,len - bitCount) - 1;    
}

int main() {
    int res;
    int _l;
    cin >> _l;
    
    int _r;
    cin >> _r;
    
    res = maxXor(_l, _r);
    cout << res;
    
    return 0;
}
