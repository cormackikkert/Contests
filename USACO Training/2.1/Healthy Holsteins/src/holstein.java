/*
ID: cormac.1
LANG: JAVA
TASK: holstein
 */

import java.io.*;
import java.util.*;
import java.lang.*;

public class holstein {
    public static void main(String[] args) throws IOException {
        BufferedReader fin = new BufferedReader(new FileReader("holstein.in"));
        PrintWriter fout = new PrintWriter(new BufferedWriter(new FileWriter("holstein.out")));

        StringTokenizer s = new StringTokenizer(fin.readLine());

        int V = Integer.parseInt(s.nextToken());

        int[] minReq = new int[V];
        s = new StringTokenizer(fin.readLine());
        for (int i = 0; i < V; i++) {
            minReq[i] = Integer.parseInt(s.nextToken());
        }

        s = new StringTokenizer(fin.readLine());
        int G = Integer.parseInt(s.nextToken());

        int[][] feeds = new int[G][V];
        for (int i = 0; i < G; i++) {
            s = new StringTokenizer(fin.readLine());
            for (int v = 0; v < V; v++) {
                feeds[i][v] = Integer.parseInt(s.nextToken());
            }
        }

        // Search using BFS
        Queue<int[]> queue = new LinkedList<>();
        queue.add(new int[] {});

        int[] curVitamins;

        while (true) {
            int[] moves = queue.poll();
            curVitamins = new int[V];
            for (int m : moves) {
                for (int v = 0; v < V; v++)
                    curVitamins[v] += feeds[m][v];
            }

            complete : {
                for (int v = 0; v < V; v++)
                    if (curVitamins[v] < minReq[v])
                        break complete;

                fout.print(moves.length);
                for (int move : moves) {
                    fout.print(" ");
                    fout.print(move + 1);
                }
                fout.println();
                break;
            }

            for (int m = 0; m < G; m++) {
                if (moves.length >= 1 && m <= moves[moves.length - 1]) continue;

                int[] newArr = new int[moves.length + 1];
                for (int i = 0; i < moves.length; i++) newArr[i] = moves[i];
                newArr[moves.length] = m;
                queue.add(newArr);
            }
        }
        fout.close();
    }
}
