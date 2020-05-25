/*
ID: cormac.1
LANG: JAVA
TASK: rockers
 */

import java.io.*;
import java.util.*;
import java.lang.*;
import java.util.stream.IntStream;

public class rockers {
    static int N;
    static int T;
    static int M;

    static int numSongs;
    static int highestCount;

    static int[] SONGS;
    static byte dp[][];

    public static void main(String[] args) throws IOException {
        BufferedReader fin = new BufferedReader(new FileReader("rockers.in"));
        PrintWriter fout = new PrintWriter(new BufferedWriter(new FileWriter("rockers.out")));

        StringTokenizer s = new StringTokenizer(fin.readLine());
        N = Integer.parseInt(s.nextToken());
        T = Integer.parseInt(s.nextToken());
        M = Integer.parseInt(s.nextToken());

        s = new StringTokenizer(fin.readLine());

        SONGS = new int[N];

        for (int i = 0; i < N; ++i) {
            SONGS[i] = Integer.parseInt(s.nextToken());
        }

        int max = 0;
        for (int songs = 0; songs < (1 << N); ++songs) {
            int usedSongs = 0;
            int temp = songs;
            if (isValid(songs)) {
                for (int i = 0; i < N; ++i) {
                    if (temp % 2 == 1) usedSongs++;
                    temp = (temp >> 1);
                }
                max = Math.max(max, usedSongs);
            }
        }
        fout.println(max);
        fout.close();
    }

    public static boolean isValid(int songs) {
        int curCDSize = 0;
        int cdCount = 1;
        for (int i = 0; i < N; ++i) {
            if (songs % 2 == 1) {
                if (curCDSize + SONGS[i] <= T) {
                    curCDSize += SONGS[i];
                } else if (SONGS[i] <= T) {
                    cdCount += 1;
                    curCDSize = SONGS[i];
                } else {
                    return false;
                }
            }
            songs = (songs >> 1);
        }
        return (cdCount <= M);
    }
}
