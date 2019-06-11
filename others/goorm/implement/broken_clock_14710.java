import java.io.*;
import java.util.*;
import java.lang.*;

public class broken_clock_14710{
    public static void main(String[] argv){
        Scanner sc = new Scanner(System.in);

        int th1 = sc.nextInt();
        int th2 = sc.nextInt();

        boolean flag = false;

        if(th2 % 12 == 0){
            if(th1 % 30 == th2 / 12)
                flag = true;
            else
                flag = false;
        }
        else
            flag = false;

        if(flag)
            System.out.print("O");
        else
            System.out.print("X");
    }
}