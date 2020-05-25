 import java.util.*;

public class ExtraMax {

  static List<Integer>[] graph;
  static boolean[] visited;
  static Stack<Integer> stack;
  static int time;
  static int[] tin;
  static int[] lowlink;
  static List<List<Integer>> components;
  static List<Integer> cutPoints;
  static HashSet<Integer>[] bridges;


  static public List<List<Integer>> biconnectedComponents(List<Integer>[] g) {
    int n = g.length;
    graph = g;
    visited = new boolean[n];
    stack = new Stack<>();
    time = 0;
    tin = new int[n];
    lowlink = new int[n];
    components = new ArrayList<>();
    cutPoints = new ArrayList<>();
    bridges = (HashSet<Integer>[]) new HashSet[n];
    for (int u = 0; u < n; u++) {
      bridges[u] = new HashSet<Integer>();
    }

    for (int u = 0; u < n; u++) {
      if (!visited[u])
        dfs(u, -1);
    }

    return components;
  }

  static void dfs(int u, int p) {
    visited[u] = true;
    lowlink[u] = tin[u] = time++;
    stack.add(u);
    int children = 0;
    boolean cutPoint = false;
    for (int v : graph[u]) {
      if (v == p)
        continue;
      if (visited[v]) {
        lowlink[u] = Math.min(lowlink[u], tin[v]);
      } else {
        dfs(v, u);
        lowlink[u] = Math.min(lowlink[u], lowlink[v]);
        cutPoint |= lowlink[v] >= tin[u];
        if (lowlink[v] > tin[u]) {
          bridges[u].add(v);
          bridges[v].add(u);
        }
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


  static int[] vis;

  static int leaves = 0;
  static List<Integer>[] adj;

  static int dfs(int at) {
    vis[at] = 1;
    int cnt = 0;
    for (int c : adj[at]) {
      if (vis[c] == 0) {
        if (bridges[at].contains(c)) {
          ++cnt;
          if (dfs(c) == 0)
            ++leaves;
        } else {
          cnt += dfs(c);
        }
      }
    }
    return cnt;
  }


  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int S = sc.nextInt();
    adj = new ArrayList[S];
    for (int i = 0; i < S; ++i) {
      adj[i] = new ArrayList<Integer>();
    } 
    for (int i = 0; i < S; ++i) {
      int l = sc.nextInt();
      for (int j = 0; j < l; ++j) {
        int s = sc.nextInt();
        adj[i].add(s);
        adj[s].add(i);
      }
    }

    List<List<Integer>> components = biconnectedComponents(adj);

    if (components.size() == 1) {
      System.out.println(0);
      return;
    }

    vis = new int[S];

    if (dfs(0) == 1)
      ++leaves;

    System.out.println(leaves-1);
  }
}
