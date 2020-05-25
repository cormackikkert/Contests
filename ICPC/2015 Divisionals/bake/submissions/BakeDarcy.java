import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;
import java.util.Collections;


public class BakeDarcy {
    public static void main(String[] args){
	new BakeDarcy().run();
    }
    
    void run(){
	Scanner in = new Scanner(System.in);
	int n = in.nextInt();
	int m = in.nextInt();

	int[] p = new int[n];
	int[] q = new int[m];
	
	for(int j=0;j<6;j++){
	    String s = in.next();
	    for(int i=0;i<n;i++)
		if(s.charAt(i) == '1')
		    p[i] |= (1 << j);
	}
	
	for(int j=0;j<6;j++){
	    String s = in.next();
	    for(int i=0;i<m;i++)
		if(s.charAt(i) == '1')
		    q[i] |= (1 << j);
	}
	
	List<Integer>[] v = new List[1 << 6];
	for(int i=0;i<(1 << 6);i++)
	    v[i] = new ArrayList<>();
	
	for(int i=n-1;i>=0;i--)
	    v[p[i]].add(i+1);
	
	int ans[] = new int[m];
	int idx[] = new int[1 << 6];
	
	for(int i=0;i<m;i++){
	    int best_j = -1, best = -1;
	    for(int j=0;j<(1 << 6);j++)
		if((q[i] & j) == q[i] && idx[j] != v[j].size())
		    if(best_j == -1 || best < v[j].get(idx[j])){
			best_j = j;
			best = v[j].get(idx[j]);
		    }
	    ans[i] = best;
	    if(best_j != -1)
		idx[best_j]++;
	}
	for(int i=0;i<m;i++)
	    System.out.printf("%s%d",(i != 0 ? " " : ""),ans[i]);
	System.out.println();
    }
}
