#include <bits/stdc++.h>

using namespace std;

long minimumTime(vector <int> A, int m, int k,int c) {
    // Complete this function
    long count=0;
    int n= A.size();
    if(m==0)
        return 0;
    int shop=0;
    int i,j;
    for(i=0;i<n;i++)
        if(A[i])
            shop++;
    int start = 0; int e=1;
    if(shop<m)
        return -1;
    else if(shop==m)
    {
        while(e<n)
        {    
            if(A[e])
            {
                if(!c)
                {count+= (long)(e-start);c++;}
                else
                {count+= (long)(e-start)*c*k;c++;}
                start = e;
            }
            e++;
        }
        return count;
    }
    for(i=0;i<n;i++)
    {
        if(A[i])
        {
            A[i] = 0;
            vector<int> B(A.begin()+i,A.end());
            long temp = ((!c)?(i-start):(i-start)*k*c) + minimumTime(B,m-1,k,c+1);
            long temp2 = minimumTime(A,m,k,c);
            return min(temp,temp2);
        }
    }
    return -1;
}

int main() {
    int n;
    int m;
    int k;
    cin >> n >> m >> k;
    vector<int> b(n);
    for(int b_i = 0; b_i < n; b_i++){
       cin >> b[b_i];
    }
    long result = minimumTime(b, m, k,0);
    cout << result << endl;
    return 0;
}
