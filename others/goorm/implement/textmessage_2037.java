import java.io.*;
import java.lang.*;
import java.util.*;

public class textmessage_2037{
    public static void main(String[] argv) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        StringTokenizer str = new StringTokenizer(br.readLine());

        int time=0;
        int P = Integer.parseInt(str.nextToken());
        int W = Integer.parseInt(str.nextToken());
        // String ign = br.readLine();
        String s =  br.readLine();
        int len = s.length();

        for(int i=0; i<len-1; i++){
            if(isSame(s.charAt(i), s.charAt(i+1)))
                time += W;
        }

        for(int i=0; i<len; i++){
            time += P * retTime(s.charAt(i));
        }
        System.out.print(time);
        // System.out.printf("%d %d %s\n", P, W, s);
    }
    public static int retTime(char a){
        String []text = {"ADGJMPTW", "BEHKNQUX", "CFILORVY", "SZ"};

        if(a == ' ')
            return 1;

        for(int i=0; i<4; i++){
            int len = text[i].length();
            for(int j=0; j<len; j++){
                if(a == text[i].charAt(j))
                    return i+1;
            }
        }
        return 0;
    }
    public static boolean isSame(char a, char b){
        String []msg = { "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};
    
        for(int i=0; i<8; i++){
            int len = msg[i].length();

            for(int j=0; j<len; j++){
                for(int k=0; k<len; k++){
                    if(msg[i].charAt(j) == a && msg[i].charAt(k) == b)
                        return true;
                }
            }
        }
        return false;
    }
}