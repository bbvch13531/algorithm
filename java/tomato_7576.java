import java.io.*;
import java.util.*;
import java.lang.*;

public class tomato_7576{
    public static int M, N;
    public static int [][]map = new int[1010][1010];
    public static void main(String[] argv){
        Scanner scanner = new Scanner(System.in);

        
        int []dx = {0, 1, 0, -1};
        int []dy = {1, 0, -1, 0};

        Queue <Tmt> q = new LinkedList<Tmt>();
        int M, N;
        int cnt=0;
        M = scanner.nextInt();
        N = scanner.nextInt();

        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                map[i][j] = scanner.nextInt();
                // System.out.printf("%d %d %d\n", i, j, map[i][j]);
                if(map[i][j] == 1){
                    q.offer(new Tmt(i, j, 0));
                }
            }
        }

        while(q.isEmpty() == false){
            int tx = q.peek().x;
            int ty = q.peek().y;
            cnt = q.peek().day;
            
            // System.out.printf("%d %d %d %d\n", tx, ty, cnt, q.size());
            q.poll();

            for(int i=0; i<4; i++){
                int nx = tx + dx[i];
                int ny = ty + dy[i];

                if(isValid(nx, ny, N, M)){
                    // System.out.printf("inner %d %d\n", nx, ny);
                    if(map[nx][ny] == 0){
                        map[nx][ny] = 1;
                        q.offer(new Tmt(nx, ny, cnt+1));
                    }
                }
            }
        }
        // System.out.printf("%d",map[0][0]);
        // System.out.println(isFinished(map, N, M));

        if(isFinished(map, N, M))
            System.out.print(cnt);
        else
            System.out.print(-1);
    }
    private static boolean isValid(int x, int y, int N, int M){
        // System.out.printf("isValid %d %d %d %d\n", x, y, N, M);
        if(0<= x && x < N && 0 <= y && y < M)
            return true;
        else
            return false;
    }
    private static boolean isFinished(int [][]map,int N, int M) {
        int flag = 1;
        // System.out.printf("%d %d\n", N, M);

        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                // System.out.printf("%d %d %d %d\n", i, j, N, M);
                if(map[i][j] == 0){
                    flag = 0;
                    return false;
                }
            }
            // System.out.println();
        }

        return true;
    }
}
class Tmt{
    int x;
    int y;
    int day;

    public Tmt(int x, int y, int day){
        this.x = x;
        this.y = y;
        this.day = day;
    }
}
/*
6 4
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 1

6 4
0 -1 0 0 0 0
-1 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 1
*/