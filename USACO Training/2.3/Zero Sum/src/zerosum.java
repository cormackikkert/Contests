/*
ID: cormac.1
LANG: JAVA
TASK: zerosum
 */

import java.io.*;
import java.util.*;
import java.lang.*;

public class zerosum {
    static ArrayList<String> answers = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader fin = new BufferedReader(new FileReader("zerosum.in"));
        PrintWriter fout = new PrintWriter(new BufferedWriter(new FileWriter("zerosum.out")));

        StringTokenizer s = new StringTokenizer(fin.readLine());

        int N = Integer.parseInt(s.nextToken());

        char[] nums = new char[N];
        for (int i = 0; i < N; i++) {
            nums[i] = (char) (i + '1');
        }

        genAnswers("", 1, N);
        Collections.sort(answers);
        for (String x : answers) {
            fout.println(x);
        }
        fout.close();
    }
    public static void genAnswers(String ffs, int cur, int target) {
        if (cur == target) {
            if (eval(ffs + (char) (target + '0')) == 0) {
                answers.add(ffs + (char) (target + '0'));
            }
            return;
        }
        for (char c : " +-".toCharArray()) {
            genAnswers(ffs + (char)(cur + '0') + c, cur+1, target);
        }
    }

    public static int eval(String input) {
        int runningTotal = 0;

        boolean add = true;
        String last = "";

        for (char c : input.toCharArray()) {
            switch (c) {
                case '+': {
                    if (add) {
                        runningTotal += Integer.parseInt(last);
                    } else {
                        runningTotal -= Integer.parseInt(last);
                    }
                    add = true;
                    last = "";
                    break;
                }case '-': {
                    if (add) {
                        runningTotal += Integer.parseInt(last);
                    } else {
                        runningTotal -= Integer.parseInt(last);
                    }
                    add = false;
                    last = "";
                    break;
                }case ' ': {
                    continue;
                }default: {
                    last += c;
                }
            }
        }
        if (add) {
            runningTotal += Integer.parseInt(last);
        } else {
            runningTotal -= Integer.parseInt(last);
        }
        return runningTotal;
    }
}
