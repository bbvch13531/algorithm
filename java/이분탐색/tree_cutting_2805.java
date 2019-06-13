import java.io.*;
import java.lang.*;
import java.util.*;

public class tree_cutting_2805{
    public static void main(String[] argv) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st; 
        String inputBuf;
        long N, M;
        // long []trees;
        ArrayList<Long> trees = new ArrayList<>();
        long maxInput=0, lo, hi, mid=0, maxHeight=0, sum=0;

        inputBuf = br.readLine();
        st = new StringTokenizer(inputBuf);
        N = Long.parseLong(st.nextToken());
        M = Long.parseLong(st.nextToken());
        
        inputBuf = br.readLine();
        // System.out.printf("%s %d %d\n", inputBuf, N, M);
        st = new StringTokenizer(inputBuf);
        for(int i=0; i<N; i++){
            Long buf = Long.parseLong(st.nextToken());
            // System.out.printf("%d ",buf);
            if(buf > maxInput)
                maxInput = buf;
            trees.add(buf);
        }

        lo = 0;
        hi = maxInput;
        
        while(lo<hi){
            sum = 0;
            mid = (lo+hi)/2;
            for(int i=0; i<N; i++){
                if(trees.get(i) > mid)
                    sum += trees.get(i) - mid;
            }
            // System.out.printf("%d %d %d\n", lo, mid, hi);
            if(sum >= M){
                maxHeight = mid;
                lo = mid + 1;
            }
            else{
                hi = mid;
            }
        }

        System.out.print(maxHeight);
    }
}