import java.util.*;

class AtomicMax {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		Map<String, Double> atoms = new HashMap<String, Double>();
		for (int i = 0; i < N; ++i) {
			atoms.put(sc.next(), sc.nextDouble());
		}
		String mol = sc.next();
		double ans = 0;
		int i = 0;
		while (i < mol.length()) {
			StringBuilder num = new StringBuilder();
			StringBuilder elem = new StringBuilder();
			elem.append(mol.charAt(i++));
			while (i < mol.length() && !Character.isUpperCase(mol.charAt(i)) && !Character.isDigit(mol.charAt(i))) {
				elem.append(mol.charAt(i++));
			}
			while (i < mol.length() && Character.isDigit(mol.charAt(i))) {
				num.append(mol.charAt(i++));
			}
			if (num.length() == 0) {
				num.append('1');
			}
			ans += atoms.get(elem.toString())*Integer.parseInt(num.toString());
		}
		System.out.println(ans);
	}
}
