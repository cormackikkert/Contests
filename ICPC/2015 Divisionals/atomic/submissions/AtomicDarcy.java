import java.util.Scanner;

public class AtomicDarcy {
  public static void main(String[] args) {
    new AtomicDarcy().run();
  }

  void run() {
    Scanner in = new Scanner(System.in);
    int n = in.nextInt();
    String[] elems = new String[n];
    int[] mass = new int[n];

    for(int i=0; i<n; i++) {
      elems[i] = in.next();
      String myMass = in.next();
      for(int j=0; j<myMass.length(); j++)
        if(myMass.charAt(j) != '.')
          mass[i] = 10*mass[i] + (myMass.charAt(j)-'0');

    }
    String compound = in.next();

    int ans = 0;
    for(int i=0; i<compound.length(); i++) {
      String elem = compound.substring(i,i+1);
      if(i+1 < compound.length() && Character.isLowerCase(compound.charAt(i+1))) {
        elem += compound.charAt(i+1);
        i++;
      }
      int num = 0;
      while(i+1 < compound.length() && Character.isDigit(compound.charAt(i+1))) {
        num = 10*num + (compound.charAt(i+1)-'0');
        i++;
      }
      if(num == 0) num = 1;
      for(int j=0; j<n; j++)
        if(elem.equals(elems[j]))
          ans += mass[j] * num;
    }
    System.out.println(ans / 100.0);
  }
}
