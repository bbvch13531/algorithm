import java.io.*;
import java.util.*;
import java.lang.*;

public class shortest_path_1753{

    public static Scanner scanner = new Scanner(System.in);
    public static PriorityQueue <Pair> pq = new PriorityQueue<>();

    public static void main(String[] argv){
        int V, E, K;
        // ArrayList<Pair>[] W = new ArrayList<Pair>[20010];
        Vector<Vector<Pair>> W = new Vector<Vector<Pair>>();
        int []dist = new int[20010];
        Arrays.fill(dist, 987654321);

        V = scanner.nextInt();
        E = scanner.nextInt();
        K = scanner.nextInt();
        for(int i=0; i<=V; i++){
            W.add(new Vector<Pair>());
        }
        for(int i=0; i<E; i++){
            int u = scanner.nextInt();
            int v = scanner.nextInt();
            int w = scanner.nextInt();
            
            // W.get(u);
            W.get(u).add(new Pair(v, w));
        }
        dist[K] = 0;
        
        pq.add(new Pair(K, 0));

        while(pq.size() != 0){
            Pair nextp = pq.poll();
            int here = nextp.des;
            int w = nextp.w;

            if(w > dist[here])
                continue;
            for(int i=0; i<W.get(here).size(); i++){
                Pair p2 = W.get(here).get(i);
                int near = p2.des;
                int near_w = w + p2.w;

                if(near_w < dist[near]){
                    dist[near] = near_w;
                    
                    pq.add(new Pair(near, near_w));
                }
            }
        }
        for(int i=1; i<=V; i++){
            if(dist[i] == 987654321)
                System.out.println("INF");
            else
                System.out.println(dist[i]);
                
        }
    }
}
class Pair implements Comparable<Pair>{
    int des;
    int w;

    public Pair(int des, int w){
        this.des = des;
        this.w = w;
    }

    @Override
    public int compareTo(Pair target){
        if(this.w > target.w)
            return 1;
        else if(this.w == target.w)
            return 0;
        else
            return -1;
    }
}     

