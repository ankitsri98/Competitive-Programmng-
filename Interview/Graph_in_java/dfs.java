import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.io.FileNotFoundException;
import java.lang.*;
import java.util.Stack;


class Graph {
    List<List<Integer>> graph;
    boolean vis[];

    Graph(int nodes) {
        graph = new ArrayList<>();
        vis = new boolean[nodes];

        for(int i=0;i<nodes;i++) {
            graph.add(i, new ArrayList<>());
        }
    }

    public void addEdge(int a, int b) {
        graph.get(a).add(b);
        graph.get(b).add(a);
    }

    void dfs() {

        Stack<Integer> stack = new Stack<>();
        vis[0] = true;
        stack.push(0);

        while(!stack.isEmpty()) {
            Integer n  = stack.pop();
            System.out.print(n + " ");
            List<Integer> childList = graph.get(n);

            for(Integer child : childList) {
                if(!vis[child]) {
                    stack.push(child);
                    vis[child] = true;
                }
            }
        }
    }


}
public class Code {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(System.in);

//        try(Scanner sc = new Scanner(new File("input.txt"));
//            PrintWriter op = new PrintWriter("output.txt");){

            int n = sc.nextInt();
            int e = sc.nextInt();
            int x, y;
            Graph g = new Graph(n);
            for(int i=0;i<e;i++) {
                x = sc.nextInt();
                y = sc.nextInt();
                g.addEdge(x, y);
                g.addEdge(y, x);
            }
            g.dfs();
           // op.println(solve(x, arr));

        //}
    }
}
