import java.io.*;
import java.util.*;

public class Solution {
    public static long countCombinations(int [] C, int N){
        if(N == 0) return 0;
        else if(N < 0) return 0;
        for(int i = 0; i < C.length; ++i){
            if(N >= C[i]) return 1 + countCombinations(C, N - C[i]);
        }
        return 0;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        int [] C = new int[M];
        if( N == 0) System.out.println(1);
        else if((N != 0 && M == 0) || M < 0) System.out.println(0);
        else{
            for(int i = 0; i < M; ++i) C[i] = sc.nextInt();
            System.out.println(countCombinations(C,N));
        }
   }
}
