/*
ID: cormac.1
LANG: JAVA
TASK: pprime
 */

import java.io.*;
import java.util.*;
import java.lang.*;

public class pprime {
    public static void main(String[] args) throws IOException {
        BufferedReader fin = new BufferedReader(new FileReader("pprime.in"));
        PrintWriter fout = new PrintWriter(new BufferedWriter(new FileWriter("pprime.out")));

        StringTokenizer s = new StringTokenizer(fin.readLine());

        int A = Integer.parseInt(s.nextToken());
        int B = Integer.parseInt(s.nextToken());

        char[] nums;
        char[] palindrome;
        int x;
        boolean END = false;
        for (int length = 0; length < 7; length++) {
            for (int n = (int) Math.pow(10, length / 2); n < (int) Math.pow(10, length / 2 + 1); n++) {
                if (length % 2 == 0) {
                    nums = Integer.toString(n).toCharArray();
                    palindrome = new char[2 * nums.length - 1];
                    for (int i = 0; i < 2 * nums.length - 1; i++) {
                        palindrome[i] = (i >= nums.length) ? nums[2 * nums.length - i - 2] : nums[i];
                    }

                    x = Integer.parseInt(new String(palindrome));
                    if (isPrime(x) && x >= A && x <= B) fout.println(x);
                    if (x >= B) {
                        END = true;
                        break;
                    }
                }
                if (length % 2 == 1) {


                    nums = Integer.toString(n).toCharArray();
                    palindrome = new char[2 * nums.length];
                    for (int i = 0; i < 2 * nums.length; i++) {
                        palindrome[i] = (i >= nums.length) ? nums[2 * nums.length - i - 1] : nums[i];
                    }
                    x = Integer.parseInt(new String(palindrome));
                    if (isPrime(x) && x >= A && x <= B) fout.println(x);
                    if (x >= B) {
                        END = true;
                        break;
                    }
                }
            }
            if (END) break;
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
    public static boolean isPrime(int p) {
        for (int d = 2; d <= (int) Math.sqrt(p) + 1; d++) {
            if (p % d == 0) return false;
        }
        return true;
    }
}
