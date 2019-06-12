import java.io.*;
import java.util.*;
import java.lang.*;

public class seven_percent_4606{
    public static void main(String[] argv) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input;
        int len=0;
        char ch;

        while(true){
            input = br.readLine();
            if(input.equals("#"))
                break;
            len = input.length();

            for(int i=0; i<len; i++){
                ch = input.charAt(i);

                if(ch == ' ')
                    System.out.print("%20");
                else if(ch == '!')
                    System.out.print("%21");
                else if(ch == '$')
                    System.out.print("%24");
                else if(ch == '%')
                    System.out.print("%25");
                else if(ch == '(')
                    System.out.print("%28");
                else if(ch == ')')
                    System.out.print("%29");
                else if(ch == '*')
                    System.out.print("%2a");
                else
                    System.out.print(ch);
            }
            System.out.println();
        }
    }
}