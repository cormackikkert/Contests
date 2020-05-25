 import java.util.*;

public class DeckMax {

  public static int maxMatching(boolean[][] graph) {
    int n1 = graph.length;
    int n2 = n1 == 0 ? 0 : graph[0].length;
    int[] matching = new int[n2];
    Arrays.fill(matching, -1);
    int matches = 0;
    for (int u = 0; u < n1; u++)
      if (findPath(graph, u, matching, new boolean[n1]))
        ++matches;
    return matches;
  }

  static boolean findPath(boolean[][] graph, int u1, int[] matching, boolean[] vis) {
    vis[u1] = true;
    for (int v = 0; v < matching.length; ++v) {
      int u2 = matching[v];
      if (graph[u1][v] && (u2 == -1 || !vis[u2] && findPath(graph, u2, matching, vis))) {
        matching[v] = u1;
        return true;
      }
    }
    return false;
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int M = sc.nextInt();
    ++M;
    String[] malcolm = new String[N];
    String[] richard = new String[M];
    for (int i = 0; i < N; ++i)
      malcolm[i] = sc.next();
    for (int i = 0; i < M; ++i)
      richard[i] = sc.next();
    boolean[][] g = new boolean[N][M];
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M-1; ++j) {
        if (malcolm[i].charAt(0) == richard[j].charAt(0) || malcolm[i].charAt(1) == richard[j].charAt(1)) {
          g[i][j] = true;
        }
      }
    }
    int f = maxMatching(g);
    for (int i = 0; i < N; ++i) {
      if (malcolm[i].charAt(0) == richard[M-1].charAt(0) || malcolm[i].charAt(1) == richard[M-1].charAt(1)) {
        g[i][M-1] = true;
      }
    }
    int fp = maxMatching(g);
    System.out.println(f == fp ? "Richard" : "Malcolm");
  }
}
