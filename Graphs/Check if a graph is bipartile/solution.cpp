class PossibleBipartition {
	private static boolean graphColoring(ArrayList<Integer>[] adjList, int node, int color, int[] colorArr) {
		colorArr[node] = color;
		for(int nxt : adjList[node]) {
			if(colorArr[nxt] != 0) {
				if(colorArr[nxt] == color) {
					return false;
				}
			} else {
				if(!graphColoring(adjList, nxt, -1 * color, colorArr)) {
					return false;
				}
			}
		}
		return true;
	}
  //Used the concept of graph coloring
	private static String possibleBipartition(int n, Vector<Vector<Integer> > edges) {
		ArrayList<Integer>[] adjList = new ArrayList[n + 1];
		int[] color = new int[n + 1];
		for(int i=0;i<=n;i++) {
			adjList[i] = new ArrayList<Integer>();
			color[i] = 0;
		}
		for(int i=0;i<edges.size();i++) {
			int u = edges.get(i).get(0);
			int v = edges.get(i).get(1);
			adjList[u].add(v);
			adjList[v].add(u);
		}
		if(graphColoring(adjList,1,1,color)) {
			return "Possible";
		}
		return "Not Possible";
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int tests = 0; tests < t; tests++) {
			int n = sc.nextInt();
			int m = sc.nextInt();

			Vector<Vector<Integer> > edges = new Vector<Vector<Integer> >();
			for (int i = 0; i < m; i++) {
				int u = sc.nextInt();
				int v = sc.nextInt();
				Vector<Integer> edge = new Vector<Integer>();
				edge.add(u);
				edge.add(v);
				edges.add(edge);
			}
			System.out.println(possibleBipartition(n, edges));
		}
		sc.close();
	}
}
