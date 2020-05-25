import java.util.Scanner;
import java.lang.Math;

public class FrontDarcy {
    public static void main(String[] args){
	new FrontDarcy().run();
    }
    
    int n,h;

    double[][] DP;
    int[] P;

    int fix(int y){
	if(y < 0) return 0;
	if(y > h) return h;
	return y;
    }
    
    double f(int i,int j){
	if(DP[j][i] >= -0.5) return DP[j][i];
	if(i == n) return 0;
	
	double ans = 0;
	for(int x=-1;x<=1;x++){
	    int nJ = fix(j+x);
	    ans += P[x+1] / 100.0 * (f(i+1,nJ) + Math.min(j,nJ) + (j == nJ ? 0 : 0.5));
	}
	
	return DP[j][i] = ans;
    }
    
    void run(){
	Scanner in = new Scanner(System.in);
	n = in.nextInt();
	h = in.nextInt();
	int a = in.nextInt();

	P = new int[3];
	for(int i=0;i<3;i++)
	    P[i] = in.nextInt();

	DP = new double[h+1][n+1];
	for(int i=0;i<=h;i++)
	    for(int j=0;j<=n;j++)
		DP[i][j] = -1;

	System.out.printf("%.10f\n",f(0,a));
    }
}
