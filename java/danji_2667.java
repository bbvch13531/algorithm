import java.io.*;
import java.util.*;
import java.lang.*;

public class danji_2667{
    public static void main(String[] argv){
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner scn = new Scanner(System.in);

        int []dx = {0, 1, 0, -1};
        int []dy = {1, 0, -1, 0};

        Stack<Point> stk = new Stack<Point>();
        Vector<Integer> val = new Vector<Integer>();

        StringBuilder []in = new StringBuilder[30];

        int N = Integer.parseInt(scn.nextLine());
        int num=0, cnt=0;

        for(int i=0; i<N; i++){
            String str = scn.next();
            in[i] = new StringBuilder(str);
        }

        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(in[i].charAt(j) == '1'){
                    val.add(num);
                    cnt++;
                    num=0;
                    in[i].setCharAt(j, '0');
                    stk.push(new Point(i, j));
                }
                while(!stk.isEmpty()){
                    int x = stk.peek().x;
                    int y = stk.peek().y;

                    stk.pop();

                    for(int k=0; k<4; k++){
                        int nx = x + dx[k];
                        int ny = y + dy[k];

                        if(isValid(nx, ny, N)){
                            if(in[nx].charAt(ny) == '1'){
                                in[nx].setCharAt(ny, '0');
                                stk.push(new Point(nx, ny));
                            }
                        }
                    }
                    num++;
                }
            }
        }
        val.add(num);
        Collections.sort(val);

        System.out.println(cnt);
        for(int i=1; i<=cnt; i++){
            System.out.println(val.get(i));
        }
    }
    private static boolean isValid(int x, int y, int N){
        if(0<= x && x < N && 0 <= y && y < N){
            return true;
        }
        return false;
    }
}
class Point{
    int x;
    int y;

    public Point(int x, int y){
        this.x = x;
        this.y = y;
    }
}