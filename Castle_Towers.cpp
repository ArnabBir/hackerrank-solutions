int castleTowers(int n, vector <int> ar) {
    //sort(ar.rbegin(), ar.rend());
    int maxi = *max_element(ar.begin(), ar.end());
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (maxi == ar[i]) {
            ++cnt;
        } 
    }
    return cnt;
}
