/*
ID: cormac.1
LANG: JAVA
TASK: humble
 */

import java.io.*;
import java.util.*;
import java.lang.*;

public class humble {
    static long[] primes;
    static long[] numbers;

    public static void main(String[] args) throws IOException {
        BufferedReader fin = new BufferedReader(new FileReader("humble.in"));
        PrintWriter fout = new PrintWriter(new BufferedWriter(new FileWriter("humble.out")));

        StringTokenizer s = new StringTokenizer(fin.readLine());

        int K = Integer.parseInt(s.nextToken());
        int N = Integer.parseInt(s.nextToken());

        primes = new long[K];
        numbers = new long[N+1];

        s = new StringTokenizer(fin.readLine());
        for (int i = 0; i < K; i++) {
            primes[i] = Long.parseLong(s.nextToken());
        }

        numbers[0] = 1;

        for (int i = 1; i <= N; ++i) {
            long result = Integer.MAX_VALUE;
            for (long prime : primes) {
                result = Math.min(result, prime * binarySearch(0, i-1, prime, numbers[i-1]));
            }
            numbers[i] = result;
        }
        fout.println(numbers[N]);
        fout.close();
    }

    public static long binarySearch(int lo, int hi, long number, long last) {
        if (lo == hi) return numbers[lo];
        int mid = (lo + hi) / 2;
        if (numbers[mid] * number > last) {
            return binarySearch(lo, mid, number, last);
        } else {
            return binarySearch(mid + 1, hi, number, last);
        }
    }
}
