import java.io.*;
import java.util.*;
import java.lang.*;

public class password_4659{
    public static void main(String [] argv) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        boolean flag = false;
        int len;
        while(true){
            String input = br.readLine();
            if(input.equals("end"))
                break;
            len = input.length();
            flag = false;
            for(int i=0; i<len; i++){
                if(isVowel(input.charAt(i))){
                    flag = true;
                    break;
                }
            }
            if(!flag){
                System.out.println("<"+input+"> is not acceptable.");
                continue;
            }
            flag = true;

            for(int i=0; i<len-2; i++){
                char ch1 = input.charAt(i);
                char ch2 = input.charAt(i+1);
                char ch3 = input.charAt(i+2);

                if(isVowel(ch1) && isVowel(ch2) && isVowel(ch3)){
                    flag = false;
                    break;
                }
                if(!isVowel(ch1) && !isVowel(ch2) && !isVowel(ch3)){
                    flag = false;
                    break;
                }
            }
            if(!flag){
                System.out.println("<"+input+"> is not acceptable.");
                continue;
            }
            flag = true;
            for(int i=0; i<len-1; i++){
                char ch1 = input.charAt(i);
                char ch2 = input.charAt(i+1);

                if(ch1 == ch2 && ch1 != 'e' && ch1 != 'o'){
                    flag = false;
                    break;
                }
            }
            if(flag)
                System.out.println("<"+input+"> is acceptable.");
            else
                System.out.println("<"+input+"> is not acceptable.");
        }
    }
    public static boolean isVowel(char ch){
        char []vowels = {'a', 'e', 'o', 'u', 'i'};

        for(int i=0; i<5; i++){
            if(ch == vowels[i])
                return true;
        }
        return false;
    }
}