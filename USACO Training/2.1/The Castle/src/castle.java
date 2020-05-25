/*
ID: cormac.1
LANG: JAVA
TASK: castle
 */

import java.io.*;
import java.util.*;
import java.lang.*;

public class castle {
    static int M;
    static int N;
    static int[][] gridConnections;
    static int[] components;
    static int curComponent;

    public static void main(String[] args) throws IOException {
        BufferedReader fin = new BufferedReader(new FileReader("castle.in"));
        PrintWriter fout = new PrintWriter(new BufferedWriter(new FileWriter("castle.out")));

        StringTokenizer s = new StringTokenizer(fin.readLine());
        N = Integer.parseInt(s.nextToken());
        M = Integer.parseInt(s.nextToken());

        gridConnections = new int[M][N];
        components = new int[M*N];

        for (int y = 0; y < M; y++) {
            s = new StringTokenizer(fin.readLine());
            for (int x = 0; x < N; x++) {
                gridConnections[y][x] = Integer.parseInt(s.nextToken());
            }
        }

        curComponent = 0;
        for (int y = 0; y < M; y++) {
            for (int x = 0; x < N; x++) {
                if (components[getIndex(x, y)] == 0) {
                    curComponent++;
                    search(x, y);
                }
            }
        }
        int[] componentCount = new int[curComponent];
        for (int comp : components) componentCount[comp-1]++;

        int biggestRoom = 0;
        for (int num : componentCount) biggestRoom = Math.max(biggestRoom, num);

        int[][] MOVE_DELTAS = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
        int maxSoFar = 0;
        int mX = 0, mY = 0;
        String dir = "";

        for (int x = 0; x < N; x++) {
            for (int y = M - 1; y >= 0; y--) {
                for (int[] move : MOVE_DELTAS) {
                    int nx = x + move[0];
                    int ny = y + move[1];
                    if (0 <= ny && ny < M && 0 <= nx && nx < N && (components[getIndex(x, y)] != components[getIndex(nx, ny)])) {
                        if (maxSoFar < componentCount[components[getIndex(x, y)]-1] + componentCount[components[getIndex(nx, ny)]-1]) {
                            maxSoFar = componentCount[components[getIndex(x, y)]-1] + componentCount[components[getIndex(nx, ny)]-1];
                            mX = x + 1;
                            mY = y + 1;
                            if (move.equals(MOVE_DELTAS[0])) {
                                dir = "N";
                            } else if (move.equals(MOVE_DELTAS[1])) {
                                dir = "S";
                            } else if (move.equals(MOVE_DELTAS[2])) {
                                dir = "E";
                            } else if (move.equals(MOVE_DELTAS[3])) {
                                dir = "W";
                            }
                        }
                    }
                }
            }
        }
        fout.println(curComponent);
        fout.println(biggestRoom);
        fout.println(maxSoFar);
        fout.println(mY +" " + mX + " " + dir);
        fout.close();
    }



    public static void search(int x, int y) {
        int index = getIndex(x, y);
        if (components[index] != 0) return;
        components[index] = curComponent;

        int connections = gridConnections[y][x];
        if (connections < 8) {
            search(x, y+1);
        } else connections -= 8;
        if (connections < 4) {
            search(x+1, y);
        } else connections -= 4;
        if (connections < 2) {
            search(x, y-1);
        } else connections -= 2;
        if (connections < 1) {
            search(x - 1, y);
        }
    }

    public static int getIndex(int x, int y) {
        return y * N + x;
    }
}
