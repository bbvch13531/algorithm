import java.io.*;
import java.util.*;
import java.lang.*;

public class numbering_1748{
    public static void main(String[] argv){
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        long start = 1, end = 10, ans = 0;
        boolean flag;
        int len=1;

        while(true){
            flag = false;
            for(long i=start; i<end; i++){
                if(i > N){
                    flag = true;
                    break;
                }
                ans += len;
            }
            if(flag)
                break;
            start *= 10;
            end *= 10;
            len++;
        }

        System.out.print(ans);
    }
}