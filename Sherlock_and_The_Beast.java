import java.io.*;
import java.util.*;

public class Sherlock_and_The_Beast {
    
    public static String DecentNumber(int N){
        int count5 = N;
        while(count5 % 3 != 0){
            if(count5 % 3 == 1){ count5 -= 10; continue;} 
            count5 -= 5;
        }
        if(count5 < 0) return "-1";
        else{
            String result = "";
            int count3 = N - count5;
            while(count5-- > 0) result += "5";
            while(count3-- > 0) result += "3";
            return result;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while(T-- > 0){
            int N = sc.nextInt();
            System.out.println(DecentNumber(N));
        }
    }
}
