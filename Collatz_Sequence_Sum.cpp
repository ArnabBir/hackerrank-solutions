int dp[5003];
bool visited[5003] = {false};

int collatzSequenceLen(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    if (n % 2 == 0) {
        return 1 + collatzSequenceLen(n/2);
    }
    return 1 + collatzSequenceLen(3*n+1);
}

int collatzSequenceSum(int T, int A, int B) {
    int n = 0;
    int result = 0;
    while (T--) {
        n = (A*n + B) % 5003;
        int best_len = 0;
        int best_num = 0;
        int cur_len;
        for (int k = 0; k <= n; ++k) {
            if(visited[k]){
                cur_len = dp[k];
            }
            else{
                cur_len = collatzSequenceLen(k);
                dp[k] = cur_len;
                visited[k] = true;
            }
            if (cur_len >= best_len) {
                best_len = cur_len;
                best_num = k;
            }
        }
        result += best_num;
    }
    return result;
}
