import java.util.*;

public class DeckDarcy {
    public static void main(String[] args){
	new DeckDarcy().run();
    }

    void run(){
	Scanner in = new Scanner(System.in);
	int m = in.nextInt();
	int r = in.nextInt();

    String[] M = new String[m];
	String[] R = new String[r+1];

	for(int i=0;i<m;i++)
	    M[i] = in.next();
	for(int i=0;i<=r;i++)
	    R[i] = in.next();

	List<Integer>[] G1 = new List[m];
	List<Integer>[] G2 = new List[m];
	
	for(int i=0;i<m;i++){
	    G1[i] = new ArrayList<>();
	    G2[i] = new ArrayList<>();
	}

	for(int i=0;i<m;i++)
	    for(int j=0;j<=r;j++)
		if(M[i].charAt(0) == R[j].charAt(0) ||
		   M[i].charAt(1) == R[j].charAt(1)){
		    G1[i].add(j);
		    if(j != r) G2[i].add(j);
		}

	int match1 = maxMatching(G1, r+1);
	int match2 = maxMatching(G2, r);
	
	System.out.println(match1 == match2 ? "Richard" : "Malcolm");
    }


    // Stole code from
    //   https://sites.google.com/site/indy256/algo/kuhn_matching2
    // to see how fast it was!
    public static int maxMatching(List<Integer>[] graph, int n2) {
	int n1 = graph.length;
	int[] matching = new int[n2];
	Arrays.fill(matching, -1);
	int matches = 0;
	for (int u = 0; u < n1; u++) {
	    if (findPath(graph, u, matching, new boolean[n1]))
		++matches;
	}
	return matches;
    }

    static boolean findPath(List<Integer>[] graph, int u1, int[] matching, boolean[] vis) {
	vis[u1] = true;
	for (int v : graph[u1]) {
	    int u2 = matching[v];
	    if (u2 == -1 || !vis[u2] && findPath(graph, u2, matching, vis)) {
		matching[v] = u1;
		return true;
	    }
	}
	return false;
    }
}
