/*
ID: cormac.1
LANG: JAVA
TASK: lamps
 */

import java.io.*;
import java.util.*;
import java.lang.*;

public class lamps {
    static int N;
    public static void main(String[] args) throws IOException {
        BufferedReader fin = new BufferedReader(new FileReader("lamps.in"));
        PrintWriter fout = new PrintWriter(new BufferedWriter(new FileWriter("lamps.out")));

        StringTokenizer s = new StringTokenizer(fin.readLine());
        N = Integer.parseInt(s.nextToken());

        s = new StringTokenizer(fin.readLine());
        int S = Integer.parseInt(s.nextToken());

        boolean[] isOn = new boolean[N];
        s = new StringTokenizer(fin.readLine());
        while (true) {
            int index = Integer.parseInt(s.nextToken());
            if (index == -1) break;
            isOn[index - 1] = true;
        }

        boolean[] isOff = new boolean[N];
        s = new StringTokenizer(fin.readLine());
        while (true) {
            int index = Integer.parseInt(s.nextToken());
            if (index == -1) break;
            isOff[index - 1] = true;
        }

        BitSet curLamps = new BitSet(N);
        for (int i = 0; i < N; i++) curLamps.set(i);

        ArrayList<String> nums = new ArrayList<>();

        boolean found = false;

        for (int a1 = 0; a1 <= 1; a1++) {
            for (int a2 = 0; a2 <= 1; a2++) {
                for (int a3 = 0; a3 <= 1; a3++) {
                    for (int a4 = 0; a4 <= 1; a4++) {
                        if (a1 == 1) apply(1, curLamps);
                        if (a2 == 1) apply(2, curLamps);
                        if (a3 == 1) apply(3, curLamps);
                        if (a4 == 1) apply(4, curLamps);

                        boolean flag = false;
                        for (int i = 0; i < N; i++) {
                            if (isOff[i] && curLamps.get(i))
                                flag = true;
                            if (isOn[i] && !curLamps.get(i))
                                flag = true;
                        }

                        if (!flag && (a1 + a2 + a3 + a4 <= S) && (S - a1 - a2 - a3 - a4) % 2 == 0) {
                            found = true;
                            StringBuilder ans = new StringBuilder();
                            for (int x = 0; x < N; x++) {
                                ans.append(curLamps.get(x) ? "1" : "0");
                            }
                            nums.add(ans.toString());
                        }

                        if (a1 == 1) apply(1, curLamps);
                        if (a2 == 1) apply(2, curLamps);
                        if (a3 == 1) apply(3, curLamps);
                        if (a4 == 1) apply(4, curLamps);
                    }
                }
            }
        }
        Collections.sort(nums);

        if (nums.size() == 0) {
            fout.println("IMPOSSIBLE");
        } else {
            for (String x : nums) {
                fout.println(x);
            }
        }
        fout.close();
    }

    public static void apply(int action, BitSet lamps) {
        switch (action) {
            case 1: lamps.flip(0, N); break;
            case 2: for (int i = 0; i < N; i+=2) lamps.flip(i); break;
            case 3: for (int i = 1; i < N; i+=2) lamps.flip(i); break;
            case 4: for (int i = 0; 3 * i < N; i++) lamps.flip(3 * i); break;
        }
    }
}
