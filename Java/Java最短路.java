/*
	优先队列
	n个点,m条边
	计算从a到其他点的距离
*/
import javafx.util.Pair;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
    static class Edge{   //边
        public int now;
        public int next;
        public int val;

        public Edge(int now, int next, int val) {
            this.now = now;
            this.next = next;
            this.val = val;
        }
    }
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int n=cin.nextInt(); //点数
        ArrayList<Edge>[] edges = new ArrayList[n];
        for(int i=0;i<n;i++){
            edges[i] = new ArrayList<Edge>();
        }
        int m = cin.nextInt(); //边数
        for(int i=0;i<m;i++){
            int now,next,val;
            now=cin.nextInt();
            next=cin.nextInt();
            val=cin.nextInt();
            edges[now-1].add(new Edge(now-1,next-1,val));
            edges[next-1].add(new Edge(next-1,now-1,val));
        }
        int a=0,b=n-1;
        int []dis=new int[n];
        for(int i=0;i<n;i++){
            dis[i]=0x3f3f3f3f;
        }
        Comparator<Pair<Integer,Integer>> integerComparator = new Comparator<Pair<Integer,Integer>>() {
            @Override
            public int compare(Pair<Integer,Integer> o1, Pair<Integer,Integer> o2) {
                return o1.getValue()-o2.getValue();
            }
        };
        PriorityQueue<Pair<Integer,Integer>>que=new PriorityQueue<Pair<Integer,Integer>>(integerComparator);
        dis[a]=0;
        que.add(new Pair<Integer,Integer>(a,0));
        while(!que.isEmpty()){
            Pair<Integer,Integer>top=que.poll();
            for (Edge e:edges[top.getKey().intValue()]) {
                int now=e.now;
                int next=e.next;
                int val=e.val;
                if(dis[now]+val<dis[next]){
                    dis[next]=dis[now]+val;
                    que.add(new Pair<Integer,Integer>(next,val));
                }
            }
        }
        for(int i=0;i<n;i++){
            System.out.println(dis[i]);
        }
    }
}
