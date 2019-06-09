import java.io.*;
import java.util.*;
import java.lang.*;

public class leftover_5585{
    public static void main(String[] argv){
        Scanner scanner = new Scanner(System.in);

        int num, ans=0;
        int []coins = {500, 100, 50, 10 ,5, 1};
        int N = scanner.nextInt();
        N = 1000 - N;

        for(int i=0; i<6; i++){
            if(N>=coins[i]){
                num = N/coins[i];
                ans += num;
                N -= num * coins[i];
                // System.out.printf("%d %d %d\n", num, ans, N);
            }
        }
        System.out.print(ans);
    }
}