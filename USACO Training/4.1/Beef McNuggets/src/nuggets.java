/*
ID: cormac.1
LANG: JAVA
TASK: nuggets
 */

import java.io.*;
import java.util.*;
import java.lang.*;

public class nuggets {
    public static void main(String[] args) throws IOException {
        BufferedReader fin = new BufferedReader(new FileReader("nuggets.in"));
        PrintWriter fout = new PrintWriter(new BufferedWriter(new FileWriter("nuggets.out")));

        int N = Integer.parseInt(fin.readLine());

        ArrayList<Integer> nums = new ArrayList<>();
        for (int i = 0; i < N; ++i) {
            int k = Integer.parseInt(fin.readLine());
            nums.add(k);
        }

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums.size(); ++j) {
                if (i == j) continue;
                if (nums.get(i) % nums.get(j) == 0) nums.remove(i);
            }
        }

        int lowest = Collections.min(nums);
        int[] arr = new int[lowest];
        for (int i = 0; i < lowest; ++i) arr[i] = Integer.MAX_VALUE;
        arr[0] = 0;

        for (int start = 0; start < lowest; ++start) {
            for (int x : nums) {
                int num = arr[start];
                for (int i = 0; i < lowest; ++i) {
                    num += x;
                    if (num < 0) break;
                    if (arr[num % lowest] > num) {
                        arr[num % lowest] = num;
                    }
                }
            }
        }
        int b = 0;
        for (int x : arr) {
            b = Math.max(x, b);
        }
        if (lowest >= b || b > 2000000000)
            fout.println(0);
        else
            fout.println(b - lowest);
        fout.close();
    }
}
