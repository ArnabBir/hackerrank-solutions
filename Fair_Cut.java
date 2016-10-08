import java.io.*;
import java.util.*;

public class Solution {
    
    public static long maxF(int [] A, int n, int k){
        long unfairness = 0;
        for(int i = 0; i < k; ++i){
            for(int j = k; j < n; ++j){
                unfairness += Math.abs(A[i] - A[j]);
            }
        }
        return unfairness;
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
        System.out.println(maxF(A, n, k));
    }
}
