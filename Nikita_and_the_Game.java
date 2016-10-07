import java.io.*;
import java.util.*;
import java.lang.Math;

public class Solution {
    
    public static int countScore(HashSet hs, int min, int max){
        if((min + max) % 2 != 0) return 0;
        else if(hs.contains((min + max) / 2))
            return 1 + Math.max(countScore(hs, min, (min + max) / 2), countScore(hs, (min + max) / 2, max));
        else return 0;
    }
    public static void arraySum( HashSet hs, int [] A, int start, int sum) {
        if(A.length == start) return;
        hs.add(sum + A[start]);
        arraySum(hs, A, start + 1, sum + A[start]);
        arraySum(hs, A, start + 1, sum);
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while(T-- > 0){
            int sum = 0;
            int N = sc.nextInt();
            int [] A = new int[N];
            HashSet hs = new HashSet();
            for(int i = 0; i < N; ++i){
                A[i] = sc.nextInt();
                sum += A[i];
            }
            arraySum( hs, A, 0, 0);
            if(sum == 0){
                System.out.println(N-1);
            } 
            else System.out.println(countScore(hs, 0, sum));
        }  
    }
}
