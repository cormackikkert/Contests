import java.util.Scanner;

public class CleverDarcy {
    public static void main(String[] args){
	new CleverDarcy().run();
    }
    
    void run(){
	Scanner in = new Scanner(System.in);
	int n = in.nextInt();
	int k = in.nextInt();

	String[] names = new String[n];
	for(int i=0;i<n;i++)
	    names[i] = in.next();

	for(int i=0;i<k;i++)
	    System.out.println(count(names,in.next()));
    }

    int count(String[] names,String word){
	if(word.length() != names.length) return 0;
	int n = word.length();
  
	int[] DP = new int[1 << n];
	DP[0] = 1;
	
	for(int i=1;i<(1 << n);i++){
	    char lett = word.charAt(Integer.bitCount(i)-1);
	    for(int j=0;j<n;j++)
		if(((i >> j) & 1) != 0 && names[j].indexOf(lett) != -1)
		    DP[i] += DP[i ^ (1 << j)];
	}
	
	return DP[(1 << n)-1];
    }
}
