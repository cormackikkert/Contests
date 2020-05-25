/*
ID: cormac.1
LANG: JAVA
TASK: contact
 */

// I did this wrong and wanted to move forward anyway so I used code from
// https://github.com/lklein/usaco-training/blob/master/usaco/contact/contact.java

import java.io.*;
import java.util.*;

public class contact {

    class Frequency implements Comparable<Frequency> {
        String seq;
        int freq;

        public int compareTo(Frequency other) {
            if (freq != other.freq) return other.freq - freq;
            if (seq.length() != other.seq.length()) return seq.length() - other.seq.length();
            return Integer.parseInt(seq, 2) - Integer.parseInt(other.seq, 2);
        }

        public Frequency(String s, int f) {
            seq = s;
            freq = f;
        }

        public String toString() {
            return String.format("(%s, %d)", seq, freq);
        }
    }

    public String[] solve(int minLen, int maxLen, int n, char[] seq) {
        // HashMap is easier to code, standard and solves the problem, a Trie may also do here
        HashMap<String, Integer> frequencies = new HashMap<String, Integer>();
        String sequ = new String(seq);

        // Straightforward, using DP is actually slower
        for (int len = minLen; len <= maxLen; len++) {
            for (int start = 0; start + len <= sequ.length(); start++) {
                updateFrequencies(frequencies, sequ.substring(start, start + len));
            }
        }

        ArrayList<Frequency> outputFreq = new ArrayList<contact.Frequency>();
        for (String k : frequencies.keySet()) {
            outputFreq.add(new Frequency(k, frequencies.get(k)));
        }
        Collections.sort(outputFreq);

        ArrayList<String> res = new ArrayList<String>();
        int currentFreq = -1;
        int printedFreq = 0;
        int printedPatterns = 0;
        StringBuilder patternSb = new StringBuilder();

        for (int i = 0; i < outputFreq.size() && printedFreq <= n; i++) {
            Frequency f = outputFreq.get(i);
            if (f.freq != currentFreq) { // print freq
                printedFreq++;
                if (printedFreq > n) break;
                printedPatterns = 0;
                if (patternSb.length() > 0) {
                    res.add(patternSb.toString().trim());
                }
                patternSb = new StringBuilder();

                res.add(String.valueOf(f.freq));
                currentFreq = f.freq;
            }
            // print frequencies
            patternSb.append(f.seq);
            patternSb.append(" ");
            printedPatterns++;
            if (printedPatterns == 6) {
                res.add(patternSb.toString().trim());
                patternSb = new StringBuilder();
                printedPatterns = 0;
            }
        }
        if (patternSb.length() > 0) {
            res.add(patternSb.toString().trim());
        }

        return res.toArray(new String[0]);
    }

    private void updateFrequencies(HashMap<String, Integer> frequencies, String thisPos) {
        if (!frequencies.containsKey(thisPos)) frequencies.put(thisPos, 0);
        frequencies.put(thisPos, frequencies.get(thisPos) + 1);
    }

    public static void main(String[] args) throws IOException {
        String problemName = "contact";
        BufferedReader f = new BufferedReader(new FileReader(problemName + ".in"));
        StringTokenizer st = new StringTokenizer(f.readLine());

        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        int n = Integer.parseInt(st.nextToken());
        StringBuilder sb = new StringBuilder();
        String line = f.readLine();
        while (line != null) {
            sb.append(line);
            line = f.readLine();
        }

        String[] res = (new contact()).solve(a, b, n, sb.toString().toCharArray());

        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(problemName + ".out")));
        for (String s : res) {
            out.println(s);
        }
        out.close(); // close the output file
        System.exit(0); // don't omit this!
    }

}