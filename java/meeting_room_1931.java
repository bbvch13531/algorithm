import java.io.*;
import java.util.*;
import java.lang.*;

public class meeting_room_1931 {

    public static Scanner scanner = new Scanner(System.in);

    public static void main(String[] argv){
        int N = scanner.nextInt();
        Meeting[] arr = new Meeting[N];
        int end = 0, cnt = 0;
        for(int i=0; i<N; i++){
            int s, e;
            s = scanner.nextInt();
            e = scanner.nextInt();
            Meeting m = new Meeting(s, e);

            arr[i] = m;
        }

        Arrays.sort(arr);

        for(int i=0; i<arr.length; i++){
            // System.out.printf("%d %d\n", arr[i].start, arr[i].end);
            if(arr[i].start >= end){
                end = arr[i].end;
                cnt++;
            }
        }
        System.out.printf("%d",cnt);
    }
}
class Meeting implements Comparable <Meeting>{
    int start;
    int end;

    public Meeting(int s, int e){
        this.start = s;
        this.end = e;
    }

    public int compareTo(Meeting m){
        if(this.end != m.end){
            if(this.end < m.end)
                return -1;
            else
                return 1;
        }
        else{
            if(this.start < m.start)
                return -1;
            else
                return 1;
        }
    }
}
