import java.util.Scanner;
import java.lang.Math;

public class KeepDarcy {
    public static void main(String[] args){
	new KeepDarcy().run();
    }

    public class Umbrella {
	int x,y,r;
	public Umbrella(int x,int y,int r){
	    this.x = x;
	    this.y = y;
	    this.r = r;
	}
    };

    double dist(Umbrella a, Umbrella b){
	double d = Math.hypot(a.x-b.x,a.y-b.y)-a.r-b.r;
	return (d < 0 ? 0 : d);
    }
    
    void run(){
	double EPS = 1e-8;
	
	Scanner in = new Scanner(System.in);
	int n = in.nextInt();
	int K = in.nextInt();
	int x = in.nextInt();
	int y = in.nextInt();

	Umbrella[] p = new Umbrella[n+1];

	for(int i=0;i<n;i++)
	    p[i] = new Umbrella(in.nextInt(),in.nextInt(),in.nextInt());
	p[n] = new Umbrella(0,0,0);
	n++;

	double[][] A = new double[n][n];
	for(int i=0;i<n;i++)
	    for(int j=0;j<n;j++)
		A[i][j] = -1;

	for(int i=0;i<n;i++)
	    for(int j=0;j<n;j++){
		if(dist(p[i],p[j]) > K+EPS) continue;
		A[i][j] = dist(p[i],p[j]);
	    }
	
	for(int k=0;k<n;k++)
	    for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
		    if(A[i][k] < -0.5 || A[k][j] < -0.5) continue;
		    if(A[i][j] < -0.5 || A[i][j] > A[i][k] + A[k][j])
			A[i][j] = A[i][k] + A[k][j];
		}

	
	Umbrella ball = new Umbrella(x,y,0);

	double best = -1;
	for(int i=0;i<n;i++)
	    for(int j=0;j<n;j++){
		if(A[n-1][i] < -0.5) continue;
		if(A[j][n-1] < -0.5) continue;
		double d = dist(p[i],ball) + dist(ball,p[j]);
		if(d > K+EPS) continue;
		
		d += A[n-1][i] + A[j][n-1];
		
		if(best < -0.5 || best > d)
		    best = d;
	    }
	
	if(best < -0.5) System.out.println("-1");
	else System.out.printf("%.10f\n",best);
    }
}
