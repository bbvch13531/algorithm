import java.io.*;
import java.lang.*;
import java.util.*;

public class difference_set_1822{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        String input;

        SortedSet<Integer> s = new TreeSet<>();
        
        int N,M,buf;

        input = br.readLine();
        st = new StringTokenizer(input);
        
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        
        st = new StringTokenizer( br.readLine());

        for(int i=0; i<N; i++){
            buf = Integer.parseInt(st.nextToken());
            s.add(buf);
        }
        
        st = new StringTokenizer( br.readLine());

        for(int i=0; i<M; i++){
            buf = Integer.parseInt(st.nextToken());
            s.remove(buf);
        }
        System.out.println(s.size());

        if(s.size() != 0){
            for(int i: s){
                System.out.printf("%d ", i);
            }
        }
    }
}