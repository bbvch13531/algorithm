import java.io.*;
import java.lang.*;
import java.util.*;

public class office_people_7785{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        Set<String> s = new TreeSet<String>();

        int N = Integer.parseInt(st.nextToken());
        String name, cmd;

        for(int i=0; i<N; i++){
            st = new StringTokenizer(br.readLine());
            name = st.nextToken();
            cmd = st.nextToken();

            if(cmd.equals("enter")){
                s.add(name);
            }
            else if(cmd.equals("leave")){
                s.remove(name);
            }
        }

        ArrayList<String> ar = new ArrayList(s);
        Collections.sort(ar, Collections.reverseOrder());

        for(String ans: ar){
            System.out.println(ans);
        }
    }
}