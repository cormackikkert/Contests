import java.util.*;

class IncompleteMax {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int k, d;
		k = sc.nextInt();
		d = sc.nextInt();
		int books = 1;
		int tot = k;
		while (tot <= d) {
			k *= 2;
			tot += k;
			++books;
		}
		System.out.println(books-1);
	}
}
