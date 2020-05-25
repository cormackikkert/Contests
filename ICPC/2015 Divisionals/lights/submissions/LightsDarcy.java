import java.util.Scanner;

public class LightsDarcy {
    public static void main(String[] args){
	new LightsDarcy().run();
    }
    
    void run(){
	Scanner in = new Scanner(System.in);
	int n = in.nextInt();
	int d = in.nextInt();

	boolean ans = true;
	for(int i=0;i<n;i++){
	    int x = in.nextInt();
	    int a = in.nextInt();
	    int g = in.nextInt();
	    int r = in.nextInt();

	    if(x < a || ((x-a) % (g+r) > g))
		ans = false;
	}

	System.out.println(ans ? "YES" : "NO");
    }
}
