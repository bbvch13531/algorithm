import java.io.*;
import java.util.*;
import java.lang.*;

public class knights_tour_1331{
    public static void main(String[] argv){
        Scanner sc = new Scanner(System.in);
        int []mx = new int [40];
        int []my = new int [40];
        int []dx = {-1, -2, -2, -1, 1, 2, 2, 1};
        int []dy = {-2, -1, 1, 2, 2, 1, -1, -2};
        boolean [][]visit = new boolean[10][10];

        int curx, cury;
        boolean flag = false;
        String in;
        char ch;

        for(int i=0; i<36; i++){
            in = sc.nextLine();
            // System.out.print(in.charAt(0));
            // System.out.println(in.charAt(1));
            mx[i] = in.charAt(0) - 'A';
            my[i] = Character.getNumericValue(in.charAt(1));
        }
        mx[36] = mx[0];
        my[36] = my[0];

        for(int i=0; i<36; i++){
            flag = false;

            for(int j=0; j<8; j++){
                curx = mx[i] + dx[j];
                cury = my[i] + dy[j];
                // System.out.printf("%d %d\n", curx, cury);
                if(0 <= curx && curx < 7 && 0 <= cury && cury < 7){
                    if(curx == mx[i+1] && cury == my[i+1] && !visit[curx][cury]){
                        // System.out.printf("next step in %d %d\n", curx, cury);
                        flag = true;
                        visit[curx][cury] = true;
                        break;
                    }
                }
            }
            if(!flag)
                break;
        }
        if(flag)
            System.out.print("Valid");
        else
            System.out.print("Invalid");
        
    }
}