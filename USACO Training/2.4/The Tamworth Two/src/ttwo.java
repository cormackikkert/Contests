/*
ID: cormac.1
TASK: ttwo
LANG: JAVA
 */

import java.io.*;
import java.lang.*;
import java.util.*;

public class ttwo {
    public static void main(String[] args) throws IOException {
        BufferedReader fin = new BufferedReader(new FileReader("ttwo.in"));
        PrintWriter fout = new PrintWriter(new BufferedWriter(new FileWriter("ttwo.out")));

        int johnX = 0;
        int johnY = 0;
        int johnR = 0;

        int cowX = 0;
        int cowY = 0;
        int cowR = 0;

        boolean[][] grid = new boolean[10][10];
        StringTokenizer s;
        for (int i = 0; i < 10; ++i) {
            s = new StringTokenizer(fin.readLine());
            char[] line = s.nextToken().toCharArray();
            for (int j = 0; j < 10; ++j) {
                switch (line[j]) {
                    case 'F': johnX = j; johnY = i; break;
                    case 'C': cowX = j; cowY = i; break;
                    case '*': grid[i][j] = true;
                }
            }
        }

        ArrayList<Integer> johnPositions = new ArrayList<>();
        ArrayList<Integer> cowPositions = new ArrayList<>();

        int jIndex;
        // Simulate john
        while (true) {
            int jcp = getCode(johnX, johnY, johnR);
            if (johnPositions.contains(jcp)) {
                jIndex = johnPositions.indexOf(jcp);
                break;
            }
            johnPositions.add(jcp);

            int newx = 0;
            int newy = 0;
            switch (johnR) {
                case 0: newx = johnX; newy = johnY - 1; break;
                case 1: newx = johnX + 1; newy = johnY; break;
                case 2: newx = johnX; newy = johnY + 1; break;
                case 3: newx = johnX - 1; newy = johnY; break;
            }

            if ((0 <= newx && newx < 10) && (0 <= newy && newy < 10) && !grid[newy][newx]) {
                johnX = newx;
                johnY = newy;
            } else {
                johnR = (johnR + 1) % 4;
            }
        }

        int cIndex;
        // Simulate cow
        while (true) {
            int ccp = getCode(cowX, cowY, cowR);
            if (cowPositions.contains(ccp)) {
                cIndex = cowPositions.indexOf(ccp);
                break;
            }
            cowPositions.add(ccp);

            int newx = 0;
            int newy = 0;
            switch (cowR) {
                case 0: newx = cowX; newy = cowY - 1; break;
                case 1: newx = cowX + 1; newy = cowY; break;
                case 2: newx = cowX; newy = cowY + 1; break;
                case 3: newx = cowX - 1; newy = cowY; break;
            }

            if ((0 <= newx && newx < 10) && (0 <= newy && newy < 10) && !grid[newy][newx]) {
                cowX = newx;
                cowY = newy;
            } else {
                cowR = (cowR + 1) % 4;
            }
        }

        int total = 0;
        int i = 0;
        int j = 0;
        boolean found = false;
        while (true) {
            if (johnPositions.get(i) % 100 == cowPositions.get(j) % 100) {
                found = true;
                break;
            }
            if ((total >= 1000 * 1000) ||(j == cIndex && i == jIndex)) {
                break;
            }
            i += 1;
            if (i == johnPositions.size()) i = jIndex;
            j += 1;
            if (j == cowPositions.size()) j = cIndex;
            total++;
        }

        if (found) fout.println(total);
        else fout.println(0);
        fout.close();
    }

    static int getCode(int x, int y, int r) {
        return r * 100 + x * 10 + y;
    }
}
