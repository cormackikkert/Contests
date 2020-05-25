import java.util.Scanner;

public class GreedyDarcy {
    public static void main(String[] args){
	new GreedyDarcy().run();
    }

    int[] coins;
    int[] machine;
    
    int[] read(Scanner in){
	int A[] = new int[6];
	for(int i=0;i<6;i++)
	    A[i] = in.nextInt();
	return A;
    }
    
    boolean make_change(int amt){
	for(int i=5, tmp_amt = amt;i>=0;i--){
	    int ctr = 0;
	    while(tmp_amt >= coins[i]){
		tmp_amt -= coins[i];
		ctr++;
	    }
	    if(ctr > machine[i])
		return false;
	}
	
	for(int i=5;i>=0;i--)
	    while(amt >= coins[i]){
		amt -= coins[i];
		machine[i]--;
	    }
	return true; 
    }
    
    void run(){
	coins = new int[]{1,2,5,10,20,50};
	Scanner in = new Scanner(System.in);

	int[] std = read(in);
	machine = new int[6];
	for(int i=0;i<6;i++) machine[i] = std[i];

	int T = in.nextInt();
	int ans = 0;

	while(T-- > 0){
	    int V = in.nextInt();
	    int[] d = read(in);
	    int amt = 0;
	    for(int i=0;i<6;i++) amt += d[i] * coins[i];
	    for(int i=0;i<6;i++) machine[i] += d[i];
	    amt -= V;
	    if(make_change(amt)) continue;
	    int before = amt;
	    for(amt++ ; !make_change(amt) ; amt++) { }
	    for(int i=0;i<6;i++) machine[i] = std[i];
	    ans += amt-before;
	}
	System.out.println(ans);
    }
}
