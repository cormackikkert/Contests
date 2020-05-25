import java.util.*;

public class ExtraDarcy {
    public static void main(String[] args){
	new ExtraDarcy().run();
    }

    void run(){
	Scanner in = new Scanner(System.in);
	int n = in.nextInt();
	
	List<Integer>[] graph = new List[n];
	for (int i = 0; i < n; i++) {
	    graph[i] = new ArrayList<>();
	}
	
	for(int u=0;u<n;u++){
	    int d = in.nextInt();
	    for(int j=0;j<d;j++){
		int v = in.nextInt();
		graph[u].add(v);
		graph[v].add(u);
	    }
	}

	ExtraDarcy bc = new ExtraDarcy();
	List<List<Integer>> components = bc.biconnectedComponents(graph);

	int num_comps = components.size();

	int[] my_comp = new int[n];
	for(int i=0;i<num_comps;i++)
	    for(int j=0;j<components.get(i).size();j++)
		my_comp[components.get(i).get(j)] = i;
	TreeSet<Integer>[] adj = new TreeSet[num_comps];
	for(int i=0;i<num_comps;i++)
	    adj[i] = new TreeSet<Integer>();
	
	for(int i=0;i<n;i++)
	    for(int j=0;j<graph[i].size();j++){
		int u = my_comp[i], v = my_comp[graph[i].get(j)];
		if(u != v){
		    adj[u].add(v);
		    adj[v].add(u);
		}
	    }

	int leaves = 0;
	for(int i=0;i<num_comps;i++)
	    if(adj[i].size() == 1)
		leaves++;
	if(leaves == 0) leaves++;
	System.out.println(leaves-1);
    }


    // Stole code from
    //   https://sites.google.com/site/indy256/algo/bridges
    // to see how fast it was!
    List<Integer>[] graph;
    boolean[] visited;
    Stack<Integer> stack;
    int time;
    int[] tin;
    int[] lowlink;
    List<List<Integer>> components;
    List<Integer> cutPoints;
    List<String> bridges;
    
    public List<List<Integer>> biconnectedComponents(List<Integer>[] graph) {
	int n = graph.length;
	this.graph = graph;
	visited = new boolean[n];
	stack = new Stack<>();
	time = 0;
	tin = new int[n];
	lowlink = new int[n];
	components = new ArrayList<>();
	cutPoints = new ArrayList<>();
	bridges = new ArrayList<>();

	for (int u = 0; u < n; u++)
	    if (!visited[u])
		dfs(u, -1);

	return components;
    }

    void dfs(int u, int p) {
	visited[u] = true;
	lowlink[u] = tin[u] = time++;
	stack.add(u);
	int children = 0;
	boolean cutPoint = false;
	for (int v : graph[u]) {
	    if (v == p)
		continue;
	    if (visited[v]) {
		// lowlink[u] = Math.min(lowlink[u], lowlink[v]);
		lowlink[u] = Math.min(lowlink[u], tin[v]);
	    } else {
		dfs(v, u);
		lowlink[u] = Math.min(lowlink[u], lowlink[v]);
		cutPoint |= lowlink[v] >= tin[u];
		//if (lowlink[v] == tin[v])
		if (lowlink[v] > tin[u])
		    bridges.add("(" + u + "," + v + ")");
		++children;
	    }
	}
	if (p == -1)
	    cutPoint = children >= 2;
	if (cutPoint)
	    cutPoints.add(u);
	if (lowlink[u] == tin[u]) {
	    List<Integer> component = new ArrayList<>();
	    while (true) {
		int x = stack.pop();
		component.add(x);
		if (x == u)
		    break;
	    }
	    components.add(component);
	}
    }
}
