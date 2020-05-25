import java.util.Scanner;

public class IncompleteDarcy {
  public static void main(String[] args) {
    new IncompleteDarcy().run();
  }

  void run() {
    Scanner in = new Scanner(System.in);
    int k = in.nextInt();
    int d = in.nextInt();

    int ans = 1;
    while(k*((1 << ans)-1) <= d)
      ans++;

    System.out.println(ans - 1);
  }
}
