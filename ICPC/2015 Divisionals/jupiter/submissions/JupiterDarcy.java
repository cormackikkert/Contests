import java.util.Scanner;
import java.lang.Math;

public class JupiterDarcy {
    public static void main(String[] args){
	new JupiterDarcy().run();
    }

    int n,k,l,m;
    
    void run(){
	Scanner in = new Scanner(System.in);
	n = in.nextInt();
	k = in.nextInt();
	l = in.nextInt();
	m = in.nextInt();

	String s = in.next();
	String t = in.next();

	int winner = phase1(s,t);

	String answer = "Draw";
	if(winner == -1) answer = "Bob";
	if(winner ==  1) answer = "Alice";
	
	System.out.println(answer);
    }

    int phase1(String s,String t){
	int best = -1;
	for(int i=0;i<=n-k;i++)
	    best = Math.max(best,phase2(s.substring(i,i+k),t));
	return best;
    }

    int phase2(String s,String t){
	int best = 1;
	for(int i=0;i<=n-k;i++)
	    best = Math.min(best,phase3(s,t.substring(i,i+k)));
	return best;
    }

    int phase3(String s,String t){
	int best = -1;
	for(int i=0;i<=k-l;i++)
	    best = Math.max(best,win(morph(s,i),t));
	return best;
    }

    String morph(String s,int st){
	String moves = "RPSR";
	String ans = "";
	for(int i=0;i<st;i++) ans += s.charAt(i);
	for(int i=st;i<st+l;i++) ans += moves.charAt(1+moves.indexOf(s.charAt(i)));
	for(int i=st+l;i<s.length();i++) ans += s.charAt(i);
	return ans;
    }

    int win(String s,String t){
	String moves = "PRSPRS";
	int wins[] = new int[3];
	for(int i=0;i<k;i++){
	    int me = moves.indexOf(s.charAt(i));
	    //System.out.println(me + " " + moves.substring(me));
	    int you = moves.substring(me).indexOf(t.charAt(i))+me;
	    wins[you-me]++;
	    if(you != me && wins[you-me] == m)
		return (you-me == 2 ? -1 : 1);
	}
	return 0;
    }
}
