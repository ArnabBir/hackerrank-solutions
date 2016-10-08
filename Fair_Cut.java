import java.io.*;
import java.util.*;
import java.lang.Math;
public class Solution {
    
    public static long maxF(int [] A, int n, int k){
        long [][]unfairness = new long [n + 1][n + 1];
        long Li, Lu;
        for(int i = 0; i < n + 1; ++i) Arrays.fill(unfairness[i], Long.MAX_VALUE);
        unfairness[0][0] = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j <= i; ++j){
                if(j > k && i - j > n - k) continue;
                Li = unfairness[i][j] + A[i] * ((i - j) - ((n - k) - (i -j)));
                Lu = unfairness[i][j] + A[i] * (j - (k - j));
                if(unfairness[i + 1][j + 1] > Li) unfairness[i + 1][j + 1] = Li;
                if(unfairness[i + 1][j] > Lu) unfairness[i + 1][j] = Lu;
            }
        }
        return unfairness[n][k];
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int [] A = new int[n];
        for(int i = 0; i < n; ++i){
            A[i] = sc.nextInt();
        }
        Arrays.sort(A);
        
        System.out.println(maxF(A, n, ((k <= n / 2) ? k : n - k)));
    }
}
