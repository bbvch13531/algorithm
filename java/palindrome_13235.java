import java.io.*;
import java.util.*;
import java.lang.*;

public class palindrome_13235{
    
    public static void main(String [] argv){
        StringBuilder sb = new StringBuilder();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String in = new String();
        try {
            in = br.readLine();
        } catch (Exception e){
            e.printStackTrace();
        }
        int flag = 1;
        int len = in.length();
        for(int i=0; i<len/2; i++){
            if(in.charAt(i) != in.charAt(len-i-1)){
                flag = 0;
                break;
            }
        }
        if(flag == 1)
            System.out.println("true");
        else
            System.out.println("false");
            
    }
}