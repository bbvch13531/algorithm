import java.io.*;
import java.util.*;
import java.lang.*;

public class hotel_room_5671{
    public static void main(String[] argv) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input;
        StringTokenizer st;
        int cnt=0;
        while((input = br.readLine()) != null){
            st = new StringTokenizer(input);
            int N = Integer.parseInt(st.nextToken());
            int M = Integer.parseInt(st.nextToken());
            cnt = 0;
            for(int i=N; i<=M; i++){
                if(countNum(i))
                    cnt++;
            }
            // System.out.println(N+" "+M+"\n");
            System.out.println(cnt);
        }
    }
    public static boolean countNum(int num){
        String str = Integer.toString(num);
        int len = str.length();
        // System.out.println(str);
        for(int i=0; i<len; i++){
            for(int j=i+1; j<len; j++){
                if(str.charAt(i) == str.charAt(j))
                    return false;
            }
        }
        return true;
    }
}