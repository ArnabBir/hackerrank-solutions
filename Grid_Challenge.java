import java.io.*;
import java.util.*;
import java.util.Arrays;
import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner sc =  new Scanner(System.in);
        int T = sc.nextInt();
        while(T-- > 0){
            int N = sc.nextInt();
            boolean flag = false;
            char [][] A = new char [N][N];
            if(N == 0) {System.out.println("YES"); continue;}
            for(int i = 0; i < N; ++i){
                String str = sc.next();
                for(int j = 0; j < N; ++j){
                    A[i][j] = str.charAt(j);
                }
                Arrays.sort(A[i]);
            }
            for(int j = 0; j < N ; ++j){
                for(int i = 0; i < N - 1; ++i){
                    if(A[i][j] > A[i + 1][j]){System.out.println("NO"); flag = true; break;}
                }
            }
            if(!flag) System.out.println("YES");
        }
            
    }
}
