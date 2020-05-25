/*
ID: cormac.1
LANG: JAVA
TASK: pprime
 */

import java.io.*;
import java.util.*;
import java.lang.*;

public class pprimeFAIL {
    public static void main(String[] args) throws IOException {
        BufferedReader fin = new BufferedReader(new FileReader("pprime.in"));
        PrintWriter fout = new PrintWriter(new BufferedWriter(new FileWriter("pprime.out")));

        StringTokenizer s = new StringTokenizer(fin.readLine());

        int A = Integer.parseInt(s.nextToken());
        int B = Integer.parseInt(s.nextToken());

        int length = B / 2 - B / 3 - B / 5 + B / 6 + B / 15 + B / 10 - B / 30 + 1;

        boolean[] isPrime = new boolean[length];
        for (int i = 0; i < length; i++) {
            isPrime[i] = true;
        }

        if (A == 5) fout.println(5);

        for (int p = 7; p <= B; p+=2) {
            if (p % 2 == 0 || p % 3 == 0 || p % 5 == 0) continue;
            if (isPrime[p / 2 - p / 3 - p / 5 + p / 6 + p / 15 + p / 10 - p / 30 - 1]) {
                if (isPalindrome(p) && A <= p)
                    fout.println(p);
                for (int n = p; n <= B; n+=p) {
                    if (n % 2 != 0 && n % 3 != 0 && n % 5 != 0) {
                        isPrime[n / 2 - n / 3 - n / 5 + n / 6 + n / 15 + n / 10 - n / 30 - 1] = false;
                    }
                }
            }
        }

        fout.close();
    }

    public static boolean isPalindrome(int p) {
        short[] digits = new short[10];
        int length = 0;
        while (p > 0) {
            digits[length] = (short) (p % 10);
            p /= 10;
            length++;
        }
        for (int i = 0; i < length / 2 + 1; i++) {
            if (digits[i] != digits[length - 1 - i]) return false;
        }
        return true;
    }
}
