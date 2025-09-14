import java.util.*;


class CycleDirectedGraphDSAMOCK{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int e = sc.nextInt();
        int[][] edges = new int[e][2];
        for(int i=0;i<e;i++){
            int a,b;
            a = sc.nextInt();
            b = sc.nextInt();
            edges[i][0]=a;
            edges[i][1]=b;
        }
        System.out.println(cycleDirectedGraph(n, edges));
        sc.close();
    }
    //Used Kahns Algorithm
    static int cycleDirectedGraph(int n, int[][] edges){
        //Stored Graph in an adjacent list
        //Added a queue, visited array to ensure nodes are visited only once else cycle is detected. Even if nodes are not visited at the end or there is a dependency, cycle is present
        List<Integer>[] adjList = new ArrayList[n + 1];
        boolean[] visited = new boolean[n + 1];
        Queue<Integer> q = new LinkedList<>();
        int[] degree = new int[n + 1];
        for(int i = 0; i <= n; i++) {
            degree[i] = 0;
            visited[i] = false;
            adjList[i] = new ArrayList<>();
        }
        for(int i = 0; i < edges.length; i++) {
            adjList[edges[i][0]].add(edges[i][1]);
            degree[edges[i][1]]++;
        }
        for(int i = 1; i <= n; i++) {
            if(degree[i] == 0) {
                q.add(i);
            }
        }
        while(!q.isEmpty()) {
            int node = q.remove();
            visited[node] = true;
            for(int nextNode : adjList[node]) {
                if(visited[nextNode] == true) {
                    return 1;
                }
                degree[nextNode]--;
                if(degree[nextNode] == 0) {
                    q.add(nextNode);
                }
                //visited[nextNode] = true;
            }
        }
        for(int i = 1; i <= n; i++) {
            if(visited[i] == false) {
                return 1;
            }
        }
        return 0;
    }

}
