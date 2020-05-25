import java.util.*;

class CleverMax {
	static char[][] auth;
	static int N;
	static char[] target;
	static int[][] dp;
	static int f(int bs, int i) {
		if (i == N)
			return 1;
		if (dp[bs][i] != -1)
			return dp[bs][i];
		int cnt = 0;
		for (int j = 0; j < N; ++j) {
			if (((~bs)&(1<<j)) == 0)
				continue;
			boolean found = false;
			for (int k = 0; k < auth[j].length; ++k) {
				if (auth[j][k] == target[i])
					found = true;
			}
			if (!found)
				continue;
			cnt += f(bs|(1<<j), i+1);
		}
		return dp[bs][i] = cnt;
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		int K = sc.nextInt();
		auth = new char[N][];
		for (int i = 0; i < N; ++i) {
			String s = sc.next();
			StringBuilder sb = new StringBuilder();
			for (int j = 0; j < s.length(); ++j) {
				if (Character.isUpperCase(s.charAt(j))) {
					sb.append(s.charAt(j));
				}
			}
			char[] ups = sb.toString().toCharArray();
			auth[i] = ups;
		}
		for (int i = 0; i < K; ++i) {
			String tar = sc.next();
			if (tar.length() != N) {
				System.out.println(0);
				continue;
			}
			target = tar.toCharArray();
			dp = new int[1<<N][N];
			for (int j = 0; j < (1<<N); ++j) {
				for (int k = 0; k < N; ++k) {
					dp[j][k] = -1;
				}
			}
			System.out.println(f(0, 0));
		}
	}
}
