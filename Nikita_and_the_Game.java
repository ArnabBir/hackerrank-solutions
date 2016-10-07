import java.io.*;
import java.util.*;
import java.lang.Math;

public class Solution {
    
    public static int countScore(int [] A, int min, int max){
        if((min + max) % 2 != 0) return 0;
        else if(isSubsetSum(A, 0, A.length, (min + max) / 2)){
            return 1 + Math.max(countScore(A, min, (min + max) / 2), countScore(A, (min + max) / 2, max));
        }
        else return 0;
    }
    /*
    public static void arraySum( HashSet hs, int [] A, int start, int sum, int real_sum) {
        if(A.length == start) return;
        else if(sum + A[start] > real_sum / 2)return;
        hs.add(sum + A[start]);
        arraySum(hs, A, start + 1, sum + A[start], real_sum);
        arraySum(hs, A, start + 1, sum, real_sum);
    }
    */
    
    public static boolean isSubsetSum(int [] set, int m, int n, int sum)
    {
        if (sum == 0) return true;
        if (n == m && sum != 0) return false;
        if (set[n-1] > sum && n > m) return isSubsetSum(set, m, n-1, sum);
        return isSubsetSum(set, m, n-1, sum) || isSubsetSum(set, m, n-1, sum-set[n-1]);
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while(T-- > 0){
            int sum = 0;
            int N = sc.nextInt();
            if(N < 2){System.out.println(0); continue;}
            int [] A = new int[N];
            HashSet hs = new HashSet();
            for(int i = 0; i < N; ++i){
                A[i] = sc.nextInt();
                sum += A[i];
            }
            //arraySum( hs, A, 0, 0, sum);
            if(sum == 0){
                System.out.println(N-1);
            } 
            else System.out.println(countScore(A, 0, sum));
        }  
    }
}
