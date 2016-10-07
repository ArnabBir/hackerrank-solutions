import java.io.*;
import java.util.*;
import java.math.BigInteger;

public class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        BigInteger t1 = new BigInteger(sc.nextInt()+"");
        BigInteger t2 = new BigInteger(sc.nextInt()+"");
        int n = sc.nextInt();
        BigInteger result = new BigInteger(0+"");
        while(n-- > 2){
            result = t1.add(t2.multiply(t2));
            t1 = t2;
            t2 = result;
        }
        System.out.println(result);
    }
}
