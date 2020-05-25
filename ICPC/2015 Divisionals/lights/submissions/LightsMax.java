import java.util.*;

class LightsMax {
	static class Light {
		public int x;
		public int a;
		public int b;
		public int c;
		public Light() {
		}
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int d = sc.nextInt();
		Light[] lights = new Light[n];
		for (int i = 0; i < n; ++i) {
			lights[i] = new Light();
			lights[i].x = sc.nextInt();
			lights[i].a = sc.nextInt();
			lights[i].b = sc.nextInt();
			lights[i].c = sc.nextInt();
		}
		boolean g = true;
		for (int i = 0; i < n; ++i) {
			int len = lights[i].b+lights[i].c;
			int t = lights[i].x-lights[i].a;
			int rem = t%len;
			if (rem > lights[i].b || t < 0) {
				g = false;
				break;
			}
		}
		System.out.println(g ? "YES" : "NO");

	}
}
