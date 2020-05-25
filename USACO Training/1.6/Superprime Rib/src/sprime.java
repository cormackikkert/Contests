/*
ID: cormac.1
LANG: JAVA
TASK: sprime
 */

import java.io.*;
import java.util.*;
import java.lang.*;

public class sprime {
    public static void main(String[] args) throws IOException {
        BufferedReader fin = new BufferedReader(new FileReader("sprime.in"));
        PrintWriter fout = new PrintWriter(new BufferedWriter(new FileWriter("sprime.out")));

        StringTokenizer s = new StringTokenizer(fin.readLine());
        int N = Integer.parseInt(s.nextToken());

        ArrayList<ArrayList<String>> superPrimes = new ArrayList<ArrayList<String>>();

        for (int i = 0; i < N; i++) {
            superPrimes.add(new ArrayList<String>());
        }
        superPrimes.get(0).add("2");
        superPrimes.get(0).add("3");
        superPrimes.get(0).add("5");
        superPrimes.get(0).add("7");

        for (int i = 1; i < N; i++) {
            for (String prevSuperPrime : superPrimes.get(i-1)) {
                for (char x : "123456789".toCharArray()) {
                    int newPrime = Integer.parseInt(prevSuperPrime + x);
                    if (isPrime(newPrime)) superPrimes.get(i).add(prevSuperPrime + x);
                }
            }
        }
        Collections.sort(superPrimes.get(N-1));
        for (String ps : superPrimes.get(N-1)) {
            fout.println(ps);
        }
        fout.close();
    }

    public static boolean isPrime(int n) {
        for (int i = 2; i <= (int) Math.sqrt(n) + 1; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }
}
