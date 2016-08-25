import java.io.*;
import java.util.*;

public class Solution {
    
    private static int max(int [] A){
        if (A.length == 0)
            return 0;
        int maximum = A[0];
        for (int i = 0; i < A.length; ++i){
            if (maximum < A[i])
                maximum = A[i];
        }
        return maximum;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while (T-- != 0){
            int size = sc.nextInt();
            int [] A = new int [size];
            for(int i = 0; i < size; ++i){
                A[i] = sc.nextInt();
            }
            int c_max = 0, nc_max = 0;
            int sum = 0;
            for (int i = 0; i < size; ++i){
                sum+= A[i];
                if (sum < 0)    sum = 0;
                if (c_max < sum)    c_max = sum;
               /* for (int j = i; j < size; ++j){
                    sum += A[j];
                    if (c_max < sum)
                        c_max = sum;
                }
                */
                if(A[i] > 0)
                    nc_max += A[i];
            }
            if (nc_max == 0)    nc_max = max(A);
            if (c_max == 0)    c_max = max(A);
            System.out.println(c_max + " " + nc_max);
        }
    }
}