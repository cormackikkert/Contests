/*
ID: cormac.1
LANG: JAVA
TASK: sort3
 */

import java.io.*;
import java.util.*;
import java.lang.*;

public class sort3 {
    static int N;
    static int[] nums;
    public static void main(String[] args) throws IOException {
        BufferedReader fin = new BufferedReader(new FileReader("sort3.in"));
        PrintWriter fout = new PrintWriter(new BufferedWriter(new FileWriter("sort3.out")));

        StringTokenizer s = new StringTokenizer(fin.readLine());

        N = Integer.parseInt(s.nextToken());
        nums = new int[N];

        int SS = 0, GS = 0;

        for (int i = 0; i < N; i++) {
            s = new StringTokenizer(fin.readLine());
            nums[i] = Integer.parseInt(s.nextToken()) - 1;
            switch (nums[i]) {
                case 0: SS++;
                case 1: GS++;
            }
        }
        int total = 0;
        while (true) {
            int i = 0;
            while ((i < SS && nums[i] == 0) || (SS <= i && i < GS && nums[i] == 1)) i++;

            if (i == GS) break;

            int j = 0;
            if (nums[i] == 1) {
                j = SS;
                while (j < GS && (nums[j] == 2 || nums[j] != ((i < SS) ? 0 : 2))) j++;
                if (j == GS) {
                    j = SS;
                    while (nums[j] == 1) j++;
                }
            } else if (nums[i] == 2) {
                j = GS;
                while (j < N && (nums[j] == 2 || nums[j] != ((i < SS) ? 0 : 2))) j++;
                if (j == N) {
                    j = GS;
                    while (nums[j] == 2) j++;
                }
            }
            swp(i, j);
            total++;
        }

        fout.println(total);
        fout.close();
    }

    public static void swp(int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}
