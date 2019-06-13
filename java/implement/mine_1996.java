import java.io.*;
import java.util.*;
import java.lang.*;

public class mine_1996{
    public static void main(String[] argv) throws IOException{
        Scanner sc = new Scanner(System.in);
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int []dx = {-1, -1, -1, 0, 1, 1, 1, 0};
        int []dy = {-1, 0, 1, 1, 1, 0, -1, -1};

        int N = Integer.parseInt(br.readLine());
        String []map = new String[1010];
        int [][]ans = new int[1010][1010];
        // System.out.println(N);

        for(int i=0; i<N; i++){
            map[i] = br.readLine();
            // System.out.println(map[i]);
        }

        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                char ch = map[i].charAt(j);
                if(ch != '.'){
                    int num = ch - '0';
                    for(int m=0; m<8; m++){
                        int nx = i + dx[m];
                        int ny = j + dy[m];

                        if(0 <= nx && nx < N && 0 <= ny && ny < N){
                            if(ans[nx][ny] + num > 9)
                                ans[nx][ny] = 11;
                            else 
                                ans[nx][ny] += num;
                        }
                    }
                }
            }
        }
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(map[i].charAt(j) != '.')
                    System.out.print("*");
                else if(ans[i][j] == 11)
                    System.out.print("M");
                else
                    System.out.print(ans[i][j]);
            }
            System.out.println();
        }
        
    }
}